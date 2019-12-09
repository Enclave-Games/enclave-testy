#ifndef ENCLAVE_TESTY
#define ENCLAVE_TESTY

#include <exception>
#include <sstream>
#include <iostream>
#include <Windows.h>
#include <cmath>

namespace enclave_testy
{
	template <typename FirstType, typename SecondType>
	void assert_equals(const FirstType& first, const SecondType& second);
}

#endif