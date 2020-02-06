#ifndef ENCLAVE_TESTY_TRACE
#define ENCLAVE_TESTY_TRACE

#include <string>

namespace enclave_testy
{
	enum answer
	{
		yes,
		no,
		maybe
	};

	class enclave_trace
	{
	public:
		void trace_warning(std::string& message);
		void trace_warning(answer& message);
		void trace_error(std::string& message);
		void trace_error(answer& message);
	private:
	};
}

#endif