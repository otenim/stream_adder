#include "stream_adder.h"
#include <ap_int.h>

void stream_adder(istream* input, ostream* output, ap_uint<DATALEN> mult) {
#pragma HLS interface axis port=input
#pragma HLS interface axis port=output
#pragma HLS interface s_axilite register port=mult
#pragma HLS interface ap_ctrl_none port=return

	ap_uint<DATALEN> a, b;

	// extract data
	a = input->data.range(DATALEN - 1, DATALEN / 2);
	b = input->data.range(DATALEN / 2 - 1, 0);

	// create output
	output->data = (a + b) * mult;
	output->keep = input->keep;
	output->strb = input->strb;
	output->user = input->user;
	output->last = input->last;
	output->id = input->id;
	output->dest = input->dest;
}
