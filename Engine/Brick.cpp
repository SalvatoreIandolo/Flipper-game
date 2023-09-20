#include "Brick.h"

Brick::Brick(Rect& in_rect, Color in_c)
	:
	rect(in_rect),
	c(in_c)
{

}

void Brick::draw(Graphics& gfx) const
{
	if(!destroyed)
		gfx.DrawRect(rect.getWithOffset(padding), c);
}

bool Brick::checkBallCollition(Ball& ball)
{
	return !destroyed && rect.isOverlapping(ball.getRect());
}

void Brick::doBallCollition(Ball& ball)
{
	Vec2 ballPos = ball.getPos();

	if (ballPos.x >= rect.x0 && ballPos.y <= rect.x1) {
		ball.bouncingY();
	}
	else {
		ball.bouncingX();
	}
	destroyed = true;

}
