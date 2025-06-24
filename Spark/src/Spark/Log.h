#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Spark {
	class SPARK_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr< spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr< spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


// Core log macros
#define SE_CORE_TRACE(...)    ::Spark::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SE_CORE_INFO(...)     ::Spark::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SE_CORE_WARN(...)     ::Spark::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SE_CORE_ERROR(...)    ::Spark::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SE_CORE_FATAL(...)    ::Spark::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define SE_TRACE(...)	      ::Spark::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SE_INFO(...)          ::Spark::Log::GetClientLogger()->info(__VA_ARGS__)
#define SE_WARN(...)          ::Spark::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SE_ERROR(...)         ::Spark::Log::GetClientLogger()->error(__VA_ARGS__)
#define SE_FATAL(...)         ::Spark::Log::GetClientLogger()->fatal(__VA_ARGS__)