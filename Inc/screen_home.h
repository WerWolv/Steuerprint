#ifndef __SCREEN_TEST_H
#define __SCREEN_TEST_H

#include "screen.h"

class OS;

class ScreenHome : public Screen {
	public:
		ScreenHome();

		virtual void render(void);	
		virtual void onHardwareButtonPressed(bool btnA, bool btnB, bool btnC);
		virtual void onHardwareEncoderTurned(int8_t steps);
	
		
	
	private:
		float m_voltage, m_current, m_temparature;
};

#endif
