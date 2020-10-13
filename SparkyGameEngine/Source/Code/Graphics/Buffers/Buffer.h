#pragma once

#define buffer Buffer

#include <GL\glew.h>

namespace Sparky
{
	namespace Graphics
	{
		class Buffer
		{
		public:
		private:
			GLuint m_BufferID;
			GLuint m_ComponentCount; //The type (vec2, vec3, vec4)

		public:
			Buffer(GLfloat* data, GLsizei count, GLuint componentCount);
			
			inline GLuint GetComponentCount() const { return m_ComponentCount; }

			void Bind() const;
			void Unbind() const;

		private:

		};
	}
}