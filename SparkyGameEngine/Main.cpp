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

	Window window("Sparky", 1920, 1080);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	mat4 ortho = mat4::Orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("Source/Shaders/basic.vert", "Source/Shaders/basic.frag");
	shader.Enable();

	shader.SetUniformMat4("pr_matrix", ortho);
	shader.SetUniformMat4("ml_matrix", mat4::Translation(vec3(4, 3, 0)));

	shader.SetUniform4f("color", vec4(1, 1, 1, 1)); // vec4(0.3f, 0.7f, 1.0f, 1.0f)

	Renderable2D Sprite1(vec3(5, 5, 0), vec2(4, 4), vec4(1, 0, 1, 1), shader);
	Renderable2D Sprite2(vec3(7, 1, 0), vec2(2, 3), vec4(0.2f, 0, 1, 1), shader);

	Simple2DRenderer renderer;

	bool lightFollow = true;
	double x, y;

	while (!window.Closed())
	{
		window.Clear();
		lightFollow = !window.IsMouseButtonPressed(GLFW_MOUSE_BUTTON_1);
		if (lightFollow)
		{
			window.GetMousePosition(x, y);
			shader.SetUniform2f("light_pos", vec2(float(x * 16.0f / 1920.0f), float(9.0f - y * 9.0f / 1080.f)));
		}
		
		renderer.Submit(&Sprite1);
		renderer.Submit(&Sprite2);
		renderer.Flush();

		window.Update();
	}
	return 0;
}