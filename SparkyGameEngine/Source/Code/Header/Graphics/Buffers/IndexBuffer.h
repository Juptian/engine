#pragma once

#define indexbuffer IndexBuffer
#define Indexbuffer IndexBuffer
#define indexBuffer IndexBuffer

#include <GL\glew.h>

namespace Sparky {
	namespace Graphics
	{
		class IndexBuffer
		{
		public:
		private:
			GLuint m_BufferID;
			GLuint m_Count;

		public:

			/*
			* IndexBuffer(GLushort* data, GLsizei count)
			* IndexBuffer constructor
			* 
			* @param data Unsigned short containing Indicies
			* 
			* @param count 
			*/
			IndexBuffer(GLushort* data, GLsizei count);

			inline GLuint GetCount() const { return m_Count; }

			void Bind() const;
			void Unbind() const;

		private:

		};
	}
}