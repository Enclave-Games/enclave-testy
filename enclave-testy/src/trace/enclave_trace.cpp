#include "enclave_trace.h"

namespace enclave_testy
{
	void enclave_trace::trace_warning(const char* message)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
			FOREGROUND_INTENSITY | 
			colors::YELLOW);

		puts(message);
	}

	void enclave_trace::trace_error(const char* message)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
			FOREGROUND_INTENSITY |
			colors::RED);

		puts(message);
	}
}