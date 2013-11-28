#include <cmath>

#include "Vector2.h"

Vector2::Vector2(float x, float y)
: x_(x), y_(y)
{

}

float Vector2::getX() const
{
	return x_;
}

float Vector2::getY() const
{
	return y_;
}

void Vector2::setX(float x)
{
	x_ = x;
}

void Vector2::setY(float y)
{
	y_ = y;
}

float Vector2::length() const
{
	return sqrt(x_ * x_ + y_ * y_);
}

void Vector2::normalize()
{
	float vecLength = length();

	x_ /= vecLength;
	y_ /= vecLength;
}

Vector2 Vector2::operator+(const Vector2& vec)
{
	Vector2 returnVec = *this;

	returnVec.setX(returnVec.getX() + vec.getX());
	returnVec.setY(returnVec.getY() + vec.getY());

	return returnVec;
}

Vector2 Vector2::operator-(const Vector2& vec)
{
	Vector2 returnVec = *this;

	returnVec.setX(returnVec.getX() - vec.getX());
	returnVec.setY(returnVec.getY() - vec.getY());

	return returnVec;
}

Vector2 Vector2::operator*(float scalar)
{
	Vector2 returnVec = *this;

	returnVec.setX(returnVec.getX() * scalar);
	returnVec.setY(returnVec.getY() * scalar);

	return returnVec;
}

Vector2 Vector2::operator/(float scalar)
{
	Vector2 returnVec = *this;

	returnVec.setX(returnVec.getX() / scalar);
	returnVec.setY(returnVec.getY() / scalar);

	return returnVec;
}

Vector2& Vector2::operator+=(const Vector2& vec)
{
	x_ += vec.getX();
	y_ += vec.getY();

	return *this;
}

Vector2& Vector2::operator-=(const Vector2& vec)
{
	x_ -= vec.getX();
	y_ -= vec.getY();

	return *this;
}

Vector2& Vector2::operator*=(float scalar)
{
	x_ *= scalar;
	y_ *= scalar;

	return *this;
}

Vector2& Vector2::operator/=(float scalar)
{
	x_ /= scalar;
	y_ /= scalar;

	return *this;
}

std::ostream& operator<<(std::ostream& out, const Vector2& vec)
{
	out << "(" << vec.getX() << ", " << vec.getY() << ")";

	return out;
}