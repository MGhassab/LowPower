#include "hls_design_meta.h"
const Port_Property HLS_Design_Meta::port_props[]={
	Port_Property("ap_clk", 1, hls_in, -1, "", "", 1),
	Port_Property("ap_rst", 1, hls_in, -1, "", "", 1),
	Port_Property("ap_start", 1, hls_in, -1, "", "", 1),
	Port_Property("ap_done", 1, hls_out, -1, "", "", 1),
	Port_Property("ap_idle", 1, hls_out, -1, "", "", 1),
	Port_Property("ap_ready", 1, hls_out, -1, "", "", 1),
	Port_Property("in_r_address0", 18, hls_out, 0, "ap_memory", "mem_address", 1),
	Port_Property("in_r_ce0", 1, hls_out, 0, "ap_memory", "mem_ce", 1),
	Port_Property("in_r_q0", 8, hls_in, 0, "ap_memory", "mem_dout", 1),
	Port_Property("in_r_address1", 18, hls_out, 0, "ap_memory", "MemPortADDR2", 1),
	Port_Property("in_r_ce1", 1, hls_out, 0, "ap_memory", "MemPortCE2", 1),
	Port_Property("in_r_q1", 8, hls_in, 0, "ap_memory", "MemPortDOUT2", 1),
	Port_Property("out_r_address0", 18, hls_out, 1, "ap_memory", "mem_address", 1),
	Port_Property("out_r_ce0", 1, hls_out, 1, "ap_memory", "mem_ce", 1),
	Port_Property("out_r_we0", 1, hls_out, 1, "ap_memory", "mem_we", 1),
	Port_Property("out_r_d0", 8, hls_out, 1, "ap_memory", "mem_din", 1),
};
const char* HLS_Design_Meta::dut_name = "sobel_filter";
