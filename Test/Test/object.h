#pragma once
#include <SDL.h>

class Object
{
private:
	

protected:
	double x_{ 0 };
	double y_{ 0 };
	double width_{ 0 };
	double height_{ 0 };

public:
	double getX() const noexcept;
	double getY() const noexcept;
	double getWidth() const noexcept;
	double getHeight() const noexcept;

	void setX(const double& x) noexcept;
	void setY(const double& y) noexcept;
	void setWidth(const double& width) noexcept;
	void setHeight(const double& height) noexcept;

	Object(const double x, const double y, const double width, const double height);

	virtual void draw(SDL_Renderer* const renderer) = 0;
	virtual void act() = 0;

	virtual ~Object() = default;
};