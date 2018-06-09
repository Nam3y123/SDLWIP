#include "rect.h"

Rect::Rect(const double x, const double y, const double width, const double height) :
Object(x, y, width, height)
{
	
}


void Rect::draw(SDL_Renderer* const renderer)
{
	SDL_Rect rect;
	rect.w = width_;
	rect.h = height_;
	rect.x = x_;
	rect.y = y_;

	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
	SDL_RenderFillRect(renderer, &rect);
}

void Rect::act()
{
	
}
