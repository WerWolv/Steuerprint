#ifndef __RENDERER_H
#define __RENDERER_H

extern "C" {
	#include "display.h"
}

#include <vector>

#include "layer.h"

#define MAX_LAYERS 16

class Renderer {	
	public:
		Renderer();
		
		void swapBuffers(void);
		Renderer& operator<<(Layer &layer);

	private:
		Bitmap m_buffer;
		std::vector<Layer*> m_layers;
	
		void clearLayers(void);
};

#endif
