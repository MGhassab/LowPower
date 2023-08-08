############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project edgeDetecion
set_top sobel_filter
add_files sobel.c
add_files sobel.h
add_files -tb input.h
add_files -tb output.h
add_files -tb sobelTest.c
open_solution "solution1"
set_part {xc7s100fgga676-2} -tool vivado
create_clock -period 10 -name default
#source "./edgeDetecion/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -rtl verilog -format ip_catalog
