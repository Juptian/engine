#include "Vec3.h"

namespace sparky {
	namespace Math {
		//Constructors
		vec3::vec3()
		{
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
		}
		vec3::vec3(const float& x, const float& y, const float& z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}
		//Maths
		vec3& vec3::add(const vec3& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			return *this;
		}
		vec3& vec3::subtract(const vec3& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			return *this;
		}
		vec3& vec3::multiply(const vec3& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			return *this;
		}
		vec3& vec3::divide(const vec3& other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;
			return *this;
		}

		//Single operators
		vec3& operator+(vec3 Left, const vec3& Right)
		{
			return Left.add(Right);
		}
		vec3& operator-(vec3 Left, const vec3& Right)
		{
			return Left.subtract(Right);
		}
		vec3& operator*(vec3 Left, const vec3& Right)
		{
			return Left.multiply(Right);
		}
		vec3& operator/(vec3 Left, const vec3& Right)
		{
			return Left.divide(Right);
		}

		//Double operators
		vec3& vec3::operator+=(const vec3& other)
		{
			return add(other);
		}
		vec3& vec3::operator-=(const vec3& other)
		{
			return subtract(other);
		}
		vec3& vec3::operator*=(const vec3& other)
		{
			return multiply(other);
		}
		vec3& vec3::operator/=(const vec3& other)
		{
			return divide(other);
		}

		bool vec3::operator==(const vec3& other)
		{
			return x == other.x && y == other.y && z == other.z;
		}

		bool vec3::operator!=(const vec3& other)
		{
			return !(*this == other);
		}

		//Outputting
		std::ostream& operator<<(std::ostream& stream, const vec3& vector)
		{
			stream << "vec3 (" << vector.x << ", " << vector.y << ", " << vector.z << ")";
			return stream;
		}
	}
}