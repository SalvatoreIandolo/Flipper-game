#pragma once
#include "Rect.h"
#include "Colors.h"
#include "Graphics.h"


class Brick {
public:
	Brick() = default;
	Brick(Rect& in_rect, Color in_c);
	void draw(Graphics& gfx) const;

public:
	Rect rect;
	Color c;
	bool destroyed = false;
};