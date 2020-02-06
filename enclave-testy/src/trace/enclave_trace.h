#ifndef ENCLAVE_TESTY_TRACE
#define ENCLAVE_TESTY_TRACE

#include <string>
#include <Windows.h>

namespace enclave_testy
{
	enum answer
	{
		yes,
		no,
		maybe
	};

	enum colors
	{
		YELLOW = 6,
		RED = FOREGROUND_RED
	};

	class enclave_trace
	{
	public:
		void trace_warning(const char* message);
		void trace_warning(answer& message);
		void trace_error(const char* message);
		void trace_error(answer& message);
	private:
	};
}

#endif