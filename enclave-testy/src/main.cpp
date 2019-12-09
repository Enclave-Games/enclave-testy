#include "enclave_asserts.cpp"

int main()
{
	enclave_testy::TestWrapper test;
	test.assert_true(5, 1);
	return 0;
}