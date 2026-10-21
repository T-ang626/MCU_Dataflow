#include "FSM.h"
#include "LED.h"
#include "uart.h"
static uint32_t cnt=0;
Keystate_t keystate=ST_IDLE;
Led_state_t led_state=off;
void FSM_update(uint8_t pressed){
    switch(keystate){
    case ST_IDLE:
    if(pressed){ keystate=ST_DEBOUNCE;}
    break;
    case ST_DEBOUNCE:
    if(!pressed) {keystate=ST_IDLE;}
    else if(++cnt>=20u){
    keystate=ST_PRESSED;  
    cnt=0;
    }
    break;
    case ST_PRESSED:
    if(!pressed){
        if(led_state==on){
        led_state=blink;
        uart_send_string("Led blink \r\n");
        cnt=0;
        }
        else if(led_state==blink){ 
        led_state=off;
        uart_send_string("Led off \r\n");
        cnt=0;

        }
        else{//state==off)
        led_state=on;
        uart_send_string("Led on \r\n");
        cnt=0;
        }
        keystate=ST_WAIT;

    }
    else if(++cnt>2000U){
        cnt=0;
        keystate=ST_LONG;
        uart_send_string("Long press\r\nLed Off \r\n");
        led_state = off;
    }
    break;
    case ST_LONG:
    if(!pressed){      
        cnt=0;
        keystate=ST_WAIT;
    }
    break;
    case ST_WAIT:
    if(!pressed){
        if(++cnt>=20U)
        {
            keystate=ST_IDLE;
            cnt=0;
        }
    }
    else{
        cnt=0;
        keystate=ST_DEBOUNCE;
    break;   
}
}
}