#ifndef __STREAM_ADDER_H__
#define __STREAM_ADDER_H__

#include <ap_int.h>
#include <ap_axi_sdata.h>

#define DATALEN 64
#define USERLEN 1
#define IDLEN 1
#define DESTLEN 1

typedef ap_axiu<DATALEN, USERLEN, IDLEN, DESTLEN> istream;
typedef ap_axiu<DATALEN, USERLEN, IDLEN, DESTLEN> ostream;

void stream_adder(istream* input, ostream* output, ap_uint<DATALEN/2> mult);
#endif
