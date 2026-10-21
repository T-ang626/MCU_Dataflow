#include <stdint.h>
#include <string.h>
#include "led.h"
#include "uart.h"
#include "FSM.h"
#include "TIM.h"
#include "event.h" 
#include "ringbuffer.h"

volatile uint8_t tick_flag=0;
extern uint8_t pressed;  

int main(void){

    TIM2_init();
    led_init();
    ring_init();
    uart_init();
    const char *msg = "Enter choice\r\n1.led on\r\n2.led off\r\n3.led blink\r\n";
    while (*msg) {
        uart_send(*msg);
        msg++;
    }
    while (1) {
        uart_cmd_tick();
        if (!tick_flag) continue;
        tick_flag = 0;
        uint8_t pressed = (GPIOA_IDR & (1U << 0)) ? 0U : 1U;
        FSM_update(pressed);
        led_tick();
    }       
}
