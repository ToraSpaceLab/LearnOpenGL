#pragma once
#include <iostream>

namespace Spark {

	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(
			const std::string& title = "My Engine",
			unsigned int width = 1280,
			unsigned int height = 720
		) :Title(title), Width(width), Height(height)
		{
		}
	};

	class Window
	{
	public:
		Window();
		~Window();

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}