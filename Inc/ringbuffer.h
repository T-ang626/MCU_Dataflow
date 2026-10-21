#ifndef ringbuffer_H
#define ringbuffer_H
#include <stdint.h>
#define __disable_irq() __asm volatile ("cpsid i" : : : "memory")
#define __enable_irq()  __asm volatile ("cpsie i" : : : "memory")
typedef struct {
    uint8_t buf[256];
    volatile uint16_t head;
    volatile uint16_t tail;
} ring_t;

void ring_init(void);
int RB_write(uint8_t val);
int RB_read(uint8_t *v);


#endif
