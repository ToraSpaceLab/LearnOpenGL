#pragma once

#ifdef SE_PLATFORM_WINDOWS

extern Spark::Application* Spark::CreateApplication();

void main(int argc, char** argv)
{
	Spark::Log::Init();

}

#endif // SE_PLATFORM_WINDOWS

