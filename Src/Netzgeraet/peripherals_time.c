#include "peripherals.h"

void initUsDelay(void) {
	CoreDebug->DEMCR &= ~CoreDebug_DEMCR_TRCENA_Msk;
	CoreDebug->DEMCR |=  CoreDebug_DEMCR_TRCENA_Msk;
     
	DWT->CTRL &= ~DWT_CTRL_CYCCNTENA_Msk;
	DWT->CTRL |=  DWT_CTRL_CYCCNTENA_Msk;
	DWT->CYCCNT = 0;
  
	__ASM volatile ("NOP");
    __ASM volatile ("NOP");
	__ASM volatile ("NOP");
}

__INLINE void delayUs(volatile uint32_t us) {
  uint32_t clkCycleStart = DWT->CYCCNT;
  us *= (HAL_RCC_GetHCLKFreq() / 1E6);

	while ((DWT->CYCCNT - clkCycleStart) < us);
}
