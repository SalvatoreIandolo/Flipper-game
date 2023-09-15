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
		gfx.DrawRect(rect,c);
}

bool Brick::detectBallCollition(Ball& ball)
{
	if (rect.isOverlapping(ball.getRect())) {
		destroyed = true;
		ball.bouncingY();
		return destroyed;
	}
	return false;
}
