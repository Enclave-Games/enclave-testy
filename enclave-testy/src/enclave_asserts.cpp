#include "enclave_asserts.h"

namespace enclave_testy
{
	template <typename FirstType, typename SecondType>
	void assert_equals(const FirstType& first, const SecondType& second)
	{
		std::ostringstream string_stream;
		const char* color_txt;
		if (first != second)
		{
			string_stream << __FILE__ << " " << " " << "Line: " << __LINE__ << std::endl;
			string_stream << "Assertion failed: " << first << " != " << second;
			color_txt = "color 4";
		}
		else
		{
			string_stream << "AssertEqual - OK";
			color_txt = "color 2";
		}
		std::cout << string_stream.str() << std::endl;
		system(color_txt);
	}

	template <typename FirstType, typename SecondType>
	void assert_equals(const std::string message, const FirstType& first, const SecondType& second)
	{
		std::ostringstream string_stream;
		const char* color_txt;
		if (first != second)
		{
			string_stream << __FILE__ << " " << " " << "Line: " << __LINE__ << std::endl;
			string_stream << message << first << " != " << second;
			color_txt = "color 4";
		}
		else
		{
			string_stream << "AssertEqual - OK";
			color_txt = "color 2";
		}
		std::cout << string_stream.str() << std::endl;
		system(color_txt);
	}

	template <typename TestFunction>
	void isolate_function_for_test(const TestFunction& _function)
	{
		try
		{
			_function();
			std::cout << "Test success!" << std::endl;
		}
		catch (std::runtime_error& error)
		{
			std:cout << "Fail: " << error.what() << std::endl;
		}
	}
	
	template <typename TestFunction>
	void isolate_function_for_test(const TestFunction& _function, const std::string& test_name)
	{
		try
		{
			_function();
			std::cout << "Test " << test_name << " success!" << std::endl;
		}
		catch (std::runtime_error& error)
		{
			std:cout << test_name << " fail: " << error.what() << std::endl;
		}
	}

	template <typename FirstType, typename SecondType>
	void assert_true(const FirstType& first, const SecondType& second)
	{
		std::ostringstream string_stream;
		const char* color_txt;
		if (first == second)
		{
			string_stream << "AssertTrue - OK";
			color_txt = "color 2";
		}
		else
		{
			string_stream << __FILE__ << " " << " " << "Line: " << __LINE__ << std::endl;
			string_stream << "Assertion failed: " << first << " != " << second;
			color_txt = "color 4";
		}
		std::cout << string_stream.str() << std::endl;
		system(color_txt);
	}
}