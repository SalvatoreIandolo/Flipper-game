#pragma once
#include "Keyboard.h"
#include "Ball.h"


class Paddle {
public:
	Paddle() = default;
	Paddle(Vec2 in_pos, float in_vel,float in_halfWidth, float in_halfHeight, Color in_c);
	void draw(Graphics& gfx);
	void update(Keyboard& kbd, float dt);
	void detectWallCollition(Rect& wall);
	bool detectBallCollition(Ball& ball);
	Rect getRect() const;
public:
	Vec2 pos;
	float halfHeigh;
	float halfWidth;
	Color c;
	float speed;

};