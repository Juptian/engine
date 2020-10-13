#pragma once

#define vertexArray VertexArray
#define vertexarray VertexArray

#include "Buffer.h"

#include <vector>
#include <GL\glew.h>

namespace sparky
{
	namespace graphics
	{
		class VertexArray
		{
		public:

		private:
			GLuint m_ArrayID;
			std::vector<Buffer*> m_Buffers;

		public:
			VertexArray();
			~VertexArray();

			void AddBuffer(Buffer* buffer, GLuint index);
			void Bind() const;
			void Unbind() const;

		private:

		};
	}
}