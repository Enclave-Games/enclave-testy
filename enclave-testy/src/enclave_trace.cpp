#include "enclave_trace.h"

namespace testy
{
	void trace::trace_warning(const char* message)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
			FOREGROUND_INTENSITY | 
			colors::YELLOW);

		puts(message);
	}

	void trace::trace_error(const char* message)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
			FOREGROUND_INTENSITY |
			colors::RED);

		puts(message);
	}
}