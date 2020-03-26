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
		class profiller
		{
		public:
			typedef enum extencion_file
			{
				JSON,
				TXT
			};

			struct profilling_info
			{
				
			};


			profiller() = default;
			explicit profiller(const char* name);
			void stop();
			void begin_session(const std::string _message);
			void begin_session(const std::string message, bool is_console_out);
			void create_and_write_data_to(const std::string filepath, extencion_file& extenction);
			void write_data(const std::string filepath);
			inline uint32_t calculate_session_id();
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

		profiller::profiller(const char* session_name)
			: _session_name(session_name)
		{
			_start_timepoint = std::chrono::high_resolution_clock::now();
		}

		void profiller::create_and_write_data_to(const std::string filepath, extencion_file& file_ext)
		{
			std::string extencion;
			_output_stream.open(filepath, std::ios::in | std::ios::app);

			// TODO!!

			switch (file_ext)
			{
			case JSON:
				extencion = ".json";
				break;

			case TXT:
				extencion = ".txt";
				break;

			default:
				break;
			}

			_output_stream.close();
		}

		uint32_t profiller::calculate_session_id()
		{
			std::random_device rd;
			std::mt19937_64 eng(rd());

			std::uniform_int_distribution<uint32_t> distr;

			uint32_t id = distr(eng);
			return id;
		}


		void profiller::begin_session(const std::string message, bool is_console_out)
		{
			if (is_console_out)
			{
				std::cout << "Session Id - " << calculate_session_id() << "\n"
					<< "Session Name - " << _session_name << "\n"
					<< '\n';
			}
			else
			{
				_output_stream << "Session Id - " << calculate_session_id() << "\n"
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
			std::cout << "Operation: " << this->_session_name << " - " << duration << " ms" << '\n';
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



#endif
