#include "object.h"

Object::Object(const double x, const double y, const double width, const double height) :
	x_{ x },
	y_{ y },
	width_{ width },
	height_{ height }
{
	
}


double Object::getX() const noexcept
{
	return x_;
}

double Object::getY() const noexcept
{
	return y_;
}

double Object::getWidth() const noexcept
{
	return width_;
}

double Object::getHeight() const noexcept
{
	return height_;
}

void Object::setX(const double& x) noexcept
{
	x_ = x;
}

void Object::setY(const double& y) noexcept
{
	y_ = y;
}

void Object::setWidth(const double& width) noexcept
{
	width_ = width;
}

void Object::setHeight(const double& height) noexcept
{
	height_ = height;
}