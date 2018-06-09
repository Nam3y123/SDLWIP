#include "window.h"
#include "rect.h"

int main(int argc, char * argv[])
{
	Window window{"SDL Window", 800, 600 };
	Rect rect1{ 0, 0, 120, 120 };
	window.addObject(rect1);
	Rect rect2{ 120, 120, 25, 25 };
	window.addObject(rect1);
	window.addObject(rect2);
	window.draw();

	while (!window.isClosed())
	{
		window.checkEvents();
	}

	return 0;
}