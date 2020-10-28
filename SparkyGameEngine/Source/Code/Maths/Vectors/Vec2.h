#pragma once
#include <iostream>

#define Vector2 vec2
#define vector2 vec2
#define Vec2 vec2

namespace Sparky {
	namespace Math {
		struct vec2
		{
		//Variables
		public:
			float x, y;
		private:

		//Methods/Functions
		public:

			/*
			* Vector2()
			* Vector 2 constructor where the `X` and `Y` values are set to 0
			*/
			vec2();

			/*
			* Vector2(const float& x, const float& y)
			* Vector 2 constructor where you can assign the `X` and `Y` values
			* 
			* @param x Value of the `X` axis
			* 
			* @param y Value of the `Y` axis
			*/
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