#include "window.h"
#include <iostream>

Window::Window(const std::string& title, const int width, const int height) :
	title_{ title },
	width_{ width },
	height_{ height }
{
	init();
}

Window::~Window()
{
	SDL_DestroyRenderer(renderer_);
	SDL_DestroyWindow(window_);
	SDL_Quit();
}

void Window::init()
{
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		throw std::exception("Failed to initialize SDL");
	}

	window_ = SDL_CreateWindow(title_.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width_, height_, 0);
	if (window_ == nullptr)
	{
		throw std::exception("Failed to create window");
	}

	renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_PRESENTVSYNC);
	if (window_ == nullptr)
	{
		throw std::exception("Failed to create renderer");
	}
}

bool Window::isClosed() const noexcept
{
	return closed_;
}

void Window::checkEvents()
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
		{
			closed_ = true;
		}
		break;

		case SDL_KEYDOWN:
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				closed_ = true;
			}
		}
		break;

		default:
			break;
		}
	}
}

void Window::draw() const noexcept
{
	SDL_SetRenderDrawColor(renderer_, 0, 0, 255, 255);
	SDL_RenderClear(renderer_);

	for (const auto object : objects_)
	{
		object.get().draw(renderer_);
	}

	SDL_RenderPresent(renderer_);
}

void Window::addObject(Object& object)
{
	objects_.emplace_back(object);
}

