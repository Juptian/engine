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
			* Creates a shader!
			* 
			* @param vertPath  Path to the vertex file
			* 
			* @param fragPath Path to the fragment file
			*/
			Shader(const char* vertPath, const char* fragPath);
			~Shader();


			/*
			* SetUniform1f(const GLChar* name, float value)
			* Sets the uniform in a shader
			* 
			* @param name Name of the uniform.
			* 
			* @param value Value to which you'd like to assign that uniform (float).
			*/
			void SetUniform1f(const GLchar* name, float value);


			/*
			* SetUniform1i(const GLChar* name, int value)
			* Sets the uniform in a shader
			* 
			* @param name Name of the uniform.
			* 
			* @param value Value to which you'd like to assign that uniform (int).
			*/
			void SetUniform1i(const GLchar* name, int value);


			/*
			* SetUniform2f(const GLChar* name, const Vector2 vector)
			* Sets the uniform in a shader
			* 
			* @param name Name of the uniform.
			* 
			* @param vector The values that you would like to assign, using a Vector2.
			* 
			* @see Vector2
			*/
			void SetUniform2f(const GLchar* name, const vec2 vector);


			/*
			* SetUniform3f(const GLChar* name, const Vector3 vector)
			* Sets the uniform in a shader
			* 
			* @param name Name of the uniform.
			* 
			* @param vector The values that you would like to assign, using a Vector 3.
			* 
			* @see Vector3
			*/
			void SetUniform3f(const GLchar* name, const vec3 vector);
			

			/*
			* SetUniform4f(const GLChar* name, const Vector4 vector)
			* Sets the uniform in a shader
			* 
			* @param name Name of the uniform.
			* 
			* @param vector The values that you would like to assign, using a Vector 4.
			* 
			* @see Vector4
			*/
			void SetUniform4f(const GLchar* name, const vec4 vector);


			/*
			* SetUniformMat4(const GLchar* name, const Math::mat4& matrix)
			* Sets the uniform in a shader
			* 
			* @param name Name of the uniform.
			* 
			* @param matrix A matrix reference for which you'd like to assign the uniform.
			*/
			void SetUniformMat4(const GLchar* name, const mat4& matrix);

			void Enable() const;
			void Disable() const;
		private:

			/*
			* GetUniformLocation(const GLchar* name)
			* 
			* @param name Name of the uniform you would like to get
			* 
			* @return GLint of the index
			*/
			GLint GetUniformLocation(const GLchar* name);
			GLuint Load();
		};
	}
}