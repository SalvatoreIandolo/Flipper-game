#pragma once

#include "Vec2.h"


class Rect {
public:
	Rect() = default;
	Rect(float in_x0, float in_y0, float in_x1, float in_y1);
	Rect(Vec2& topLeft, Vec2& bottomRight);
	Rect(Vec2& topLeft, float width, float height);
	bool isOverlapping(Rect& other_rect);
	static Rect fromCenter(const Vec2& center, float halfWidth, float halfHeight);
	
public:
	float x0;
	float x1;
	float y0;
	float y1;
};