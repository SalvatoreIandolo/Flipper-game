#include "Vec2.h"
#include <cmath>

Vec2::Vec2(float x_in, float y_in)
	:
	x(x_in),
	y(y_in)
{
}

Vec2 Vec2::operator+(const Vec2& rhs) const
{
	return Vec2(x + rhs.x, y + rhs.y);
}

Vec2& Vec2::operator+=(const Vec2& rhs)
{
	return *this = *this + rhs; // return a reference to the current obj on which we are operating
}

Vec2 Vec2::operator*(float rhs) const
{
	return Vec2(x * rhs, y * rhs);
}

Vec2& Vec2::operator*=(float rhs)
{
	return *this = *this * rhs;
}

Vec2 Vec2::operator-(const Vec2& rhs) const
{
	return Vec2(x - rhs.x, y - rhs.y);
}

Vec2& Vec2::operator-=(const Vec2& rhs)
{
	return *this = *this - rhs;
}

float Vec2::getLenght() const
{
	return std::sqrt(getLenghtSq());
}

float Vec2::getLenghtSq() const
{
	return x * x + y * y;
}

Vec2& Vec2::normalize()
{
	return *this = getNormalize();
}

Vec2 Vec2::getNormalize() const
{
	const float len = getLenght();
	if (len != 0.0f)
		return *this * (1.0f / len);
	return *this;
}
