#ifndef uart_H
#define uart_H
#include <stdint.h>
#define RCC_APB2ENR (*(volatile uint32_t*)0x40021018) 
#define USART1_SR   (*(volatile uint32_t *)0x40013800)
#define USART1_DR   (*(volatile uint32_t *)0x40013804)
#define USART1_BRR  (*(volatile uint32_t *)0x40013808)
#define USART1_CR1  (*(volatile uint32_t *)0x4001380C)
#define NVIC_ISER1  (*(volatile uint32_t *)0xE000E104)
#define GPIOA_CRH   (*(volatile uint32_t *)0x40010804)
void uart_init(void);
void uart_send(uint8_t data);
void USART1_IRQHandler(void); 
void uart_send_string(const char *str);
#endif
