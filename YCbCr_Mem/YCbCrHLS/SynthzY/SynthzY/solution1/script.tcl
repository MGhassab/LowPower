############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project SynthzY
set_top Y
add_files Y.c
add_files Y.h
add_files -tb YTest.c
add_files -tb input.h
open_solution "solution1"
set_part {xc7s100fgga676-2} -tool vivado
create_clock -period 10 -name default
#source "./SynthzY/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -rtl verilog -format ip_catalog
