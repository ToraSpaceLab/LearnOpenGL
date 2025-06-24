#pragma once

#ifdef SE_PLATFORM_WINDOWS

extern Spark::Application* Spark::CreateApplication();

void main(int argc, char** argv)
{
	Spark::Log::Init();
	SE_CORE_WARN("Initialized Log!");
	int a = 5;
	SE_INFO("Hello! Var={0}", a);

	auto app = Spark::CreateApplication();
	app->Run();
	delete app;
}

#endif // SE_PLATFORM_WINDOWS

