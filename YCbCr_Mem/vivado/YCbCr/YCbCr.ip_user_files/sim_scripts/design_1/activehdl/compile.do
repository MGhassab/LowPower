vlib work
vlib activehdl

vlib activehdl/xbip_utils_v3_0_10
vlib activehdl/axi_utils_v2_0_6
vlib activehdl/xbip_pipe_v3_0_6
vlib activehdl/xbip_dsp48_wrapper_v3_0_4
vlib activehdl/xbip_dsp48_addsub_v3_0_6
vlib activehdl/xbip_dsp48_multadd_v3_0_6
vlib activehdl/xbip_bram18k_v3_0_6
vlib activehdl/mult_gen_v12_0_15
vlib activehdl/floating_point_v7_1_8
vlib activehdl/xil_defaultlib

vmap xbip_utils_v3_0_10 activehdl/xbip_utils_v3_0_10
vmap axi_utils_v2_0_6 activehdl/axi_utils_v2_0_6
vmap xbip_pipe_v3_0_6 activehdl/xbip_pipe_v3_0_6
vmap xbip_dsp48_wrapper_v3_0_4 activehdl/xbip_dsp48_wrapper_v3_0_4
vmap xbip_dsp48_addsub_v3_0_6 activehdl/xbip_dsp48_addsub_v3_0_6
vmap xbip_dsp48_multadd_v3_0_6 activehdl/xbip_dsp48_multadd_v3_0_6
vmap xbip_bram18k_v3_0_6 activehdl/xbip_bram18k_v3_0_6
vmap mult_gen_v12_0_15 activehdl/mult_gen_v12_0_15
vmap floating_point_v7_1_8 activehdl/floating_point_v7_1_8
vmap xil_defaultlib activehdl/xil_defaultlib

vcom -work xbip_utils_v3_0_10 -93 \
"../../../../YCbCr.srcs/sources_1/bd/design_1/ipshared/1123/hdl/xbip_utils_v3_0_vh_rfs.vhd" \

vcom -work axi_utils_v2_0_6 -93 \
"../../../../YCbCr.srcs/sources_1/bd/design_1/ipshared/1971/hdl/axi_utils_v2_0_vh_rfs.vhd" \

vcom -work xbip_pipe_v3_0_6 -93 \
"../../../../YCbCr.srcs/sources_1/bd/design_1/ipshared/7468/hdl/xbip_pipe_v3_0_vh_rfs.vhd" \

vcom -work xbip_dsp48_wrapper_v3_0_4 -93 \
"../../../../YCbCr.srcs/sources_1/bd/design_1/ipshared/cdbf/hdl/xbip_dsp48_wrapper_v3_0_vh_rfs.vhd" \

vcom -work xbip_dsp48_addsub_v3_0_6 -93 \
"../../../../YCbCr.srcs/sources_1/bd/design_1/ipshared/910d/hdl/xbip_dsp48_addsub_v3_0_vh_rfs.vhd" \

vcom -work xbip_dsp48_multadd_v3_0_6 -93 \
"../../../../YCbCr.srcs/sources_1/bd/design_1/ipshared/b0ac/hdl/xbip_dsp48_multadd_v3_0_vh_rfs.vhd" \

vcom -work xbip_bram18k_v3_0_6 -93 \
"../../../../YCbCr.srcs/sources_1/bd/design_1/ipshared/d367/hdl/xbip_bram18k_v3_0_vh_rfs.vhd" \

vcom -work mult_gen_v12_0_15 -93 \
"../../../../YCbCr.srcs/sources_1/bd/design_1/ipshared/d4d2/hdl/mult_gen_v12_0_vh_rfs.vhd" \

vcom -work floating_point_v7_1_8 -93 \
"../../../../YCbCr.srcs/sources_1/bd/design_1/ipshared/83a3/hdl/floating_point_v7_1_vh_rfs.vhd" \

vcom -work xil_defaultlib -93 \
"../../../../YCbCr.srcs/sources_1/bd/design_1/ipshared/55f7/hdl/vhdl/Y_dadd_64ns_64ns_bkb.vhd" \
"../../../../YCbCr.srcs/sources_1/bd/design_1/ipshared/55f7/hdl/vhdl/Y_dmul_64ns_64ns_cud.vhd" \
"../../../../YCbCr.srcs/sources_1/bd/design_1/ipshared/55f7/hdl/vhdl/Y_sitodp_32ns_64_dEe.vhd" \
"../../../../YCbCr.srcs/sources_1/bd/design_1/ipshared/55f7/hdl/vhdl/Y.vhd" \
"../../../../YCbCr.srcs/sources_1/bd/design_1/ipshared/55f7/hdl/ip/Y_ap_dadd_3_no_dsp_64.vhd" \
"../../../../YCbCr.srcs/sources_1/bd/design_1/ipshared/55f7/hdl/ip/Y_ap_dmul_3_max_dsp_64.vhd" \
"../../../../YCbCr.srcs/sources_1/bd/design_1/ipshared/55f7/hdl/ip/Y_ap_sitodp_3_no_dsp_32.vhd" \
"../../../bd/design_1/ip/design_1_Y_0_0/sim/design_1_Y_0_0.vhd" \
"../../../../YCbCr.srcs/sources_1/bd/design_1/ipshared/b642/hdl/vhdl/Cb_dadddsub_64ns_bkb.vhd" \
"../../../../YCbCr.srcs/sources_1/bd/design_1/ipshared/b642/hdl/vhdl/Cb_dmul_64ns_64nscud.vhd" \
"../../../../YCbCr.srcs/sources_1/bd/design_1/ipshared/b642/hdl/vhdl/Cb_sitodp_32ns_64dEe.vhd" \
"../../../../YCbCr.srcs/sources_1/bd/design_1/ipshared/b642/hdl/vhdl/Cb.vhd" \
"../../../../YCbCr.srcs/sources_1/bd/design_1/ipshared/b642/hdl/ip/Cb_ap_dadddsub_3_no_dsp_64.vhd" \
"../../../../YCbCr.srcs/sources_1/bd/design_1/ipshared/b642/hdl/ip/Cb_ap_dmul_3_max_dsp_64.vhd" \
"../../../../YCbCr.srcs/sources_1/bd/design_1/ipshared/b642/hdl/ip/Cb_ap_sitodp_3_no_dsp_32.vhd" \
"../../../bd/design_1/ip/design_1_Cb_0_0/sim/design_1_Cb_0_0.vhd" \
"../../../../YCbCr.srcs/sources_1/bd/design_1/ipshared/402e/hdl/vhdl/Cr_dadddsub_64ns_bkb.vhd" \
"../../../../YCbCr.srcs/sources_1/bd/design_1/ipshared/402e/hdl/vhdl/Cr_dmul_64ns_64nscud.vhd" \
"../../../../YCbCr.srcs/sources_1/bd/design_1/ipshared/402e/hdl/vhdl/Cr_sitodp_32ns_64dEe.vhd" \
"../../../../YCbCr.srcs/sources_1/bd/design_1/ipshared/402e/hdl/vhdl/Cr.vhd" \
"../../../../YCbCr.srcs/sources_1/bd/design_1/ipshared/402e/hdl/ip/Cr_ap_dadddsub_3_no_dsp_64.vhd" \
"../../../../YCbCr.srcs/sources_1/bd/design_1/ipshared/402e/hdl/ip/Cr_ap_dmul_3_max_dsp_64.vhd" \
"../../../../YCbCr.srcs/sources_1/bd/design_1/ipshared/402e/hdl/ip/Cr_ap_sitodp_3_no_dsp_32.vhd" \
"../../../bd/design_1/ip/design_1_Cr_0_0/sim/design_1_Cr_0_0.vhd" \
"../../../bd/design_1/sim/design_1.vhd" \

