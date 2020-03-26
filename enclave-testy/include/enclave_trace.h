#ifndef ENCLAVE_TESTY_TRACE
#define ENCLAVE_TESTY_TRACE

#include <string>
#include <Windows.h>

namespace testy
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

	void trace_warning(const char* message)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
			FOREGROUND_INTENSITY |
			colors::YELLOW);

		puts(message);
	}

	void trace_error(const char* message)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
			FOREGROUND_INTENSITY |
			colors::RED);

		puts(message);
	}

	void trace_warning(answer& message)
	{

	}

	void trace_error(answer& message)
	{

	}
}

#endif