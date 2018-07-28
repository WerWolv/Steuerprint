#ifndef _WIDGET_H
#define _WIDGET_H

extern "C" {
	#include "stm32f4xx_hal.h"
}

#include "layer.h"

class Widget {
public:
	Widget(uint8_t x, uint8_t y, uint8_t width, uint8_t height, int8_t tabIndex);
	~Widget();

	virtual void render() = 0;
	virtual void renderSelected();

	virtual void onClicked() = 0;
	virtual void onScroll(int8_t steps) = 0;
	virtual void onSelected() = 0;
	virtual void onUnselected() = 0;

	void select();
	void unselect();

	static Layer widgetLayer;

protected:
	int8_t m_tabIndex;
	uint8_t m_x, m_y, m_width, m_height;
	bool m_selected;
};

#endif
