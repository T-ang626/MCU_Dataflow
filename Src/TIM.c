#include "TIM.h"
#include <stdint.h>
extern uint8_t tick_flag;
void TIM2_init(void)
{
    RCC_APB1ENR |= (1U << 0);  
    TIM2_PSC = 7;      
    TIM2_ARR = 999;   
    TIM2_EGR = 1U;
    TIM2_DIER |= (1U << 0);
    TIM2_SR   = 0U;
    TIM2_CR1  = 1U;
    NVIC_ISER0 |= (1U << 28);
}
void TIM2_IRQHandler(void)
{
    if (TIM2_SR & 1U) {
        TIM2_SR &= ~1U;
        tick_flag = 1;
    }
}
