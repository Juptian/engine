#pragma once
#include <iostream>

namespace sparky {
	namespace Math {
		struct vec2
		{
		//Variables
		public:
			float x, y;
		private:

		//Methods/Functions
		public:
			vec2();
			vec2(const float& x, const float& y);
			
			vec2& add(const vec2& other);
			vec2& subtract(const vec2& other);
			vec2& multiply(const vec2& other);
			vec2& divide(const vec2& other);

			vec2& operator+=(const vec2& other);
			vec2& operator-=(const vec2& other);
			vec2& operator*=(const vec2& other);
			vec2& operator/=(const vec2& other);

			bool operator==(const vec2& other);
			bool operator!=(const vec2& other);


			friend vec2& operator+(vec2 Left, const vec2& Right);
			friend vec2& operator-(vec2 Left, const vec2& Right);
			friend vec2& operator*(vec2 Left, const vec2& Right);
			friend vec2& operator/(vec2 Left, const vec2& Right);

			friend std::ostream& operator<<(std::ostream& stream, const vec2& vector);
		private:
		};
	}
}