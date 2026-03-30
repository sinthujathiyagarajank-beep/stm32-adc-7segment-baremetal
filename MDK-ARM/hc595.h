#ifndef HC595_H
#define HC595_H
#include <stdint.h>

extern volatile uint16_t m_final_data[];
void hc595_process(void);
void hc595_tx_data(void);
#endif