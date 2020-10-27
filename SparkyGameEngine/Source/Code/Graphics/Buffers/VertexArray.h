#pragma once

#define vertexArray VertexArray
#define vertexarray VertexArray

#include "Buffer.h"

#include <vector>
#include <GL\glew.h>

namespace Sparky
{
	namespace Graphics
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

			/*
			* AddBuffer(Buffer* buffer, GLuint index)
			* @param buffer 
			* A `Buffer` pointer to add to the vertex array
			* 
			* @param index 
			* Index of the which you would like to in the vertex path
			*/
			void AddBuffer(Buffer* buffer, GLuint index);
			void Bind() const;
			void Unbind() const;

		private:

		};
	}
}