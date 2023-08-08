############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project SynthzCb
set_top Cb
add_files Cb.c
add_files Cb.h
add_files -tb CbTest.c
add_files -tb input.h
open_solution "solution1"
set_part {xc7s100fgga676-2} -tool vivado
create_clock -period 10 -name default
#source "./SynthzCb/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -rtl verilog -format ip_catalog
