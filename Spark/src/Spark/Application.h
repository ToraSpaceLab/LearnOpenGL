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

	class SPARK_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;

	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();
}