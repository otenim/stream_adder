#include "stream_adder.hpp"
#include <ap_int.h>

void stream_adder(istream* input, ostream* output, ap_uint<DATALEN/2> reg) {
#pragma HLS interface axis port=input
#pragma HLS interface axis port=output
#pragma HLS interface s_axilite register port=reg
#pragma HLS interface ap_ctrl_none port=return

	ap_uint<DATALEN/2> a, b, c;

	// extract data
	a = input->data.range(DATALEN - 1, DATALEN / 2); // upper 32 bits
	b = input->data.range(DATALEN / 2 - 1, 0); // lower 32 bit

	// add & multiply
	c = (a + b) * reg;

	// create output data
	output->data = c;
	output->last = input->last;
}
