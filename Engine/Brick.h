#pragma once
#include "Rect.h"
#include "Colors.h"
#include "Graphics.h"
#include "Ball.h"

class Brick {
public:
	Brick() = default;
	Brick(Rect& in_rect, Color in_c);
	void draw(Graphics& gfx) const;
	bool checkBallCollition(Ball& ball);
	void doBallCollition(Ball& ball);
	

public:
	static constexpr float padding = 1.0f;
	Rect rect;
	Color c;
	bool destroyed = false;

};