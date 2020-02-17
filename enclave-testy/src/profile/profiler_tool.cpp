#include "profiler_tool.h"

namespace testy
{
	namespace profilling
	{
		profiller::profiller(const char* session_name)
			: _session_name(session_name)
		{
			_start_timepoint = std::chrono::high_resolution_clock::now();
		}

		void profiller::create_and_write_data_to(const std::string filepath = "perfomance.json")
		{
			_output_stream.open(filepath);
		}

		uint64_t profiller::calculate_session_id()
		{
			std::random_device rd;
			std::mt19937_64 eng(rd());

			std::uniform_int_distribution<uint64_t> distr;

			uint64_t id = distr(eng);
			return id;
		}


		void profiller::begin_session(const std::string message, bool is_console_out)
		{

			if (is_console_out)
			{
				_session_id = calculate_session_id();
				_message = message;
				std::cout << "Session Id - " << _session_id << "\n"
					<< "Session Name - " << _session_name << "\n"
					<< '\n';
			}
			else
			{
				_session_id = calculate_session_id();
				_message = message;
				_output_stream << "Session Id - " << _session_id << "\n"
					<< "Session Name - " << _session_name << "\n"
					<< '\n';
			}
			//_output_stream.flush();

			//map_sessions.insert({ _session_id, _session_name });
		}


		void profiller::stop()
		{
			chrono_time_pt_steady endTime = std::chrono::high_resolution_clock::now();

			long long start = std::chrono::time_point_cast<std::chrono::microseconds>(_start_timepoint).time_since_epoch().count();
			long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTime).time_since_epoch().count();

			auto duration = end - start;
			std::cout << "Operation: " << _message << " - " << duration << " ms" << '\n';
			//_output_stream.flush();
			_stopped = true;
		}

		void profiller::end_session()
		{
			_start_timepoint.time_since_epoch().zero();
			_stopped = true;
		}

		profiller::~profiller()
		{
			if (!_stopped)
			{
				stop();
				end_session();
			}
		}
	}
}