#include "Rect.h"

Rect::Rect(float in_x0, float in_y0, float in_x1, float in_y1)
	:
	x0(in_x0),
	x1(in_x1),
	y0(in_y0),
	y1(in_y1)
{
	
}

Rect::Rect(Vec2& topLeft, Vec2& bottomRight)
{
	Rect(topLeft.x, topLeft.y, bottomRight.x, bottomRight.y);
}

Rect::Rect(Vec2& topLeft, float width, float height)
{
	Rect(topLeft, Vec2(topLeft.x + width, topLeft.y + height));
}

bool Rect::isOverlapping(Rect& other_rect)
{
	return x1 >= other_rect.x0 && x0 <other_rect.x1
		&& y1 >= other_rect.y0 && y0 < other_rect.y1;
}

Rect Rect::fromCenter(const Vec2& center, float halfWidth, float halfHeight)
{
	Rect temp(center.x - halfWidth, center.y - halfHeight, center.x + halfWidth, center.y + halfHeight);
	return temp;
}

Rect Rect::getWithOffset(float offset) const
{
	return Rect(x0 + offset, y0 + offset, x1 - offset, y1 - offset);
}

Vec2 Rect::getCenter() const
{
	return Vec2(x0 + (x1 / 2.0f), y0 +(y1 / 2.0f));
}


/*
Rect::Rect(Vec2& center, float halfWidth, float halfHeight)
{
	//Rect( Vec2(center.x - halfWidth, center.y - halfHeight), Vec2(center.x + halfWidth, center.y + halfHeight) );
}
*/