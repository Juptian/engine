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

			/*
			* Buffer(GLfloat* data, GLsizei count, GLuint componentCount)
			* 
			* @param data Float array containing verticies
			* 
			* @param count Count of the items
			* 
			* @param componentCount Count of the components (ie a 3x4 array would be: Buffer(Name, 3, 4))
			* 
			*/
			Buffer(GLfloat* data, GLsizei count, GLuint componentCount);
			
			inline GLuint GetComponentCount() const { return m_ComponentCount; }

			void Bind() const;
			void Unbind() const;

		private:

		};
	}
}