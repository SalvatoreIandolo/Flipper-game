#include "Paddle.h"

Paddle::Paddle(Rect& in_paddle, Color in_c)
	:
	paddle(in_paddle),
	c(in_c)
{
}

void Paddle::draw(Graphics& gfx)
{
	gfx.DrawRect(paddle, c);
}

void Paddle::update(Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_LEFT)) {
		paddle.x0 -= speed * dt;
		paddle.x1 -= speed * dt;
	}

	if (kbd.KeyIsPressed(VK_RIGHT)) {
		paddle.x0 += speed * dt;
		paddle.x1 += speed * dt;
	}
}

void Paddle::detectWallCollition(Rect& wall)
{
	if (paddle.x0 < wall.x0) {
		paddle.x0 = 0;
	}
	else if (paddle.x1 > wall.x1) {
		paddle.x1 = 0;
	}
	
}

bool Paddle::detectBallCollition(Ball& ball)
{
	if (paddle.isOverlapping(ball.getRect())) {
		ball.bouncingY();
		return true;
	}
	return false;
}
