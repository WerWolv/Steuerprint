#ifndef _WIDGET_PROGRESS_H
#define _WIDGET_PROGRESS_H

#include "widget.h"

class WidgetProgress : public Widget {
	WidgetProgress(uint8_t x, uint8_t y, uint8_t width, uint8_t height, int8_t tabIndex);

	virtual void render();

	virtual void onClicked();
	virtual void onScroll(int8_t steps);
	virtual void onSelected();
	virtual void onUnselected();
};

#endif
