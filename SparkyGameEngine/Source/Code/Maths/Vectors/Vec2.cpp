#include "Vec2.h"

namespace sparky {
	namespace Math {
		//Constructors
		vec2::vec2()
		{
			x = 0.0f;
			y = 0.0f;
		}
		vec2::vec2(const float& x, const float& y)
		{
			this->x = x;
			this->y = y;
		}
		//Math
		vec2& vec2::add(const vec2& other)
		{
			x += other.x;
			y += other.y;
			return *this;
		}
		vec2& vec2::subtract(const vec2& other)
		{
			x -= other.x;
			y -= other.y;
			return *this;
		}
		vec2& vec2::multiply(const vec2& other)
		{
			x *= other.x;
			y *= other.y;
			return *this;
		}
		vec2& vec2::divide(const vec2& other)
		{
			x /= other.x;
			y /= other.y;
			return *this;
		}

		//Single operators
		vec2& operator+(vec2 Left, const vec2& Right)
		{
			return Left.add(Right);
		}
		vec2& operator-(vec2 Left, const vec2& Right)
		{
			return Left.subtract(Right);
		}
		vec2& operator*(vec2 Left, const vec2& Right)
		{
			return Left.multiply(Right);
		}
		vec2& operator/(vec2 Left, const vec2& Right)
		{
			return Left.divide(Right);
		}

		//Double operators
		vec2& vec2::operator+=(const vec2& other)
		{
			return add(other);
		}
		vec2& vec2::operator-=(const vec2& other)
		{
			return subtract(other);
		}
		vec2& vec2::operator*=(const vec2& other)
		{
			return multiply(other);
		}
		vec2& vec2::operator/=(const vec2& other)
		{
			return divide(other);
		}

		bool vec2::operator==(const vec2& other)
		{
			return x == other.x && y == other.y;
		}

		bool vec2::operator!=(const vec2& other)
		{
			return !(*this == other);
		}

		//Outputting
		std::ostream& operator<<(std::ostream& stream, const vec2& vector)
		{
			stream << "Vector2 (" << vector.x << ", " << vector.y << ")";
			return stream;
		}
	}
}