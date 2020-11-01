#pragma once

#include "../graphics.h"

namespace Sparky
{
	namespace Graphics
	{
		class StaticSprite : public Renderable2D
		{
		private:
			//Shader
			Shader& m_Shader;

			//Buffers
			VertexArray* m_VertexArray;
			IndexBuffer* m_IndexBuffer;

		public:
			StaticSprite(float x, float y, float width, float height, Vector4& colour, Shader& shader);
			~StaticSprite();

			inline const VertexArray* GetVAO() const { return m_VertexArray; }
			inline const IndexBuffer* GetIBO() const { return m_IndexBuffer; }

			inline Shader& GetShader() const { return m_Shader; }
		};
	}
}
