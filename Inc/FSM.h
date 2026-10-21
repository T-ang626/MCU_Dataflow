#ifndef FSM_H
#define FSM_H
#include <stdint.h>
typedef enum{
    ST_IDLE,
    ST_DEBOUNCE,
    ST_PRESSED,
    ST_LONG,
    ST_WAIT,
}Keystate_t;
typedef enum{    
    on,
    off,
    blink,
}Led_state_t;  
void FSM_update(uint8_t pressed);
void FSM_LED(void);

#endif
