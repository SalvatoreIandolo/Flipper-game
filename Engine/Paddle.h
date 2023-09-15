#pragma once
#include "Keyboard.h"
#include "Ball.h"


class Paddle {
public:
	Paddle() = default;
	Paddle(Rect& in_paddle, Color in_c);
	void draw(Graphics& gfx);
	void update(Keyboard& kbd, float dt);
	void detectWallCollition(Rect& wall);
	bool detectBallCollition(Ball& ball);
public:
	Rect paddle;
	Color c;
	float speed = 300.0f;

};