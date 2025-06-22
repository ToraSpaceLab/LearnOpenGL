#include "sepch.h"

#include "Application.h"
#include "Renderer/VertexArray.h"

#include <glad/glad.h>

namespace Spark {

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());

		m_VertexArray.reset(VertexArray::Create());

		float vertices[3 * 3] = {
			//triangle
			-0.5f, -0.5f, 0.0f,  // left bottom
			 0.0f,  0.5f, 0.0f,  // top middle
			 0.5f, -0.5f, 0.0f   // bottom right
		};

		std::shared_ptr<VertexBuffer> vertexBuffer;
		vertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		std::string vertexSrc = R"(
		#version 330 core

		layout (location = 0) in vec3 aPos;
		
		void main()
		{
			gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
		}
	)";

		std::string fragmentSrc = R"(
		#version 330 core

		out vec4 FragColor;

		in vec3 v_Position;
		in vec4 v_Color;

		void main()
		{
			FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
		}
	)";

		std::string greenBlackVertexShaderSource = R"(
		#version 330 core
		layout (location = 0) in vec3 aPos; // the position variable has attribute position 0
  
		out vec4 vertexColor; // specify a color output to the fragment shader

		void main()
		{
			gl_Position = vec4(aPos, 1.0); // see how we directly give a vec3 to vec4's constructor
			vertexColor = vec4(0.5, 0.0, 0.0, 1.0); // set the output variable to a dark-red color
		}
	)";

		const char* greenBlackFragmentShaderSource = R"(
		#version 330 core
		out vec4 FragColor;
  
		uniform vec4 ourColor; // we set this variable in the OpenGL code.

		void main()
		{
			FragColor = ourColor;
		}
	)";
	}

	Application::~Application() {}

	void Application::Run()
	{
		while (m_Running)
		{
			// rendering commands here
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);


		}
	}
}