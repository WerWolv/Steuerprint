#ifndef __OS_H
#define __OS_H

#include "stm32f4xx_hal.h"

class OS {
	public:
		bool running;
		static float targetU, actualU, targetI, actualI;

		OS();
	
		void onInit(void);
		void mainEntry(void);
		void onShutdown(void);
		void onErrorOccured(uint8_t errorCode);
};

#endif
