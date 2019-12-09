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


	//TODO
	/*template <typename FirstType, typename SecondType>
	bool assert_false(const FirstType& first, const SecondType& second)
	{
		return false;
	}


	template <typename FirstType, typename SecondType>
	bool assert_true(const FirstType& first, const SecondType& second)
	{
		return true;
	}*/
}