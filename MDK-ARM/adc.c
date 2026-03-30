 #include <stdint.h>
 #include "stm32g070xx.h"
 #include "adc.h"
 
 
 void adc_init(void)
 {
	 uint16_t data;
	 RCC->IOPENR |= RCC_IOPENR_GPIOAEN;
	 RCC->APBENR2|= RCC_APBENR2_ADCEN;
	 
	 GPIOA->MODER &= ~GPIO_MODER_MODE0_Msk;
	 GPIOA->MODER |= GPIO_MODER_MODE0_Msk;
	 
	 if (ADC1->CR & ADC_CR_ADEN)
    {
        ADC1->CR |= ADC_CR_ADDIS;
        while (ADC1->CR & ADC_CR_ADEN);
    }
		
	 ADC1->CR |= ADC_CR_ADVREGEN;
	 for (volatile int i = 0; i < 100; i++);
		
		ADC1->CR |= ADC_CR_ADCAL;
    while (ADC1->CR & ADC_CR_ADCAL);
		
	 ADC1->CFGR1 |= ADC_CFGR1_CONT;
		ADC1->SMPR |= ADC_SMPR_SMP1;  
    ADC1->CHSELR |= ADC_CHSELR_CHSEL0;
		
		ADC1->ISR |= ADC_ISR_ADRDY | ADC_ISR_EOC | ADC_ISR_EOS | ADC_ISR_OVR;
		
	 ADC1->CR |= ADC_CR_ADEN;
	 while(!(ADC1->ISR & ADC_ISR_ADRDY));
	 ADC1->CR |= ADC_CR_ADSTART;
 }
 
 uint16_t adc_read(void)
{
    while (!(ADC1->ISR & ADC_ISR_EOC));
    return ADC1->DR;
}

float adc_volt(void)
{
	volatile uint16_t data;
	data = adc_read();
	float volt_data;
	volt_data =(data* 3.3f)/4095.0f;
	return volt_data;
}

uint16_t float_to_int(void)
{
	volatile float data;
	data = adc_volt();
	uint16_t temp = (int)(data * 1000);
	return temp;
}
	

