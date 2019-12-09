#ifndef ENCLAVE_TESTY
#define ENCLAVE_TESTY

#include <exception>
#include <sstream>
#include <iostream>
#include <Windows.h>
#include <cmath>

namespace enclave_testy
{
	class TestWrapper
	{
	public:
		template <typename FirstType, typename SecondType>
		void assert_equals(const FirstType& first, const SecondType& second);

		template <typename FirstType, typename SecondType>
		void assert_equals(const std::string message, const FirstType& first, const SecondType& second);

		template <typename TestFunction>
		void isolate_function_for_test(const TestFunction& _function);

		template <typename TestFunction>
		void isolate_function_for_test(const TestFunction& _function, const std::string& test_name);

		template <typename FirstType, typename SecondType>
		void assert_true(const FirstType& first, const SecondType& second);

		virtual ~TestWrapper();
	private:
		int fail_count = 0;
	};
	
}

#endif