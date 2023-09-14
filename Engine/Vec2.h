#pragma once

class Vec2 {
public:
	Vec2() = default;
	Vec2(float x_in, float y_in);
	Vec2 operator+(const Vec2& rhs) const; // lhs + rhs
	Vec2& operator+=(const Vec2& rhs); // ritorno una reference perchè è un assignemnt operator, non è const perchè sto modificando il lhs
	Vec2 operator*(float rhs) const;
	Vec2& operator*=(float rhs);
	Vec2 operator-(const Vec2& rhs) const; // lhs + rhs
	Vec2& operator-=(const Vec2& rhs);
	float getLenght() const;
	float getLenghtSq() const;
	Vec2& normalize();
	Vec2 getNormalize() const;
public:
	float x;
	float y;
};