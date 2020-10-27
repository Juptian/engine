#pragma once
#include <iostream>

#define Vector3 vec3
#define vector3 vec3
#define Vec3 vec3

namespace Sparky {
	namespace Math {
		struct vec3
		{
		//Variables
		public:
			float x, y, z;
		private:

		//Methods/Functions
		public:

			/*
			* Vector3()
			* Vector 3 constructor where the X, Y, and Z values are set to 0
			*/
			vec3();

			/*
			* Vector3(const float& x, const float& y, const float& z)
			* Vector 3 constructor where you can assign the X, Y, and Z values
			* @param x Value of the X axis
			* @param y Value of the Y axis
			* @param z Value of the Z axis
			*/
			vec3(const float& x, const float& y, const float& z);
			
			vec3& add(const vec3& other);
			vec3& subtract(const vec3& other);
			vec3& multiply(const vec3& other);
			vec3& divide(const vec3& other);

			vec3& operator+=(const vec3& other);
			vec3& operator-=(const vec3& other);
			vec3& operator*=(const vec3& other);
			vec3& operator/=(const vec3& other);

			bool operator==(const vec3& other);
			bool operator!=(const vec3& other);


			friend vec3& operator+(vec3 Left, const vec3& Right);
			friend vec3& operator-(vec3 Left, const vec3& Right);
			friend vec3& operator*(vec3 Left, const vec3& Right);
			friend vec3& operator/(vec3 Left, const vec3& Right);

			friend std::ostream& operator<<(std::ostream& stream, const vec3& vector);
		private:
		};
	}
}