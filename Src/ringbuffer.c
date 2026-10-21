#include <stdint.h>
#include "ringbuffer.h"

#define RING_BUFFER_MASK 255U
static ring_t ring;
void ring_init(void) {
   ring.head = 0;
   ring.tail = 0;
}
int RB_write(uint8_t val) {
   uint16_t next = (ring.head + 1U) & RING_BUFFER_MASK;
   if (next == ring.tail) return 0;
   ring.buf[ring.head] = val;
   ring.head = next;
   return 1;
}
int RB_read(uint8_t *v) {
    int ret = 0;         
    __disable_irq();    
    if (ring.head != ring.tail) { 
        *v = ring.buf[ring.tail];
        ring.tail = (ring.tail + 1U) & RING_BUFFER_MASK;
        ret = 1;      
    }   
    __enable_irq();      
    return ret;      
}
