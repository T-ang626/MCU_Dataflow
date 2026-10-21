#ifndef TIM_H
#define TIM_H
#include <stdint.h>
#define RCC_APB1ENR (*(volatile uint32_t*)0x4002101C)
#define TIM2_PSC    (*(volatile uint32_t*)0x40000028)
#define TIM2_ARR    (*(volatile uint32_t*)0x4000002C)
#define TIM2_DIER   (*(volatile uint32_t*)0x4000000C)
#define TIM2_SR     (*(volatile uint32_t*)0x40000010)
#define TIM2_CR1    (*(volatile uint32_t*)0x40000000)
#define TIM2_EGR    (*(volatile uint32_t*)0x40000014)
#define NVIC_ISER0  (*(volatile uint32_t*)0xE000E100)
#define RCC_CR      (*(volatile uint32_t*)0x40021000)
void TIM2_init(void);
void TIM2_IRQHandler(void);
void SYSCLK_init(void);
#endif
