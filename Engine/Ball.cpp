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

void Ball::update(float dt)
{
	pos += vel * dt;
}

bool Ball::detectWallCollition(const Rect& wall)
{
	bool collision = false;
	const Rect temp = getRect();

	if (temp.x0 < wall.x0) {
		pos.x += wall.x0 - temp.x0; // aggiungo un offset pari allo spazio che sono uscito dal muro
		bouncingX();
		collision = true;
	}
	else if (temp.x1 > wall.x1) {
		pos.x -= temp.x1 - wall.x1;
		bouncingX();
		collision = true;
	}

	if (temp.y0 < wall.y0) {
		pos.y += wall.y0 - temp.y0;
		bouncingY();
		collision = true;
	}
	else if (temp.y1 > wall.y1) {
		pos.y -= temp.y1 - wall.y1;
		bouncingY();
		collision = true;
	}
	return collision;
}

void Ball::bouncingX()
{
	vel.x = -vel.x;
}

void Ball::bouncingY()
{
	vel.y = -vel.y;
}

Rect Ball::getRect() const
{
	return Rect::fromCenter(pos,radius,radius);
}

Vec2 Ball::getPos() const
{
	return pos;
}
