#include "stream_adder.hpp"
#include <ap_int.h>
#include <stdlib.h>
#include <math.h>

#define REG 5
#define N 10


int main(int argc, char** argv) {
	ap_uint<DATALEN/2> a, b;
	ap_uint<DATALEN/2> reg = REG;
	istream input;
	ostream output;

	for (int i = 0; i < N; i++) {
		a = i; // upper 32-bit field
		b = i; // lower 32-bit field

		// create input
		input.data = (a, b); // concatination
		input.last = 0;

		// compute
		stream_adder(&input, &output, reg);

		// print output
		printf("[%d]:\n", i);
		printf("upper 32-bit field: %s\n", a.to_string(10).c_str());
		printf("lower 32-bit field: %s\n", b.to_string(10).c_str());
		printf("reg: %s\n", reg.to_string(10).c_str());
		printf("output: %s\n", output.data.to_string(10).c_str());
	}

	return EXIT_SUCCESS;
}
