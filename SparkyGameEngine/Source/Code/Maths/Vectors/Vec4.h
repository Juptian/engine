#pragma once
#include <iostream>

#define Vector4 vec4
#define vector4 vec4
#define Vec4 vec4

namespace Sparky {
	namespace Math {
		struct vec4
		{
		//Variables
		public:
			float x, y, z, w;
		private:

		//Methods/Functions
		public:
			//vec4();
			vec4() = default;
			vec4(const float& x, const float& y, const float& z, const float& w);
			
			vec4& add(const vec4& other);
			vec4& subtract(const vec4& other);
			vec4& multiply(const vec4& other);
			vec4& divide(const vec4& other);

			vec4& operator+=(const vec4& other);
			vec4& operator-=(const vec4& other);
			vec4& operator*=(const vec4& other);
			vec4& operator/=(const vec4& other);

			bool operator==(const vec4& other);
			bool operator!=(const vec4& other);


			friend vec4& operator+(vec4 Left, const vec4& Right);
			friend vec4& operator-(vec4 Left, const vec4& Right);
			friend vec4& operator*(vec4 Left, const vec4& Right);
			friend vec4& operator/(vec4 Left, const vec4& Right);

			friend std::ostream& operator<<(std::ostream& stream, const vec4& vector);
		private:
		};
	}
}