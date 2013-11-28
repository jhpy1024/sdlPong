#ifndef VECTOR2_H
#define VECTOR2_H

#include <iostream>

class Vector2
{
public:
	Vector2(float x = 0.f, float y = 0.f);

	float getX() const;
	float getY() const;

	void setX(float x);
	void setY(float y);

	float length() const;

	void normalize();

	Vector2 operator+(const Vector2& vec);
	Vector2 operator-(const Vector2& vec);
	Vector2 operator*(float scalar);
	Vector2 operator/(float scalar);

	Vector2& operator+=(const Vector2& vec);
	Vector2& operator-=(const Vector2& vec);
	Vector2& operator*=(float scalar);
	Vector2& operator/=(float scalar);

	friend std::ostream& operator<<(std::ostream& out, const Vector2& vec);

private:
	float x_;
	float y_;
};

#endif