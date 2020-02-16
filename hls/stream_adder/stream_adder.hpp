#ifndef __STREAM_ADDER_H__
#define __STREAM_ADDER_H__

#include <ap_int.h>

#define DATALEN 64

typedef struct input_stream {
    ap_uint<DATALEN> data;
    ap_uint<1> last;
} istream;

typedef struct output_stream {
    ap_uint<DATALEN> data;
    ap_uint<1> last;
} ostream;

void stream_adder(istream* input, ostream* output, ap_uint<DATALEN/2> reg);
#endif
