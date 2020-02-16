#include "stream_adder.hpp"
#include <ap_int.h>
#include <stdlib.h>
#include <math.h>
#define MAXIMUM 1000
#define N 10

void create_istream(istream* input, ap_uint<DATALEN> data) {
	input->data = data;
	input->last = 0;
}

int main(int argc, char** argv) {
	ap_uint<DATALEN> data;
	ap_uint<DATALEN/2> a, b, reg;
	istream input;
	ostream output;

	for (int i = 0; i < N; i++) {
		a = rand() % MAXIMUM; // 0 ~ (MAXIMUM - 1)
		b = rand() % MAXIMUM;
		reg = rand() % MAXIMUM;
		data = (a, b);
		create_istream(&input, data);
		stream_adder(&input, &output, reg);
		printf("[%d]:\n", i);
		printf("\t a = %s(%s)\n",
				a.to_string(16).c_str(),
				a.to_string(10).c_str());
		printf("\t b = %s(%s)\n",
				b.to_string(16).c_str(),
				b.to_string(10).c_str());
		printf("\t reg = %s(%s)\n",
				reg.to_string(16).c_str(),
				reg.to_string(10).c_str());
		printf("\t [input] data = %s\n",
				data.to_string(16).c_str());
		printf("\t [output] data = %s(%s)\n",
				output.data.to_string(16).c_str(),
				output.data.to_string(10).c_str());
	}

	return EXIT_SUCCESS;
}
