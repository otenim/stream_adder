open_project stream_adder
set_top stream_adder
add_files stream_adder/stream_adder.hpp
add_files stream_adder/stream_adder.cpp
add_files -tb stream_adder/test.cpp -cflags "-Wno-unknown-pragmas"
open_solution "solution1"
set_part {xc7z020clg400-1}
create_clock -period 10 -name default
config_export -format ip_catalog -rtl verilog
