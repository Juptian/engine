#pragma once

#define _USE_MATH_DEFINES
#define Mat4 mat4

#include "..\Math.h"
#include <math.h>

namespace sparky {
	namespace Math {

		struct mat4
		{
		//Variables
		public:
			union
			{
				float elements[4 * 4];
				vec4 columns[4];
			};
		private:

		//Functions/methods
		public:
			//Constructors
			mat4();
			mat4(float diagonal);

			//Setting identity
			static mat4 Identity();


			//Operators
			mat4& Multiply(const mat4& other);
			friend mat4& operator*(mat4 Left, const mat4& Right);
			mat4& operator*=(const mat4& other);

			//Projection
			static mat4 Orthographic(float left, float right, float bottom, float top, float near, float far);
			static mat4 Perspective(float fov, float aspectRatio, float near, float far);

			//Translation Matricies
			static mat4 Translation(const vec3& translation);
			static mat4 Rotation(float angle, const vec3& axis);
			static mat4 Scale(const vec3& scale);
			
		private:
		};
	}
}
