#pragma once

#include "../Graphics.h"
#include "../../Maths/Math.h"


namespace Sparky
{
	namespace Graphics
	{
		class Renderable2D
		{
		protected:
			//Vectors
			vec2 m_Size;
			vec3 m_Position;
			vec4 m_Colour;


		public:
			
			/*
			* Renderable2D(Vector3 position, Vector2 size, Vector4 color, Shader* shader)
			* 
			* @param position position of the rendered object
			* 
			* @param size Size of the object
			* 
			* @param color Colour of the object
			* 
			* @param shader Shader of the object
			*/
			Renderable2D(Vector3 position, Vector2 size, Vector4 color);
			virtual ~Renderable2D();

			inline const Vector3& GetPosition() const { return m_Position; }
			inline const Vector2& GetSize() const { return m_Size; }
			inline const Vector4& GetColor() const { return m_Colour; }

		};
	}
}