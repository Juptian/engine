#pragma once

#include "../Utilities/Utilities.h"
#include "../Maths/Math.h"
#include <iostream>
#include <vector>
#include <GL\glew.h>

namespace Sparky 
{
	namespace Graphics
	{
		class Shader
		{
		public:

		private:
			GLuint m_ShaderID;
			const char* m_VertPath;
			const char* m_FragPath;

		public:


			/*
			* Shader(const char* vertPath, const char* fragPath)
			* @param vertPath Path to the vertex file
			* @param fragPath Path to the fragment file
			*/
			Shader(const char* vertPath, const char* fragPath);
			~Shader();


			/*
			* SetUniform1f(const GLChar* name, float value)
			* @param name Name of the uniform.
			* @param value Value to which you'd like to assign that uniform (float).
			*/
			void SetUniform1f(const GLchar* name, float value);


			/*
			* SetUniform1f(const GLChar* name, int value)
			* @param name Name of the uniform.
			* @param value Value to which you'd like to assign that uniform (int).
			*/
			void SetUniform1i(const GLchar* name, int value);


			/*
			* SetUniform2f(const GLChar* name, const Math::Vector2 vector)
			* @param name Name of the uniform.
			* @param vector The values that you would like to assign, using a Vector 2.
			*/
			void SetUniform2f(const GLchar* name, const Math::vec2 vector);


			/*
			* SetUniform3f(const GLChar* name, const Math::Vector3 vector)
			* @param name Name of the uniform.
			* @param vector The values that you would like to assign, using a Vector 3.
			*/
			void SetUniform3f(const GLchar* name, const Math::vec3 vector);
			

			/*
			* SetUniform4f(const GLChar* name, const Math::Vector4 vector)
			* @param name Name of the uniform.
			* @param vector The values that you would like to assign, using a Vector 4.
			*/
			void SetUniform4f(const GLchar* name, const Math::vec4 vector);


			/*
			* SetUniformMat4(const GLchar* name, const Math::mat4& matrix)
			* @param name Name of the uniform.
			* @param matrix A matrix reference for which you'd like to assign the uniform.
			*/
			void SetUniformMat4(const GLchar* name, const Math::mat4& matrix);

			void Enable() const;
			void Disable() const;
		private:

			/*
			* GetUniformLocation(const GLchar* name)
			* @param name Name of the uniform you would like to get
			* @return GLint of the index
			*/
			GLint GetUniformLocation(const GLchar* name);
			GLuint Load();
		};
	}
}