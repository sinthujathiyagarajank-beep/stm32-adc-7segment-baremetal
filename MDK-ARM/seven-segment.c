#include "seven-segment.h"
#include <stdint.h>


uint16_t m_display_data[4] = 
{  
};

uint16_t m_data[4]={};
const uint8_t m_segment_char[] =
{
	0x08, //display 3
	0x04, //display 2
	0x02, //display 1
	0x01  //display 0
};

void
seven_segment_init(void)
{
	
}

void
seven_segment_process(void)
{
	uint16_t i;
	for(i=0;i<4;i++)
	{
	switch (m_display_data[i])
	{
		case 1:
			  m_data[i]=0xF900;
		    break;
		case 2:
			  m_data[i] =0xA400;
		    break;
		case 3:
			  m_data[i]=0xB000;
		    break;
		case 4:
			  m_data[i]=0x9900;
		    break;
		case 5:
			  m_data[i]=0x9200;
		    break;
		case 6:
			  m_data[i]=0x8200;
		    break;
		case 7:
			 m_data[i]=0xF800;
		    break;
		case 8:
			 m_data[i]=0x8000;
		    break;
		case 9:
			 m_data[i]=0x9000;
		    break;
		default:
			 m_data[i]=0xC000;   //for 0
		    break;
	}
	}
	m_data[3]-=0x8000;
}

void
seven_segment_display(uint16_t display_value)
{
	 uint16_t i,temp_var;
	 for(i=0;i<4;i++)
	{
		temp_var = display_value%10;
		m_display_data[i] =temp_var;
		display_value /= 10;
	}
}
