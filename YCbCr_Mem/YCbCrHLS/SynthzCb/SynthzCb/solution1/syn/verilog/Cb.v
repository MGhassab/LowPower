// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2019.1
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

(* CORE_GENERATION_INFO="Cb,hls_ip_2019_1,{HLS_INPUT_TYPE=c,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xc7s100-fgga676-2,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=8.567000,HLS_SYN_LAT=26,HLS_SYN_TPT=none,HLS_SYN_MEM=0,HLS_SYN_DSP=25,HLS_SYN_FF=2140,HLS_SYN_LUT=2977,HLS_VERSION=2019_1}" *)

module Cb (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        R,
        G,
        B,
        ap_return
);

parameter    ap_ST_fsm_state1 = 27'd1;
parameter    ap_ST_fsm_state2 = 27'd2;
parameter    ap_ST_fsm_state3 = 27'd4;
parameter    ap_ST_fsm_state4 = 27'd8;
parameter    ap_ST_fsm_state5 = 27'd16;
parameter    ap_ST_fsm_state6 = 27'd32;
parameter    ap_ST_fsm_state7 = 27'd64;
parameter    ap_ST_fsm_state8 = 27'd128;
parameter    ap_ST_fsm_state9 = 27'd256;
parameter    ap_ST_fsm_state10 = 27'd512;
parameter    ap_ST_fsm_state11 = 27'd1024;
parameter    ap_ST_fsm_state12 = 27'd2048;
parameter    ap_ST_fsm_state13 = 27'd4096;
parameter    ap_ST_fsm_state14 = 27'd8192;
parameter    ap_ST_fsm_state15 = 27'd16384;
parameter    ap_ST_fsm_state16 = 27'd32768;
parameter    ap_ST_fsm_state17 = 27'd65536;
parameter    ap_ST_fsm_state18 = 27'd131072;
parameter    ap_ST_fsm_state19 = 27'd262144;
parameter    ap_ST_fsm_state20 = 27'd524288;
parameter    ap_ST_fsm_state21 = 27'd1048576;
parameter    ap_ST_fsm_state22 = 27'd2097152;
parameter    ap_ST_fsm_state23 = 27'd4194304;
parameter    ap_ST_fsm_state24 = 27'd8388608;
parameter    ap_ST_fsm_state25 = 27'd16777216;
parameter    ap_ST_fsm_state26 = 27'd33554432;
parameter    ap_ST_fsm_state27 = 27'd67108864;

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
input  [7:0] R;
input  [7:0] G;
input  [7:0] B;
output  [7:0] ap_return;

reg ap_done;
reg ap_idle;
reg ap_ready;

(* fsm_encoding = "none" *) reg   [26:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
wire   [63:0] grp_fu_100_p1;
reg   [63:0] reg_106;
wire    ap_CS_fsm_state6;
reg   [0:0] and_ln10_4_reg_341;
wire    ap_CS_fsm_state11;
wire   [63:0] grp_fu_89_p2;
reg   [63:0] reg_111;
wire    ap_CS_fsm_state16;
wire   [63:0] grp_fu_84_p2;
reg   [63:0] reg_117;
wire    ap_CS_fsm_state21;
wire   [0:0] and_ln10_4_fu_182_p2;
wire   [31:0] zext_ln16_fu_188_p1;
wire    ap_CS_fsm_state2;
wire   [63:0] grp_fu_103_p1;
reg   [63:0] tmp_4_reg_356;
wire   [31:0] zext_ln16_2_fu_196_p1;
wire    ap_CS_fsm_state7;
wire   [63:0] grp_fu_94_p2;
reg   [63:0] tmp_5_reg_366;
reg   [10:0] tmp_V_reg_371;
wire    ap_CS_fsm_state26;
wire   [51:0] tmp_V_1_fu_214_p1;
reg   [51:0] tmp_V_1_reg_377;
reg   [63:0] grp_fu_84_p0;
reg   [63:0] grp_fu_84_p1;
wire    ap_CS_fsm_state12;
wire    ap_CS_fsm_state17;
wire    ap_CS_fsm_state22;
reg   [63:0] grp_fu_89_p1;
reg   [31:0] grp_fu_100_p0;
wire   [31:0] grp_fu_103_p0;
wire   [0:0] icmp_ln10_1_fu_128_p2;
wire   [0:0] icmp_ln10_2_fu_134_p2;
wire   [0:0] and_ln10_fu_158_p2;
wire   [0:0] icmp_ln10_fu_122_p2;
wire   [0:0] icmp_ln10_4_fu_146_p2;
wire   [0:0] icmp_ln10_5_fu_152_p2;
wire   [0:0] and_ln10_2_fu_170_p2;
wire   [0:0] icmp_ln10_3_fu_140_p2;
wire   [0:0] and_ln10_3_fu_176_p2;
wire   [0:0] and_ln10_1_fu_164_p2;
wire   [63:0] p_Val2_s_fu_200_p1;
wire    ap_CS_fsm_state27;
wire   [53:0] mantissa_V_fu_218_p4;
wire   [11:0] zext_ln502_fu_231_p1;
wire   [11:0] add_ln502_fu_234_p2;
wire   [10:0] sub_ln1311_fu_248_p2;
wire   [0:0] isNeg_fu_240_p3;
wire  signed [11:0] sext_ln1311_fu_253_p1;
wire   [11:0] ush_fu_257_p3;
wire  signed [31:0] sext_ln1311_1_fu_265_p1;
wire   [53:0] zext_ln1285_fu_273_p1;
wire   [112:0] zext_ln682_fu_227_p1;
wire   [112:0] zext_ln1287_fu_269_p1;
wire   [53:0] r_V_fu_277_p2;
wire   [0:0] tmp_10_fu_289_p3;
wire   [112:0] r_V_1_fu_283_p2;
wire   [7:0] zext_ln662_fu_297_p1;
wire   [7:0] tmp_2_fu_301_p4;
wire   [7:0] val_V_fu_311_p3;
reg   [1:0] grp_fu_84_opcode;
reg   [26:0] ap_NS_fsm;

// power-on initialization
initial begin
#0 ap_CS_fsm = 27'd1;
end

Cb_dadddsub_64ns_bkb #(
    .ID( 1 ),
    .NUM_STAGE( 5 ),
    .din0_WIDTH( 64 ),
    .din1_WIDTH( 64 ),
    .dout_WIDTH( 64 ))
Cb_dadddsub_64ns_bkb_U1(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(grp_fu_84_p0),
    .din1(grp_fu_84_p1),
    .opcode(grp_fu_84_opcode),
    .ce(1'b1),
    .dout(grp_fu_84_p2)
);

Cb_dmul_64ns_64nscud #(
    .ID( 1 ),
    .NUM_STAGE( 5 ),
    .din0_WIDTH( 64 ),
    .din1_WIDTH( 64 ),
    .dout_WIDTH( 64 ))
Cb_dmul_64ns_64nscud_U2(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(reg_106),
    .din1(grp_fu_89_p1),
    .ce(1'b1),
    .dout(grp_fu_89_p2)
);

Cb_dmul_64ns_64nscud #(
    .ID( 1 ),
    .NUM_STAGE( 5 ),
    .din0_WIDTH( 64 ),
    .din1_WIDTH( 64 ),
    .dout_WIDTH( 64 ))
Cb_dmul_64ns_64nscud_U3(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(tmp_4_reg_356),
    .din1(64'd4598913809884165177),
    .ce(1'b1),
    .dout(grp_fu_94_p2)
);

Cb_sitodp_32ns_64dEe #(
    .ID( 1 ),
    .NUM_STAGE( 5 ),
    .din0_WIDTH( 32 ),
    .dout_WIDTH( 64 ))
Cb_sitodp_32ns_64dEe_U4(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(grp_fu_100_p0),
    .ce(1'b1),
    .dout(grp_fu_100_p1)
);

Cb_sitodp_32ns_64dEe #(
    .ID( 1 ),
    .NUM_STAGE( 5 ),
    .din0_WIDTH( 32 ),
    .dout_WIDTH( 64 ))
Cb_sitodp_32ns_64dEe_U5(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(grp_fu_103_p0),
    .ce(1'b1),
    .dout(grp_fu_103_p1)
);

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if (((ap_start == 1'b1) & (1'b1 == ap_CS_fsm_state1))) begin
        and_ln10_4_reg_341 <= and_ln10_4_fu_182_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((((1'd0 == and_ln10_4_reg_341) & (1'b1 == ap_CS_fsm_state11)) | ((1'd0 == and_ln10_4_reg_341) & (1'b1 == ap_CS_fsm_state6)))) begin
        reg_106 <= grp_fu_100_p1;
    end
end

always @ (posedge ap_clk) begin
    if ((((1'd0 == and_ln10_4_reg_341) & (1'b1 == ap_CS_fsm_state16)) | ((1'd0 == and_ln10_4_reg_341) & (1'b1 == ap_CS_fsm_state11)))) begin
        reg_111 <= grp_fu_89_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((((1'd0 == and_ln10_4_reg_341) & (1'b1 == ap_CS_fsm_state21)) | ((1'd0 == and_ln10_4_reg_341) & (1'b1 == ap_CS_fsm_state16)))) begin
        reg_117 <= grp_fu_84_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((1'd0 == and_ln10_4_reg_341) & (1'b1 == ap_CS_fsm_state6))) begin
        tmp_4_reg_356 <= grp_fu_103_p1;
    end
end

always @ (posedge ap_clk) begin
    if (((1'd0 == and_ln10_4_reg_341) & (1'b1 == ap_CS_fsm_state11))) begin
        tmp_5_reg_366 <= grp_fu_94_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((1'd0 == and_ln10_4_reg_341) & (1'b1 == ap_CS_fsm_state26))) begin
        tmp_V_1_reg_377 <= tmp_V_1_fu_214_p1;
        tmp_V_reg_371 <= {{p_Val2_s_fu_200_p1[62:52]}};
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state27)) begin
        ap_done = 1'b1;
    end else begin
        ap_done = 1'b0;
    end
end

always @ (*) begin
    if (((ap_start == 1'b0) & (1'b1 == ap_CS_fsm_state1))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state27)) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state7)) begin
        grp_fu_100_p0 = zext_ln16_2_fu_196_p1;
    end else if ((1'b1 == ap_CS_fsm_state2)) begin
        grp_fu_100_p0 = zext_ln16_fu_188_p1;
    end else begin
        grp_fu_100_p0 = 'bx;
    end
end

always @ (*) begin
    if (((1'd0 == and_ln10_4_reg_341) & (1'b1 == ap_CS_fsm_state12))) begin
        grp_fu_84_opcode = 2'd1;
    end else if ((((1'd0 == and_ln10_4_reg_341) & (1'b1 == ap_CS_fsm_state22)) | ((1'd0 == and_ln10_4_reg_341) & (1'b1 == ap_CS_fsm_state17)))) begin
        grp_fu_84_opcode = 2'd0;
    end else begin
        grp_fu_84_opcode = 'bx;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state22) | (1'b1 == ap_CS_fsm_state17))) begin
        grp_fu_84_p0 = reg_117;
    end else if ((1'b1 == ap_CS_fsm_state12)) begin
        grp_fu_84_p0 = reg_111;
    end else begin
        grp_fu_84_p0 = 'bx;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state22)) begin
        grp_fu_84_p1 = 64'd4638707616191610880;
    end else if ((1'b1 == ap_CS_fsm_state17)) begin
        grp_fu_84_p1 = reg_111;
    end else if ((1'b1 == ap_CS_fsm_state12)) begin
        grp_fu_84_p1 = tmp_5_reg_366;
    end else begin
        grp_fu_84_p1 = 'bx;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state12)) begin
        grp_fu_89_p1 = 64'd4601579940863568511;
    end else if ((1'b1 == ap_CS_fsm_state7)) begin
        grp_fu_89_p1 = 64'd13817872319104117899;
    end else begin
        grp_fu_89_p1 = 'bx;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_state1 : begin
            if (((ap_start == 1'b1) & (1'b1 == ap_CS_fsm_state1))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end
        end
        ap_ST_fsm_state2 : begin
            ap_NS_fsm = ap_ST_fsm_state3;
        end
        ap_ST_fsm_state3 : begin
            ap_NS_fsm = ap_ST_fsm_state4;
        end
        ap_ST_fsm_state4 : begin
            ap_NS_fsm = ap_ST_fsm_state5;
        end
        ap_ST_fsm_state5 : begin
            ap_NS_fsm = ap_ST_fsm_state6;
        end
        ap_ST_fsm_state6 : begin
            ap_NS_fsm = ap_ST_fsm_state7;
        end
        ap_ST_fsm_state7 : begin
            ap_NS_fsm = ap_ST_fsm_state8;
        end
        ap_ST_fsm_state8 : begin
            ap_NS_fsm = ap_ST_fsm_state9;
        end
        ap_ST_fsm_state9 : begin
            ap_NS_fsm = ap_ST_fsm_state10;
        end
        ap_ST_fsm_state10 : begin
            ap_NS_fsm = ap_ST_fsm_state11;
        end
        ap_ST_fsm_state11 : begin
            ap_NS_fsm = ap_ST_fsm_state12;
        end
        ap_ST_fsm_state12 : begin
            ap_NS_fsm = ap_ST_fsm_state13;
        end
        ap_ST_fsm_state13 : begin
            ap_NS_fsm = ap_ST_fsm_state14;
        end
        ap_ST_fsm_state14 : begin
            ap_NS_fsm = ap_ST_fsm_state15;
        end
        ap_ST_fsm_state15 : begin
            ap_NS_fsm = ap_ST_fsm_state16;
        end
        ap_ST_fsm_state16 : begin
            ap_NS_fsm = ap_ST_fsm_state17;
        end
        ap_ST_fsm_state17 : begin
            ap_NS_fsm = ap_ST_fsm_state18;
        end
        ap_ST_fsm_state18 : begin
            ap_NS_fsm = ap_ST_fsm_state19;
        end
        ap_ST_fsm_state19 : begin
            ap_NS_fsm = ap_ST_fsm_state20;
        end
        ap_ST_fsm_state20 : begin
            ap_NS_fsm = ap_ST_fsm_state21;
        end
        ap_ST_fsm_state21 : begin
            ap_NS_fsm = ap_ST_fsm_state22;
        end
        ap_ST_fsm_state22 : begin
            ap_NS_fsm = ap_ST_fsm_state23;
        end
        ap_ST_fsm_state23 : begin
            ap_NS_fsm = ap_ST_fsm_state24;
        end
        ap_ST_fsm_state24 : begin
            ap_NS_fsm = ap_ST_fsm_state25;
        end
        ap_ST_fsm_state25 : begin
            ap_NS_fsm = ap_ST_fsm_state26;
        end
        ap_ST_fsm_state26 : begin
            ap_NS_fsm = ap_ST_fsm_state27;
        end
        ap_ST_fsm_state27 : begin
            ap_NS_fsm = ap_ST_fsm_state1;
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign add_ln502_fu_234_p2 = ($signed(12'd3073) + $signed(zext_ln502_fu_231_p1));

assign and_ln10_1_fu_164_p2 = (icmp_ln10_fu_122_p2 & and_ln10_fu_158_p2);

assign and_ln10_2_fu_170_p2 = (icmp_ln10_5_fu_152_p2 & icmp_ln10_4_fu_146_p2);

assign and_ln10_3_fu_176_p2 = (icmp_ln10_3_fu_140_p2 & and_ln10_2_fu_170_p2);

assign and_ln10_4_fu_182_p2 = (and_ln10_3_fu_176_p2 & and_ln10_1_fu_164_p2);

assign and_ln10_fu_158_p2 = (icmp_ln10_2_fu_134_p2 & icmp_ln10_1_fu_128_p2);

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state11 = ap_CS_fsm[32'd10];

assign ap_CS_fsm_state12 = ap_CS_fsm[32'd11];

assign ap_CS_fsm_state16 = ap_CS_fsm[32'd15];

assign ap_CS_fsm_state17 = ap_CS_fsm[32'd16];

assign ap_CS_fsm_state2 = ap_CS_fsm[32'd1];

assign ap_CS_fsm_state21 = ap_CS_fsm[32'd20];

assign ap_CS_fsm_state22 = ap_CS_fsm[32'd21];

assign ap_CS_fsm_state26 = ap_CS_fsm[32'd25];

assign ap_CS_fsm_state27 = ap_CS_fsm[32'd26];

assign ap_CS_fsm_state6 = ap_CS_fsm[32'd5];

assign ap_CS_fsm_state7 = ap_CS_fsm[32'd6];

assign ap_return = ((and_ln10_4_reg_341[0:0] === 1'b1) ? 8'd133 : val_V_fu_311_p3);

assign grp_fu_103_p0 = G;

assign icmp_ln10_1_fu_128_p2 = ((R > 8'd26) ? 1'b1 : 1'b0);

assign icmp_ln10_2_fu_134_p2 = ((G < 8'd76) ? 1'b1 : 1'b0);

assign icmp_ln10_3_fu_140_p2 = ((G > 8'd36) ? 1'b1 : 1'b0);

assign icmp_ln10_4_fu_146_p2 = ((B < 8'd85) ? 1'b1 : 1'b0);

assign icmp_ln10_5_fu_152_p2 = ((B > 8'd45) ? 1'b1 : 1'b0);

assign icmp_ln10_fu_122_p2 = ((R < 8'd66) ? 1'b1 : 1'b0);

assign isNeg_fu_240_p3 = add_ln502_fu_234_p2[32'd11];

assign mantissa_V_fu_218_p4 = {{{{1'd1}, {tmp_V_1_reg_377}}}, {1'd0}};

assign p_Val2_s_fu_200_p1 = grp_fu_84_p2;

assign r_V_1_fu_283_p2 = zext_ln682_fu_227_p1 << zext_ln1287_fu_269_p1;

assign r_V_fu_277_p2 = mantissa_V_fu_218_p4 >> zext_ln1285_fu_273_p1;

assign sext_ln1311_1_fu_265_p1 = $signed(ush_fu_257_p3);

assign sext_ln1311_fu_253_p1 = $signed(sub_ln1311_fu_248_p2);

assign sub_ln1311_fu_248_p2 = (11'd1023 - tmp_V_reg_371);

assign tmp_10_fu_289_p3 = r_V_fu_277_p2[32'd53];

assign tmp_2_fu_301_p4 = {{r_V_1_fu_283_p2[60:53]}};

assign tmp_V_1_fu_214_p1 = p_Val2_s_fu_200_p1[51:0];

assign ush_fu_257_p3 = ((isNeg_fu_240_p3[0:0] === 1'b1) ? sext_ln1311_fu_253_p1 : add_ln502_fu_234_p2);

assign val_V_fu_311_p3 = ((isNeg_fu_240_p3[0:0] === 1'b1) ? zext_ln662_fu_297_p1 : tmp_2_fu_301_p4);

assign zext_ln1285_fu_273_p1 = $unsigned(sext_ln1311_1_fu_265_p1);

assign zext_ln1287_fu_269_p1 = $unsigned(sext_ln1311_1_fu_265_p1);

assign zext_ln16_2_fu_196_p1 = B;

assign zext_ln16_fu_188_p1 = R;

assign zext_ln502_fu_231_p1 = tmp_V_reg_371;

assign zext_ln662_fu_297_p1 = tmp_10_fu_289_p3;

assign zext_ln682_fu_227_p1 = mantissa_V_fu_218_p4;

endmodule //Cb
