#pragma once

#include "../Graphics.h"
#include "Renderer2D.h"

namespace Sparky
{
	namespace Graphics
	{
		class BatchRenderer2D : public Renderer2D
		{
		//Variables
		private:
			VertexArray m_VAO;
			GLuint m_VBO, m_IBO;

		public:

		//Functions
		private:

		public:
			void Submit(const Renderable2D* renderable) override;
			void Flush() override;
		};
	}
}
