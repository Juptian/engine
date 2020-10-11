#include "Vec4.h"

namespace sparky {
	namespace Math {
		//Constructors
		/*
		vec4::vec4()
		{
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
			w = 0.0f;
		}
		*/
		vec4::vec4(const float& x, const float& y, const float& z, const float& w)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}
		//Maths
		vec4& vec4::add(const vec4& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;
			return *this;
		}
		vec4& vec4::subtract(const vec4& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;
			return *this;
		}
		vec4& vec4::multiply(const vec4& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			w *= other.w;
			return *this;
		}
		vec4& vec4::divide(const vec4& other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;
			w /= other.w;
			return *this;
		}

		//Single operators
		vec4& operator+(vec4 Left, const vec4& Right)
		{
			return Left.add(Right);
		}
		vec4& operator-(vec4 Left, const vec4& Right)
		{
			return Left.subtract(Right);
		}
		vec4& operator*(vec4 Left, const vec4& Right)
		{
			return Left.multiply(Right);
		}
		vec4& operator/(vec4 Left, const vec4& Right)
		{
			return Left.divide(Right);
		}

		//Double operators
		vec4& vec4::operator+=(const vec4& other)
		{
			return add(other);
		}
		vec4& vec4::operator-=(const vec4& other)
		{
			return subtract(other);
		}
		vec4& vec4::operator*=(const vec4& other)
		{
			return multiply(other);
		}
		vec4& vec4::operator/=(const vec4& other)
		{
			return divide(other);
		}

		bool vec4::operator==(const vec4& other)
		{
			return x == other.x && y == other.y && z == other.z && w == other.w;
		}

		bool vec4::operator!=(const vec4& other)
		{
			return !(*this == other);
		}

		//Outputting
		std::ostream& operator<<(std::ostream& stream, const vec4& vector)
		{
			stream << "vec4 (" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")";
			return stream;
		}
	}
}