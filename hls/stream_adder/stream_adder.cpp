#include "stream_adder.h"
#include <ap_int.h>

void stream_adder(istream* idata, ostream* odata) {
#pragma HLS interface axis port=idata
#pragma HLS interface axis port=odata
#pragma HLS interface ap_ctrl_none port=return

	ap_uint<DATALEN> data;
	ap_uint<DATALEN/2> a, b;

	// extract data
	data = idata->data;
	a = data.range(DATALEN - 1, DATALEN/2);
	b = data.range(DATALEN/2 - 1, 0);

	// create output stream
	odata->data = a + b;
	odata->keep = idata->keep;
	odata->strb = idata->strb;
	odata->user = idata->user;
	odata->last = idata->last;
	odata->id = idata->id;
	odata->dest = idata->dest;
}
