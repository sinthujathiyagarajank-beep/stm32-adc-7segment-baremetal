#ifndef SEVEN_SEGMENT_H
#define SEVEN_SEGMENT_H
#include <stdint.h>

extern const uint8_t m_segment_char[];
extern uint16_t m_display_data[];
extern uint16_t m_data[];

void seven_segment_display(uint16_t display_value);
void seven_segment_process(void);
void seven_segment_init(void);
#endif 