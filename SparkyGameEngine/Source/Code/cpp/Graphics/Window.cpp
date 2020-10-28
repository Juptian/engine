#include "..\..\Header\Graphics\Window.h"

namespace Sparky {
	namespace Graphics {
		//Functions
		void Window_Resize(GLFWwindow* window, int width, int height);
		void Key_Callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		void Mouse_Button_Callback(GLFWwindow* window, int button, int action, int mods);
		void Cursor_Position_Callback(GLFWwindow* window, double xpos, double ypos);

			//Constructor
		Window::Window(const char* title, int width, int height)
		{
			m_Width = width;
			m_Height = height;
			m_Title = title;
			if (!Init())
			{
				glfwTerminate();
			}
			for (int i = 0; i < MAX_KEYS; i++)
			{
				m_Keys[i] = false;
			}
			for (int i = 0; i < MAX_BUTTONS; i++)
			{
				m_Buttons[i] = false;
			}
		}
		//Deconstructor
		Window::~Window()
		{
			glfwTerminate();
		}

		//Initializing window
		bool Window::Init()
		{
			//Checking for GLFW
			if (!glfwInit())
			{
				std::cout << "Failed to initialize GLFW\n";
				return false;
			}

			//Creating Window
			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
			if (!m_Window)
			{
				std::cout << "Failed to create window\n";
				glfwTerminate();
				return false;
			}

			glfwMakeContextCurrent(m_Window);
			glfwSetWindowUserPointer(m_Window, this);
			glfwSetWindowSizeCallback(m_Window, Window_Resize);
			glfwSetKeyCallback(m_Window, Key_Callback);
			glfwSetMouseButtonCallback(m_Window, Mouse_Button_Callback);
			glfwSetCursorPosCallback(m_Window, Cursor_Position_Callback);

			//Checking for glew
			if (glewInit() != GLEW_OK)
			{
				std::cout << "Could not init GLEW!\n";
				return false;
			}


			return true;
		}
		
		//Update and close
		void Window::Update()
		{
			GLenum error = glGetError();
			if (error != GL_NO_ERROR)
			{
				std::cout << "OpenGL Error: " << error << "\n";
			}

			glfwPollEvents();
			glfwSwapBuffers(m_Window);
		}
		bool Window::Closed() const
		{
			return glfwWindowShouldClose(m_Window) == 1;
		}

		//Clear
		void Window::Clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		//Window Resize
		void Window_Resize(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

		//KEYS
		void Key_Callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			Window* win = (Window*) glfwGetWindowUserPointer(window);
			win->m_Keys[key] = action != GLFW_RELEASE;
		}

		bool Window::IsKeyPressed(unsigned int keycode) const
		{
			//Todo: Log this!
			if (keycode >= MAX_KEYS)
			{
				return false;
			}
			return m_Keys[keycode];
		}

		//MOUSE BUTTONS
		void Mouse_Button_Callback(GLFWwindow* window, int button, int action, int mods)
		{
			Window* win = (Window*) glfwGetWindowUserPointer(window);
			win->m_Buttons[button] = action != GLFW_RELEASE;
		}
		bool Window::IsMouseButtonPressed(unsigned int button) const
		{
			//Todo: Log this!
			if (button >= MAX_BUTTONS)
			{
				return false;
			}
			return m_Buttons[button];
		}

		//MOUSE MOVEMENT
		void Cursor_Position_Callback(GLFWwindow* window, double xpos, double ypos)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_MouseX = xpos;
			win->m_MouseY = ypos;
		}
		void Window::GetMousePosition(OUT double& x, OUT double& y) const
		{
			x = m_MouseX;
			y = m_MouseY;
		}
	}
}
