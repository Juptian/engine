#pragma once

#define indexbuffer IndexBuffer
#define Indexbuffer IndexBuffer
#define indexBuffer IndexBuffer

#include <GL\glew.h>

namespace sparky {
	namespace graphics
	{
		class IndexBuffer
		{
		public:
		private:
			GLuint m_BufferID;
			GLuint m_Count;

		public:
			IndexBuffer(GLushort* data, GLsizei count);

			inline GLuint GetCount() const { return m_Count; }

			void Bind() const;
			void Unbind() const;

		private:

		};
	}
}