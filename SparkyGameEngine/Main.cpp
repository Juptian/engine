//Header files
#include "Source\Code\Header\Maths\Math.h"
#include "Source\Code\Header\Graphics\Graphics.h"
#include "Source\Code\Header\Graphics\Window.h"
#include "Source\Code\Header\Graphics\Renderers\2DRenderer_S.h"

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
	using namespace Sparky;
	using namespace Graphics;
	using namespace Math;

	Window window("Sparky", 960, 540);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

#if 0
	GLfloat vertices[] =
	{
		0, 0, 0,
		0, 3, 0,
		8, 3, 0,
		8, 0, 0,
	};

	GLushort indices[] =
	{
		0, 1, 2,
		2, 3, 0
	};

	GLfloat colorsA[] =
	{
		1, 0, 1, 1,
		1, 0, 1, 1,
		1, 0, 1, 1,
		1, 0, 1, 1
	};

	GLfloat colorsB[] =
	{
		0.2f, 0.3f, 0.8f, 1.0f,
		0.2f, 0.3f, 0.8f, 1.0f,
		0.2f, 0.3f, 0.8f, 1.0f,
		0.2f, 0.3f, 0.8f, 1.0f
	};

	GLfloat colorsC[] =
	{
		0, 1, 0, 1,
		0, 1, 0, 1,
		0, 1, 0, 1,
		0, 1, 0, 1
	};

	VertexArray sprite1, sprite2, sprite3, sprite4, sprite5; 
	IndexBuffer ibo(indices, 6);

	sprite1.AddBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	sprite1.AddBuffer(new Buffer(colorsA, 4 * 4, 4), 1);

	sprite2.AddBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	sprite2.AddBuffer(new Buffer(colorsB, 4 * 4, 4), 1);

	sprite3.AddBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	sprite3.AddBuffer(new Buffer(colorsC, 4 * 4, 4), 1);

	sprite4.AddBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	sprite4.AddBuffer(new Buffer(colorsB, 4 * 4, 4), 1);

	sprite5.AddBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	sprite5.AddBuffer(new Buffer(colorsC, 4 * 4, 4), 1);
#endif

	mat4 ortho = mat4::Orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);


	Shader shader("Source/Shaders/basic.vert", "Source/Shaders/basic.frag");
	shader.Enable();

	shader.SetUniformMat4("pr_matrix", ortho);
	shader.SetUniformMat4("ml_matrix", mat4::Translation(vec3(4, 3, 0)));

	shader.SetUniform4f("color", vec4(1, 1, 1, 1)); // vec4(0.3f, 0.7f, 1.0f, 1.0f)

	Renderable2D Sprite(Vector3(5, 5, 0), Vector2(4, 4, 4), vector4(1, 0, 1, 1), shader);
	Simple2DRenderer renderer ;

	bool lightFollow = true;

	while (!window.Closed())
	{
		window.Clear();
		lightFollow = !window.IsMouseButtonPressed(GLFW_MOUSE_BUTTON_1);
		if (lightFollow)
		{
			double x, y;
			window.GetMousePosition(x, y);
			shader.SetUniform2f("light_pos", vec2(float(x * 16.0f / 960.0f), float(9.0f - y * 9.0f / 540.0f)));
		}
		
		renderer.Submit(Sprite);
		renderer.Flush();

		window.Update();
	}
	return 0;
}