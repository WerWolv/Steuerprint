#include "renderer.h"

Renderer::Renderer() {
	Renderer::m_layers = std::vector<Layer*>();
	this->clearLayers();
}


void Renderer::swapBuffers(void) {
	for(uint8_t l = 0; l < m_layers.size(); l++)
		for(uint8_t i = 0; i < SCREEN_WIDTH; i++)
			for(uint8_t j = 0; j < SCREEN_HEIGHT; j++)
				this->m_buffer.pixels[i][j] |= m_layers.at(l)->getBitmap().pixels[i][j];
	
	sendBuffer(this->m_buffer.pixels);
				
	this->clearLayers();
}

Renderer& Renderer::operator<<(Layer &layer) {
	if(!layer.isOnScreen())
		m_layers.push_back(&layer);
	
	return *this;
}

void Renderer::clearLayers(void) {
	for(uint8_t layer = 0; layer < m_layers.size(); layer++)
		m_layers.at(layer)->cleanScreen();
	
	for(uint8_t x = 0; x < SCREEN_WIDTH; x++)
		for(uint8_t y = 0; y < SCREEN_HEIGHT; y++)
			this->m_buffer.pixels[x][y] = false;
	
	m_layers.clear();
}
