#pragma once
#include "object.h"

class Rect : public Object
{
private:
	uint8_t color_{ 0 };

public:
	Rect(const double x, const double y, const double width, const double height);

	void draw(SDL_Renderer* const renderer) override;
	void act() override;
};