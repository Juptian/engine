#pragma once

#define _USE_MATH_DEFINES
#define Mat4 mat4

#include "..\Math.h"
#include <Math.h>

namespace Sparky {
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

			/*
			* Translation(const Vector3& translation)
			* @param translation 
			* Vector3& of which you'd like to translate an object
			* 
			* @return `Mat4` of the translation
			*/
			static mat4 Translation(const vec3& translation);
			
			/*
			* Rotation(float angle, const Vector3& axis)
			* @param angle 
			* Angle that you would like to rotate the object by (`float`)
			* 
			* @param axis 
			* `Vector3` containing the axis of rotation
			*/
			static mat4 Rotation(float angle, const vec3& axis);

			/*
			* Scale(const Vector3& scale)
			* @param scale 
			* Scale (`Vector3`) of which you'd like scale the axis
			*/
			static mat4 Scale(const vec3& scale);
			
		private:
		};
	}
}
