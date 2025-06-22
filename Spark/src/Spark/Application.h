#pragma once

#include "Core.h"

#include "Window.h"
#include "Spark/LayerStack.h"
#include "Spark/Events/Event.h"
#include "Spark/Events/ApplicationEvent.h"

#include "Spark/Renderer/Shader.h"
#include "Spark/Renderer/Buffer.h"
#include "Spark/Renderer/VertexArray.h"

namespace Spark {

	class Application
	{
	public:
		Application();
		~Application();

		void Run();

		void OnEvent();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

	private:
		std::unique_ptr<Window> m_Window;

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;

	private:
		bool m_Running = true;

	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();
}