#include "led.h"
#include <stdint.h>
#include "FSM.h"
#include "uart.h"
static uint32_t blink_cnt;
extern Keystate_t keystate;
extern Led_state_t led_state;

void led_init(void){
    RCC_APB2ENR |=(1u<<4)|(1u<<2);
    GPIOC_CRH &=~(0XFU<<20);
    GPIOC_CRH |=(0x3u<<20);
    GPIOA_CRL &= ~(0xFU << 0);
    GPIOA_CRL |=  (0x8U << 0);
    GPIOA_ODR |= (1u<<0);

}

void led_off(void){GPIOC_ODR |=(1u<<13);}
void led_on(void){GPIOC_ODR &= ~(1u<<13);}
void led_toggle(void){GPIOC_ODR ^= (1u<<13);}
void led_tick(void){
    switch(led_state){
        case on:
            blink_cnt=0; 
            led_on();
            break;
        case off:
          blink_cnt=0;

            led_off();
            break;
        case blink:
            if(++blink_cnt>250U){
                blink_cnt=0;
                led_toggle();
                }

            break;
        default:
          blink_cnt=0;
        led_off();
        break;

    }
}
void led_execute_cmd(uint8_t choice){
    switch (choice) {
        case 1:
            led_state = on;
            break;
        case 2:
            led_state = off;         
            break;
        case 3:
            led_state = blink;     
            blink_cnt = 0;
            break;
        default:
            break;
    }
}
