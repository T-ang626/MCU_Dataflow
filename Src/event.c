#include <stdint.h>
#include "event.h"
#include "led.h"
#include "uart.h"
#include "ringbuffer.h"
void uart_cmd_tick(void){
    uint8_t receive_data;
    while (RB_read(&receive_data) == 1) {
        if (receive_data=='\r' || receive_data=='\n') {
            continue;
        }
        if (receive_data>='1'&&receive_data<= '3') {
            led_execute_cmd((uint8_t)(receive_data - '0'));
            if(receive_data=='1'){
                uart_send_string("LED ON \r\n");
            }
            if(receive_data=='2'){
                uart_send_string("LED OFF \r\n");
            }    
            if(receive_data=='3'){
                uart_send_string("LED BLINK \r\n");
            }    
            uart_send_string("Command executed\r\n");
        } 
        else {
            uart_send_string("Invalid command\r\n");
        }
    }
}
    