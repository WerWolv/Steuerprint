#ifndef __SCREEN_H
#define __SCREEN_H

#include "renderer.h"
#include "layer.h"
#include "widget.h"

class Screen {
	public:
		Screen();
	
		virtual void render(void) = 0;
		virtual void onHardwareButtonPressed(bool btnA, bool btnB, bool btnC) = 0;
		virtual void onHardwareEncoderTurned(int8_t steps) = 0;
		
		static Renderer renderer;
	protected:
		Layer bgLayer;
	
		virtual void drawDefaultBackground(void);
		void addWidget(Widget& widget);
	
	private:
		std::vector<Widget*> m_widgets;

};

#endif
