#ifndef ENCLAVE_TESTY
#define ENCLAVE_TESTY

#include <exception>
#include <sstream>
#include <iostream>
#include <Windows.h>
#include <cmath>

namespace testy
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

		~TestWrapper()
		{
			if (fail_count > 0)
			{
				std::cerr << fail_count << " test failed!" << std::endl;
				exit(1);
			}
		}
	private:
		int fail_count = 0;
		std::ostringstream string_stream;
		const char* color;
	};

	template <typename FirstType, typename SecondType>
	void TestWrapper::assert_equals(const FirstType& first, const SecondType& second)
	{
		if (first != second)
		{
			string_stream << __FILE__ << " " << " " << "Line: " << __LINE__ << std::endl;
			string_stream << "Assertion failed: " << first << " != " << second;
			color = "color 4";
			++fail_count;
		}
		else
		{
			string_stream << "AssertEqual - OK";
			color = "color 2";
		}
		std::cout << string_stream.str() << std::endl;
		system(color);
	}

	template <typename FirstType, typename SecondType>
	void TestWrapper::assert_equals(const std::string message, const FirstType& first, const SecondType& second)
	{
		if (first != second)
		{
			string_stream << __FILE__ << " " << " " << "Line: " << __LINE__ << std::endl;
			string_stream << message << first << " != " << second;
			color = "color 4";
			++fail_count;
		}
		else
		{
			string_stream << "AssertEqual - OK";
			color = "color 2";
		}
		std::cout << string_stream.str() << std::endl;
		system(color);
	}

	template <typename TestFunction>
	void TestWrapper::isolate_function_for_test(const TestFunction& _function)
	{
		try
		{
			_function();
			std::cout << "Test success!" << std::endl;
		}
		catch (std::runtime_error& error)
		{
			std::cout << "Fail: " << error.what() << std::endl;
			++fail_count;
		}
	}

	template <typename TestFunction>
	void TestWrapper::isolate_function_for_test(const TestFunction& _function, const std::string& test_name)
	{
		try
		{
			_function();
			std::cout << "Test " << test_name << " success!" << std::endl;
		}
		catch (std::runtime_error& error)
		{
			std::cout << test_name << " FAIL: " << error.what() << std::endl;
			++fail_count;
		}
	}

	template <typename FirstType, typename SecondType>
	void TestWrapper::assert_true(const FirstType& first, const SecondType& second)
	{
		if (first == second)
		{
			string_stream << "AssertTrue - OK";
			color = "color 2";
		}
		else
		{
			string_stream << "Source: " << __FILE__ << " " << "Line: " << __LINE__ << std::endl;
			string_stream << "Assertion failed: " << first << " != " << second;
			++fail_count;
			color = "color 4";
		}
		std::cerr << string_stream.str() << std::endl;
		system(color);
	}
	
}

#endif