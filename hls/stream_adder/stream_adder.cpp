#include "stream_adder.hpp"
#include <ap_int.h>

void stream_adder(istream* input, ostream* output, ap_uint<DATALEN/2> reg) {
#pragma HLS interface axis port=input
#pragma HLS interface axis port=output
#pragma HLS interface s_axilite register port=reg
#pragma HLS interface ap_ctrl_none port=return

	ap_uint<DATALEN/2> a, b;

	// extract data
	a = input->data.range(DATALEN - 1, DATALEN / 2);
	b = input->data.range(DATALEN / 2 - 1, 0);

	// create output
	output->data = (a + b) * reg;
	output->last = input->last;
}
