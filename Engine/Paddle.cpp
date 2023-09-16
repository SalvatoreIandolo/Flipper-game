#include "Paddle.h"



Paddle::Paddle(Vec2 in_pos, float in_vel, float in_halfWidth, float in_halfHeight, Color in_c)
	:
	pos(in_pos),
	halfWidth(in_halfWidth),
	halfHeigh(in_halfHeight),
	speed(in_vel),
	c(in_c)
{
	
	
}

void Paddle::draw(Graphics& gfx)
{
	Rect rect = Rect::fromCenter(pos, halfWidth, halfHeigh);
	gfx.DrawRect(rect,c);
}

void Paddle::update(Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_LEFT)) {
		pos.x -= speed * dt;
		pos.x -= speed * dt;
	}

	if (kbd.KeyIsPressed(VK_RIGHT)) {
		pos.x += speed * dt;
		pos.x += speed * dt;
	}
}

void Paddle::detectWallCollition(Rect& wall)
{
	Rect temp = getRect();

	if (temp.x0 < wall.x0) {
		pos.x += wall.x0 - temp.x0;
	}

	if (temp.x1 > wall.x1) {
		pos.x -=  temp.x1 - wall.x1;
	}
	
}

bool Paddle::detectBallCollition(Ball& ball)
{
	if (getRect().isOverlapping(ball.getRect())) {
		ball.bouncingY();
		return true;
	}
	return false;
}

Rect Paddle::getRect() const
{
	return Rect::fromCenter(pos, halfWidth, halfHeigh);
}
