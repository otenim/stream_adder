#include "stream_adder.h"
#include <ap_int.h>
#include <stdlib.h>
#include <math.h>
#define MAXIMUM 1000
#define N 10

void create_istream(istream* idata, ap_uint<DATALEN> data) {
	idata->data = data;
	idata->keep = 0;
	idata->strb = 0;
	idata->user = 0;
	idata->last = 0;
	idata->id = 0;
	idata->dest = 0;
}

int main(int argc, char** argv) {
	ap_uint<DATALEN> data;
	ap_uint<DATALEN/2> a, b;
	istream idata;
	ostream odata;

	for (int i = 0; i < N; i++) {
		a = rand() % MAXIMUM; // 0 ~ (MAXIMUM - 1)
		b = rand() % MAXIMUM;
		data = (a, b);
		create_istream(&idata, data);
		stream_adder(&idata, &odata);
		printf("[%d]:\n", i);
		printf("\t a = %s(%s)\n",
				a.to_string(16).c_str(),
				a.to_string(10).c_str());
		printf("\t b = %s(%s)\n",
				b.to_string(16).c_str(),
				b.to_string(10).c_str());
		printf("\t [input] data = %s(%s)\n",
				data.to_string(16).c_str(),
				data.to_string(10).c_str());
		printf("\t [output] data = %s(%s)\n",
				odata.data.to_string(16).c_str(),
				odata.data.to_string(10).c_str());
	}

	return EXIT_SUCCESS;
}
