#include <iostream>
#include <cassert>
#include "../enum.h"

DECLARE_ENUM(Color, int, Red, Green, Blue);

int main()
{
	Color color = Color::Red;
	assert(color == Color::Red);
	color = Color::Blue;
	assert(color == Color::Blue);
	assert(color =! Color::Red);
	assert(Color::Red == Color::Red);
	assert(Color::Red != Color::Green);
	assert(Color::Red   == 0);
	assert(Color::Green == 1);
	assert(Color::Blue  == 2);
	assert(Color::count() == 3);
	assert(Color::value(0) == Color::Red);
	assert(Color::value(1) == Color::Green);
	assert(Color::value(2) == Color::Blue);
	assert(color.isValid());
	color = 100;
	assert(!color.isValid());
	assert( Color::isValid(Color::Red));
	assert(!Color::isValid(100));

	return 0;
}
