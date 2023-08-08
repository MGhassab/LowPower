// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2019.1 (win64) Build 2552052 Fri May 24 14:49:42 MDT 2019
// Date        : Sun Aug  6 20:10:56 2023
// Host        : DESKTOP-NSCBN50 running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub
//               c:/Users/ESRLab-04/Desktop/vivado/YCbCr/YCbCr.srcs/sources_1/bd/design_1/ip/design_1_Y_0_0/design_1_Y_0_0_stub.v
// Design      : design_1_Y_0_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7s100fgga676-2
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* x_core_info = "Y,Vivado 2019.1" *)
module design_1_Y_0_0(ap_clk, ap_rst, ap_start, ap_done, ap_idle, 
  ap_ready, ap_return, R, G, B)
/* synthesis syn_black_box black_box_pad_pin="ap_clk,ap_rst,ap_start,ap_done,ap_idle,ap_ready,ap_return[7:0],R[7:0],G[7:0],B[7:0]" */;
  input ap_clk;
  input ap_rst;
  input ap_start;
  output ap_done;
  output ap_idle;
  output ap_ready;
  output [7:0]ap_return;
  input [7:0]R;
  input [7:0]G;
  input [7:0]B;
endmodule
