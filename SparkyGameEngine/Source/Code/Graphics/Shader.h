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
			Shader(const char* vertPath, const char* fragPath);
			~Shader();


			void SetUniform1f(const GLchar* name, float value);
			void SetUniform1i(const GLchar* name, int value);

			void SetUniform2f(const GLchar* name, const Math::vec2 vector);
			void SetUniform3f(const GLchar* name, const Math::vec3 vector);
			void SetUniform4f(const GLchar* name, const Math::vec4 vector);


			void SetUniformMat4(const GLchar* name, const Math::mat4& matrix);

			void Enable() const;
			void Disable() const;
		private:
			GLint GetUniformLocation(const GLchar* name);
			GLuint Load();
		};
	}
}