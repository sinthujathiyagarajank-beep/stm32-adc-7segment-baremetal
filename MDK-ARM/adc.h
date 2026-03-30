#ifndef ADC_H
#define ADC_H
#include<stdint.h>

void adc_init(void);
 uint16_t adc_read(void);
 float adc_volt(void);
 uint16_t float_to_int(void);
#endif