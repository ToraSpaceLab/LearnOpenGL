#include <Spark.h>

class ExampleLayer : public Spark::Layer
{
public:
	ExampleLayer() : Layer("Example")
	{
	}

	void OnUpdate() override
	{
		//if (Spark::Input::IsKeyPressed(SE_KEY_TAB))
		//{
		//	SE_TRACE("Tab key is pressed (poll)!");
		//}
	}

	//void OnEvent(Spark::Event& event) override
	//{
	//	if (event.GetEventType() == Spark::EventType::KeyPressed)
	//	{
	//		Spark::KeyPressedEvent& e = (Spark::KeyPressedEvent&)event;
	//		if (e.GetKeyCode() == SE_KEY_TAB)
	//		{
	//			SE_TRACE("Tab key is pressed (event)!");
	//		}
	//		SE_TRACE("{0}", (char)e.GetKeyCode());
	//	}
	//}
};

class Sandbox : public Spark::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

Spark::Application* Spark::CreateApplication()
{
	return new Sandbox();
}