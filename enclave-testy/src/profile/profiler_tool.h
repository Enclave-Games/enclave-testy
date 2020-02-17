#ifndef ENCLAVE_TESTY_PERFOMANCE_TOOL
#define ENCLAVE_TESTY_PERFOMANCE_TOOL

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <map>
#include <limits.h>
#include <stdlib.h>
#include <random>
#include <thread>

using chrono_time_pt_high_res = std::chrono::time_point<std::chrono::high_resolution_clock>;
using chrono_time_pt_steady = std::chrono::time_point<std::chrono::steady_clock>;

namespace testy
{
	namespace profilling
	{
		class profiller
		{
		public:
			struct profilling_info
			{
				
			};

			profiller() = default;
			explicit profiller(const char* name);
			void stop();
			void begin_session(const std::string _message);
			void begin_session(const std::string message, bool is_console_out);
			void create_and_write_data_to(const std::string filepath);
			void write_data(const std::string filepath);
			inline uint64_t calculate_session_id();
			void end_session();
			~profiller();
		private:
			std::string _message;
			std::ofstream _output_stream;
			std::map<uint64_t, const char*> map_sessions;
			chrono_time_pt_high_res _start_timepoint;
			const char* _session_name;
			uint64_t _session_id;
			bool _stopped = false;
		};
	}
}



#endif
