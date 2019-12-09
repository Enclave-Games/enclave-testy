#include "enclave_asserts.h"

namespace enclave_testy
{
	template <typename FirstType, typename SecondType>
	void TestWrapper::assert_equals(const FirstType& first, const SecondType& second)
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
	void TestWrapper::assert_equals(const std::string message, const FirstType& first, const SecondType& second)
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
			std::cout << test_name << " fail: " << error.what() << std::endl;
			++fail_count;
		}
	}

	template <typename FirstType, typename SecondType>
	void TestWrapper::assert_true(const FirstType& first, const SecondType& second)
	{
		std::ostringstream string_stream;
		const char* color;
		if (first == second)
		{
			string_stream << "AssertTrue - OK";
			color = "color 2";
		}
		else
		{
			string_stream << __FILE__ << std::endl;
			string_stream << "Assertion failed: " << first << " != " << second << " " << "Line: " << __LINE__ << second;
			++fail_count;
			color = "color 4";
		}
		std::cerr << string_stream.str() << std::endl;
		system(color);
	}

	TestWrapper::~TestWrapper()
	{
		if (fail_count > 0)
		{
			std::cerr << fail_count << "test failed!" << std::endl;
			exit(1);
		}
	}
}