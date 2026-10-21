#ifndef led_H
#define led_H
#include <stdint.h>
#define RCC_APB2ENR (*(volatile uint32_t*)0x40021018) 
#define GPIOC_ODR (*(volatile uint32_t*)0x4001100C)
#define GPIOC_IDR (*(volatile uint32_t*)0x40011008)
#define GPIOC_CRH (*(volatile uint32_t*)0x40011004)
#define GPIOA_ODR (*(volatile uint32_t*)0x4001080C)
#define GPIOA_IDR (*(volatile uint32_t*)0x40010808)
#define GPIOA_CRL (*(volatile uint32_t*)0x40010800)
void led_init(void);
void led_on(void);
void led_off(void);
void led_toggle(void);  
void led_tick(void);
void led_execute_cmd(uint8_t cmd);

#endif
