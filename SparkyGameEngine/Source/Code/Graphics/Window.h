#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Sparky
{
	namespace Graphics
	{
		#define MAX_KEYS 1024
		#define MAX_BUTTONS 32
		class Window
		{
		//Variables
		public:
		private:
			//Private things
			const char *m_Title;
			GLFWwindow *m_Window;
			int m_Width, m_Height;

			//Static
			bool m_Keys[MAX_KEYS];
			bool m_Buttons[MAX_BUTTONS];
			double m_MouseX, m_MouseY;

		//Methods
		public:
			Window(const char *name, int width, int height);
			~Window();

			bool Closed() const;

			inline int GetHeight() const { return m_Height; }
			inline int GetWidth() const { return m_Width; }

			void Clear() const;
			void Update();

			//Static
			bool IsKeyPressed(unsigned int keycode) const;
			bool IsMouseButtonPressed(unsigned int button) const;
			void GetMousePosition(double &x, double &y) const;

		private:
			bool Init();

			//frens <3
			friend static void Key_Callback(GLFWwindow *window, int key, int scancode, int action, int mods);
			friend static void Mouse_Button_Callback(GLFWwindow *window, int button, int action, int mods);
			friend static void Cursor_Position_Callback(GLFWwindow *window, double xpos, double ypos);
		};
	}
}