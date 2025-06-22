#pragma once

#ifdef SE_PLATFORM_WINDOWS
	#if SE_DYNAMIC_LINK
		#ifdef SE_BUILD_DLL
			#define SPARK_API	__declspec(dllexport)
		#else
			#define SPARK_API	__declspec(dllexport)
		#endif
	#else
		#define SPARK_API
	#endif
#else
	#error Spark only support Windows!
#endif

#if SE_DEBUG
	#define SE_ENABLE_ASSERTS
#endif // SE_DEBUG

#ifdef SE_ENABLE_ASSERTS
	#define SE_ASSERT(x, ...) {if(!(x)) {SE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
	#define SE_CORE_ASSERT(x, ...) {if(!(x)) {SE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
	#define SE_ASSERT(x,...)
	#define SE_CORE_ASSERT(x, ...)
#endif // SE_ENABLE_ASSERTS

#define BIT(x) (1<<x)

#define SE_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)


