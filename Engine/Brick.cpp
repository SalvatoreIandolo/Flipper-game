#include "Brick.h"

Brick::Brick(Rect& in_rect, Color in_c)
	:
	rect(in_rect),
	c(in_c)
{

}

void Brick::draw(Graphics& gfx) const
{
	gfx.DrawRect(rect,c);
}
