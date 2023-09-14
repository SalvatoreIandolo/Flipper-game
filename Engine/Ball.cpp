#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(const Vec2& in_pos, const Vec2& in_vel)
	:
	pos(in_pos),
	vel(in_vel)

{
}

void Ball::draw(Graphics& gfx)
{
	SpriteCodex::DrawBall(pos, gfx);
}
