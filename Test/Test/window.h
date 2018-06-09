#pragma once
#include <string>
#include <SDL.h>
#include <vector>
#include "object.h"

class Window
{
private:
	std::string title_;
	int width_;
	int height_;

	bool closed_{ false };

	SDL_Window* window_{ nullptr };
	SDL_Renderer* renderer_{ nullptr };

	std::vector<std::reference_wrapper<Object>> objects_;

private:
	void init();

public:
	Window(const std::string& title, const int width, const int height);
	~Window();

	bool isClosed() const noexcept;

	void checkEvents();

	void draw() const noexcept;

	void addObject(Object& object);
};