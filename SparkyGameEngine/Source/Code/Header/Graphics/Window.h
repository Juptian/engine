#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define OUT 

namespace Sparky
{
	namespace Graphics
	{
		#define MAX_KEYS 1024
		#define MAX_BUTTONS 32
		class Window
		{
			#define Mouse_Button_1 GLFW_MOUSE_BUTTON_ONE
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
			/*
			* IsKeyPressed(unsigned int keycode)
			* 
			* @param keycode Code for the key they would like to check
			* 
			* @return Returns true/false based on wether that key is pressed
			*/
			bool IsKeyPressed(unsigned int keycode) const;

			/*
			* IsMouseButtonPressed(unsigned int button)
			*
			* @param Button Code for the Mouse Button they would like to check
			*
			* @return Returns true/false based on wether that button is pressed
			*/
			bool IsMouseButtonPressed(unsigned int button) const;

			/*
			* GetMousePosition(double &x, double &y
			*
			* @param X Mouse position on the X Axis
			*
			* @param Y Mouse position on the Y axis
			* 
			* @return Returns the mouse position on the X and Y axis
			*/
			void GetMousePosition(OUT double &x, OUT double &y) const;

		private:
			bool Init();

			//frens <3
			friend static void Key_Callback(GLFWwindow *window, int key, int scancode, int action, int mods);
			friend static void Mouse_Button_Callback(GLFWwindow *window, int button, int action, int mods);
			friend static void Cursor_Position_Callback(GLFWwindow *window, double xpos, double ypos);
		};
	}
}