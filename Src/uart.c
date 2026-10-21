#include <stdint.h>
#include "uart.h"
#include "ringbuffer.h"

void uart_init(void){
    RCC_APB2ENR |=(1u<<2)|(1u<<14);
    GPIOA_CRH &=~(0XFU<<4);
    GPIOA_CRH |= (0XBU<<4);
    GPIOA_CRH &=~(0XFU<<8);
    GPIOA_CRH |=(0X4U<<8);
    USART1_BRR=0X341;
    USART1_CR1 |= (1U << 13) | (1U << 3) | (1U << 2) | (1U << 5);
    NVIC_ISER1 |= (1U << 5);
}

void uart_send(uint8_t data){
    while (!(USART1_SR & (1U << 7)));
    USART1_DR = data;
}

void USART1_IRQHandler(void) {
    if (USART1_SR & (1U << 5)) {
        uint8_t rx_data = (uint8_t)USART1_DR;
        (void)RB_write(rx_data);
    }
}

void uart_send_string(const char *str) {
    while (*str) {
        uart_send((uint8_t)*str++);
    }
}
