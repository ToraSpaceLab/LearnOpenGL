#include "sepch.h"

#include "OpenGLContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <gl/GL.h>

namespace Spark {
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) : m_WindowHandle(windowHandle)
	{
		SE_CORE_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		SE_CORE_ASSERT(status, "Failed to initialize Glad!");

		SE_CORE_INFO("OpenGL Info:");
		SE_CORE_INFO("	Vendor: {0}", (char*)glGetString(GL_VENDOR));
		SE_CORE_INFO("	Renderer: {0}", (char*)glGetString(GL_RENDERER));
		SE_CORE_INFO("	Version: {0}", (char*)glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}