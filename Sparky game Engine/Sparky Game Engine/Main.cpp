//Header files
#include "Source\Code\Maths\Math.h"
#include "Source\Code\Graphics\Graphics.h"


//Libraries
#include <iostream>
#include <GLFW\glfw3.h>	

/*
Pointers
Mem adress that points to data
To access that data, you need to dereference it
*/

int main()
{
	using namespace sparky;
	using namespace graphics;
	using namespace Math;

	Window window("Sparky", 960, 540);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	GLfloat vertices[] =
	{
		/*-0.5f, -0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,*/
		0, 0, 0,
		8, 0, 0,
		0, 3, 0,
		0, 3, 0,
		8, 3, 0,
		8, 0, 0
	};

	GLuint vao, vbo;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//Making the vertices popup
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);


	mat4 ortho = mat4::Orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("Source/Shaders/basic.vert", "Source/Shaders/basic.frag");
	shader.Enable();

	shader.SetUniformMat4("pr_matrix", ortho);
	//shader.SetUniformMat4("ml_matrix", mat4::Translation(vec3(4, 3, 0)));
	shader.SetUniformMat4("ml_matrix", mat4::Translation(vec3(4, 3, 0)));

	shader.SetUniform2f("light_pos", vec2(8.0, 3.0f));
	shader.SetUniform4f("colour", vec4(0.3f, 0.7f, 1.0f, 1.0f));

	while (!window.Closed())
	{
		window.Clear();
		glDrawArrays(GL_TRIANGLES, 0, 12);
		window.Update();
	}
	return 0;
}