#include <stdint.h>
#include "stm32g070xx.h"
#include "seven-segment.h"
#include "hc595.h"

volatile uint16_t m_final_data[4]={};
void
hc595_init(void)
{
	//init clock and port registers
}

void
hc595_process(void)
{
	uint16_t i,j;
	hc595_tx_data();
	for(j=0;j<4;j++)
		{
			GPIOB->ODR&= ~GPIO_ODR_OD5;   //LATCH LOW
			for(i=0;i<32;i++)
			{
				if(i%2)
				{
					GPIOA->ODR = (1<<8);
				}
				else
				{
					GPIOA->ODR = ((0<<8)|((m_final_data[j]<< i/2 ) & 0x8000) >> 6);
				}
			} 
			GPIOB->ODR|= GPIO_ODR_OD5;  //latch high 
		}
}

void
hc595_tx_data(void)
{
	uint8_t i;
	  seven_segment_process();
	   for(i=0;i<4;i++)
	{
		m_final_data[i] = (m_data[i]|m_segment_char[i]);
	}
}        