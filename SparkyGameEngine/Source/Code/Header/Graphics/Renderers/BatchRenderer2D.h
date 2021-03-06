#pragma once

#include "../Graphics.h"
#include "Renderer2D.h"

namespace Sparky
{
	namespace Graphics
	{
//Defines
#define RENDERER_MAX_SPRITES	10000
#define RENDERER_VERTEX_SIZE	sizeof(VertexData)
#define RENDERER_SPRITE_SIZE	RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE	RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
#define RENDERER_INDICES_SIZE	RENDERER_MAX_SPRITES * 6

#define SHADER_VERTEX_INDEX 0
#define SHADER_COLOUR_INDEX 1
#define SHADER_COLOR_INDEX  1

		class BatchRenderer2D : public Renderer2D
		{
		//Variables
		private:
			GLuint m_VAO;
			GLuint m_VBO;

			IndexBuffer* m_IBO;
			
			GLsizei m_IndexCount;

		private:
			void Init();
		public:
			BatchRenderer2D();
			~BatchRenderer2D();
			void Submit(const Renderable2D* renderable) override;
			void Flush() override;
		};
	}
}
