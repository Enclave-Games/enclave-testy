#include "enclave_asserts.cpp"

int main()
{
	enclave_testy::assert_equals(5 + 1, 1);
	return 0;
}