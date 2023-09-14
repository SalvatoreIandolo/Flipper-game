#pragma once
#include "Graphics.h"
#include "Vec2.h"


class Ball {
public:
	Ball() = default;
	Ball(const Vec2& in_pos, const Vec2& in_vel);
	void draw(Graphics& gfx);

public:
	Vec2 pos;
	Vec2 vel;
	static constexpr float radius = 7.0f;
};