#ifndef __STREAM_ADDER_H__
#define __STREAM_ADDER_H__

#include <ap_int.h>
#include <ap_axi_sdata.h>

#define DATALEN 64
#define USERLEN 1
#define IDLEN 1
#define DESTLEN 1

typedef struct istream {
	ap_uint<DATALEN> data;
	ap_uint<DATALEN/8> keep;
	ap_uint<DATALEN/8> strb;
	ap_uint<USERLEN> user;
	ap_uint<1> last;
	ap_uint<IDLEN> id;
	ap_uint<DESTLEN> dest;
} istream;

typedef struct ostream {
	ap_uint<DATALEN> data;
	ap_uint<DATALEN/8> keep;
	ap_uint<DATALEN/8> strb;
	ap_uint<USERLEN> user;
	ap_uint<1> last;
	ap_uint<IDLEN> id;
	ap_uint<DESTLEN> dest;
} ostream;

void stream_adder(istream* idata, ostream* odata);
#endif
