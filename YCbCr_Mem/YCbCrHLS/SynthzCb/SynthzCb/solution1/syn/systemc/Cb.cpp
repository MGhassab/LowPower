// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2019.1
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#include "Cb.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

const sc_logic Cb::ap_const_logic_1 = sc_dt::Log_1;
const sc_logic Cb::ap_const_logic_0 = sc_dt::Log_0;
const sc_lv<27> Cb::ap_ST_fsm_state1 = "1";
const sc_lv<27> Cb::ap_ST_fsm_state2 = "10";
const sc_lv<27> Cb::ap_ST_fsm_state3 = "100";
const sc_lv<27> Cb::ap_ST_fsm_state4 = "1000";
const sc_lv<27> Cb::ap_ST_fsm_state5 = "10000";
const sc_lv<27> Cb::ap_ST_fsm_state6 = "100000";
const sc_lv<27> Cb::ap_ST_fsm_state7 = "1000000";
const sc_lv<27> Cb::ap_ST_fsm_state8 = "10000000";
const sc_lv<27> Cb::ap_ST_fsm_state9 = "100000000";
const sc_lv<27> Cb::ap_ST_fsm_state10 = "1000000000";
const sc_lv<27> Cb::ap_ST_fsm_state11 = "10000000000";
const sc_lv<27> Cb::ap_ST_fsm_state12 = "100000000000";
const sc_lv<27> Cb::ap_ST_fsm_state13 = "1000000000000";
const sc_lv<27> Cb::ap_ST_fsm_state14 = "10000000000000";
const sc_lv<27> Cb::ap_ST_fsm_state15 = "100000000000000";
const sc_lv<27> Cb::ap_ST_fsm_state16 = "1000000000000000";
const sc_lv<27> Cb::ap_ST_fsm_state17 = "10000000000000000";
const sc_lv<27> Cb::ap_ST_fsm_state18 = "100000000000000000";
const sc_lv<27> Cb::ap_ST_fsm_state19 = "1000000000000000000";
const sc_lv<27> Cb::ap_ST_fsm_state20 = "10000000000000000000";
const sc_lv<27> Cb::ap_ST_fsm_state21 = "100000000000000000000";
const sc_lv<27> Cb::ap_ST_fsm_state22 = "1000000000000000000000";
const sc_lv<27> Cb::ap_ST_fsm_state23 = "10000000000000000000000";
const sc_lv<27> Cb::ap_ST_fsm_state24 = "100000000000000000000000";
const sc_lv<27> Cb::ap_ST_fsm_state25 = "1000000000000000000000000";
const sc_lv<27> Cb::ap_ST_fsm_state26 = "10000000000000000000000000";
const sc_lv<27> Cb::ap_ST_fsm_state27 = "100000000000000000000000000";
const sc_lv<32> Cb::ap_const_lv32_0 = "00000000000000000000000000000000";
const sc_lv<32> Cb::ap_const_lv32_5 = "101";
const sc_lv<1> Cb::ap_const_lv1_0 = "0";
const sc_lv<32> Cb::ap_const_lv32_A = "1010";
const sc_lv<32> Cb::ap_const_lv32_F = "1111";
const sc_lv<32> Cb::ap_const_lv32_14 = "10100";
const sc_lv<32> Cb::ap_const_lv32_1 = "1";
const sc_lv<32> Cb::ap_const_lv32_6 = "110";
const sc_lv<32> Cb::ap_const_lv32_19 = "11001";
const sc_lv<64> Cb::ap_const_lv64_4060000000000000 = "100000001100000000000000000000000000000000000000000000000000000";
const sc_lv<32> Cb::ap_const_lv32_B = "1011";
const sc_lv<32> Cb::ap_const_lv32_10 = "10000";
const sc_lv<32> Cb::ap_const_lv32_15 = "10101";
const sc_lv<64> Cb::ap_const_lv64_BFC2F1A9FBE76C8B = "1011111111000010111100011010100111111011111001110110110010001011";
const sc_lv<64> Cb::ap_const_lv64_3FDC189374BC6A7F = "11111111011100000110001001001101110100101111000110101001111111";
const sc_lv<64> Cb::ap_const_lv64_3FD29FBE76C8B439 = "11111111010010100111111011111001110110110010001011010000111001";
const sc_lv<8> Cb::ap_const_lv8_42 = "1000010";
const sc_lv<8> Cb::ap_const_lv8_1A = "11010";
const sc_lv<8> Cb::ap_const_lv8_4C = "1001100";
const sc_lv<8> Cb::ap_const_lv8_24 = "100100";
const sc_lv<8> Cb::ap_const_lv8_55 = "1010101";
const sc_lv<8> Cb::ap_const_lv8_2D = "101101";
const sc_lv<32> Cb::ap_const_lv32_34 = "110100";
const sc_lv<32> Cb::ap_const_lv32_3E = "111110";
const sc_lv<1> Cb::ap_const_lv1_1 = "1";
const sc_lv<32> Cb::ap_const_lv32_1A = "11010";
const sc_lv<12> Cb::ap_const_lv12_C01 = "110000000001";
const sc_lv<11> Cb::ap_const_lv11_3FF = "1111111111";
const sc_lv<32> Cb::ap_const_lv32_35 = "110101";
const sc_lv<32> Cb::ap_const_lv32_3C = "111100";
const sc_lv<8> Cb::ap_const_lv8_85 = "10000101";
const sc_lv<2> Cb::ap_const_lv2_0 = "00";
const sc_lv<2> Cb::ap_const_lv2_1 = "1";
const bool Cb::ap_const_boolean_1 = true;

Cb::Cb(sc_module_name name) : sc_module(name), mVcdFile(0) {
    Cb_dadddsub_64ns_bkb_U1 = new Cb_dadddsub_64ns_bkb<1,5,64,64,64>("Cb_dadddsub_64ns_bkb_U1");
    Cb_dadddsub_64ns_bkb_U1->clk(ap_clk);
    Cb_dadddsub_64ns_bkb_U1->reset(ap_rst);
    Cb_dadddsub_64ns_bkb_U1->din0(grp_fu_84_p0);
    Cb_dadddsub_64ns_bkb_U1->din1(grp_fu_84_p1);
    Cb_dadddsub_64ns_bkb_U1->opcode(grp_fu_84_opcode);
    Cb_dadddsub_64ns_bkb_U1->ce(ap_var_for_const0);
    Cb_dadddsub_64ns_bkb_U1->dout(grp_fu_84_p2);
    Cb_dmul_64ns_64nscud_U2 = new Cb_dmul_64ns_64nscud<1,5,64,64,64>("Cb_dmul_64ns_64nscud_U2");
    Cb_dmul_64ns_64nscud_U2->clk(ap_clk);
    Cb_dmul_64ns_64nscud_U2->reset(ap_rst);
    Cb_dmul_64ns_64nscud_U2->din0(reg_106);
    Cb_dmul_64ns_64nscud_U2->din1(grp_fu_89_p1);
    Cb_dmul_64ns_64nscud_U2->ce(ap_var_for_const0);
    Cb_dmul_64ns_64nscud_U2->dout(grp_fu_89_p2);
    Cb_dmul_64ns_64nscud_U3 = new Cb_dmul_64ns_64nscud<1,5,64,64,64>("Cb_dmul_64ns_64nscud_U3");
    Cb_dmul_64ns_64nscud_U3->clk(ap_clk);
    Cb_dmul_64ns_64nscud_U3->reset(ap_rst);
    Cb_dmul_64ns_64nscud_U3->din0(tmp_4_reg_356);
    Cb_dmul_64ns_64nscud_U3->din1(ap_var_for_const1);
    Cb_dmul_64ns_64nscud_U3->ce(ap_var_for_const0);
    Cb_dmul_64ns_64nscud_U3->dout(grp_fu_94_p2);
    Cb_sitodp_32ns_64dEe_U4 = new Cb_sitodp_32ns_64dEe<1,5,32,64>("Cb_sitodp_32ns_64dEe_U4");
    Cb_sitodp_32ns_64dEe_U4->clk(ap_clk);
    Cb_sitodp_32ns_64dEe_U4->reset(ap_rst);
    Cb_sitodp_32ns_64dEe_U4->din0(grp_fu_100_p0);
    Cb_sitodp_32ns_64dEe_U4->ce(ap_var_for_const0);
    Cb_sitodp_32ns_64dEe_U4->dout(grp_fu_100_p1);
    Cb_sitodp_32ns_64dEe_U5 = new Cb_sitodp_32ns_64dEe<1,5,32,64>("Cb_sitodp_32ns_64dEe_U5");
    Cb_sitodp_32ns_64dEe_U5->clk(ap_clk);
    Cb_sitodp_32ns_64dEe_U5->reset(ap_rst);
    Cb_sitodp_32ns_64dEe_U5->din0(grp_fu_103_p0);
    Cb_sitodp_32ns_64dEe_U5->ce(ap_var_for_const0);
    Cb_sitodp_32ns_64dEe_U5->dout(grp_fu_103_p1);

    SC_METHOD(thread_ap_clk_no_reset_);
    dont_initialize();
    sensitive << ( ap_clk.pos() );

    SC_METHOD(thread_add_ln502_fu_234_p2);
    sensitive << ( zext_ln502_fu_231_p1 );

    SC_METHOD(thread_and_ln10_1_fu_164_p2);
    sensitive << ( and_ln10_fu_158_p2 );
    sensitive << ( icmp_ln10_fu_122_p2 );

    SC_METHOD(thread_and_ln10_2_fu_170_p2);
    sensitive << ( icmp_ln10_4_fu_146_p2 );
    sensitive << ( icmp_ln10_5_fu_152_p2 );

    SC_METHOD(thread_and_ln10_3_fu_176_p2);
    sensitive << ( and_ln10_2_fu_170_p2 );
    sensitive << ( icmp_ln10_3_fu_140_p2 );

    SC_METHOD(thread_and_ln10_4_fu_182_p2);
    sensitive << ( and_ln10_3_fu_176_p2 );
    sensitive << ( and_ln10_1_fu_164_p2 );

    SC_METHOD(thread_and_ln10_fu_158_p2);
    sensitive << ( icmp_ln10_1_fu_128_p2 );
    sensitive << ( icmp_ln10_2_fu_134_p2 );

    SC_METHOD(thread_ap_CS_fsm_state1);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state11);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state12);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state16);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state17);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state2);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state21);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state22);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state26);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state27);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state6);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state7);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_done);
    sensitive << ( ap_CS_fsm_state27 );

    SC_METHOD(thread_ap_idle);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm_state1 );

    SC_METHOD(thread_ap_ready);
    sensitive << ( ap_CS_fsm_state27 );

    SC_METHOD(thread_ap_return);
    sensitive << ( and_ln10_4_reg_341 );
    sensitive << ( ap_CS_fsm_state27 );
    sensitive << ( val_V_fu_311_p3 );

    SC_METHOD(thread_grp_fu_100_p0);
    sensitive << ( zext_ln16_fu_188_p1 );
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( zext_ln16_2_fu_196_p1 );
    sensitive << ( ap_CS_fsm_state7 );

    SC_METHOD(thread_grp_fu_103_p0);
    sensitive << ( G );
    sensitive << ( ap_CS_fsm_state2 );

    SC_METHOD(thread_grp_fu_84_opcode);
    sensitive << ( and_ln10_4_reg_341 );
    sensitive << ( ap_CS_fsm_state12 );
    sensitive << ( ap_CS_fsm_state17 );
    sensitive << ( ap_CS_fsm_state22 );

    SC_METHOD(thread_grp_fu_84_p0);
    sensitive << ( reg_111 );
    sensitive << ( reg_117 );
    sensitive << ( ap_CS_fsm_state12 );
    sensitive << ( ap_CS_fsm_state17 );
    sensitive << ( ap_CS_fsm_state22 );

    SC_METHOD(thread_grp_fu_84_p1);
    sensitive << ( reg_111 );
    sensitive << ( tmp_5_reg_366 );
    sensitive << ( ap_CS_fsm_state12 );
    sensitive << ( ap_CS_fsm_state17 );
    sensitive << ( ap_CS_fsm_state22 );

    SC_METHOD(thread_grp_fu_89_p1);
    sensitive << ( ap_CS_fsm_state7 );
    sensitive << ( ap_CS_fsm_state12 );

    SC_METHOD(thread_icmp_ln10_1_fu_128_p2);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm_state1 );
    sensitive << ( R );

    SC_METHOD(thread_icmp_ln10_2_fu_134_p2);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm_state1 );
    sensitive << ( G );

    SC_METHOD(thread_icmp_ln10_3_fu_140_p2);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm_state1 );
    sensitive << ( G );

    SC_METHOD(thread_icmp_ln10_4_fu_146_p2);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm_state1 );
    sensitive << ( B );

    SC_METHOD(thread_icmp_ln10_5_fu_152_p2);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm_state1 );
    sensitive << ( B );

    SC_METHOD(thread_icmp_ln10_fu_122_p2);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm_state1 );
    sensitive << ( R );

    SC_METHOD(thread_isNeg_fu_240_p3);
    sensitive << ( add_ln502_fu_234_p2 );

    SC_METHOD(thread_mantissa_V_fu_218_p4);
    sensitive << ( tmp_V_1_reg_377 );

    SC_METHOD(thread_p_Val2_s_fu_200_p1);
    sensitive << ( grp_fu_84_p2 );

    SC_METHOD(thread_r_V_1_fu_283_p2);
    sensitive << ( zext_ln682_fu_227_p1 );
    sensitive << ( zext_ln1287_fu_269_p1 );

    SC_METHOD(thread_r_V_fu_277_p2);
    sensitive << ( mantissa_V_fu_218_p4 );
    sensitive << ( zext_ln1285_fu_273_p1 );

    SC_METHOD(thread_sext_ln1311_1_fu_265_p1);
    sensitive << ( ush_fu_257_p3 );

    SC_METHOD(thread_sext_ln1311_fu_253_p1);
    sensitive << ( sub_ln1311_fu_248_p2 );

    SC_METHOD(thread_sub_ln1311_fu_248_p2);
    sensitive << ( tmp_V_reg_371 );

    SC_METHOD(thread_tmp_10_fu_289_p3);
    sensitive << ( r_V_fu_277_p2 );

    SC_METHOD(thread_tmp_2_fu_301_p4);
    sensitive << ( r_V_1_fu_283_p2 );

    SC_METHOD(thread_tmp_V_1_fu_214_p1);
    sensitive << ( p_Val2_s_fu_200_p1 );

    SC_METHOD(thread_ush_fu_257_p3);
    sensitive << ( add_ln502_fu_234_p2 );
    sensitive << ( isNeg_fu_240_p3 );
    sensitive << ( sext_ln1311_fu_253_p1 );

    SC_METHOD(thread_val_V_fu_311_p3);
    sensitive << ( isNeg_fu_240_p3 );
    sensitive << ( zext_ln662_fu_297_p1 );
    sensitive << ( tmp_2_fu_301_p4 );

    SC_METHOD(thread_zext_ln1285_fu_273_p1);
    sensitive << ( sext_ln1311_1_fu_265_p1 );

    SC_METHOD(thread_zext_ln1287_fu_269_p1);
    sensitive << ( sext_ln1311_1_fu_265_p1 );

    SC_METHOD(thread_zext_ln16_2_fu_196_p1);
    sensitive << ( B );

    SC_METHOD(thread_zext_ln16_fu_188_p1);
    sensitive << ( R );

    SC_METHOD(thread_zext_ln502_fu_231_p1);
    sensitive << ( tmp_V_reg_371 );

    SC_METHOD(thread_zext_ln662_fu_297_p1);
    sensitive << ( tmp_10_fu_289_p3 );

    SC_METHOD(thread_zext_ln682_fu_227_p1);
    sensitive << ( mantissa_V_fu_218_p4 );

    SC_METHOD(thread_ap_NS_fsm);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm );
    sensitive << ( ap_CS_fsm_state1 );

    SC_THREAD(thread_hdltv_gen);
    sensitive << ( ap_clk.pos() );

    SC_THREAD(thread_ap_var_for_const0);

    SC_THREAD(thread_ap_var_for_const1);

    ap_CS_fsm = "000000000000000000000000001";
    static int apTFileNum = 0;
    stringstream apTFilenSS;
    apTFilenSS << "Cb_sc_trace_" << apTFileNum ++;
    string apTFn = apTFilenSS.str();
    mVcdFile = sc_create_vcd_trace_file(apTFn.c_str());
    mVcdFile->set_time_unit(1, SC_PS);
    if (1) {
#ifdef __HLS_TRACE_LEVEL_PORT__
    sc_trace(mVcdFile, ap_clk, "(port)ap_clk");
    sc_trace(mVcdFile, ap_rst, "(port)ap_rst");
    sc_trace(mVcdFile, ap_start, "(port)ap_start");
    sc_trace(mVcdFile, ap_done, "(port)ap_done");
    sc_trace(mVcdFile, ap_idle, "(port)ap_idle");
    sc_trace(mVcdFile, ap_ready, "(port)ap_ready");
    sc_trace(mVcdFile, R, "(port)R");
    sc_trace(mVcdFile, G, "(port)G");
    sc_trace(mVcdFile, B, "(port)B");
    sc_trace(mVcdFile, ap_return, "(port)ap_return");
#endif
#ifdef __HLS_TRACE_LEVEL_INT__
    sc_trace(mVcdFile, ap_CS_fsm, "ap_CS_fsm");
    sc_trace(mVcdFile, ap_CS_fsm_state1, "ap_CS_fsm_state1");
    sc_trace(mVcdFile, grp_fu_100_p1, "grp_fu_100_p1");
    sc_trace(mVcdFile, reg_106, "reg_106");
    sc_trace(mVcdFile, ap_CS_fsm_state6, "ap_CS_fsm_state6");
    sc_trace(mVcdFile, and_ln10_4_reg_341, "and_ln10_4_reg_341");
    sc_trace(mVcdFile, ap_CS_fsm_state11, "ap_CS_fsm_state11");
    sc_trace(mVcdFile, grp_fu_89_p2, "grp_fu_89_p2");
    sc_trace(mVcdFile, reg_111, "reg_111");
    sc_trace(mVcdFile, ap_CS_fsm_state16, "ap_CS_fsm_state16");
    sc_trace(mVcdFile, grp_fu_84_p2, "grp_fu_84_p2");
    sc_trace(mVcdFile, reg_117, "reg_117");
    sc_trace(mVcdFile, ap_CS_fsm_state21, "ap_CS_fsm_state21");
    sc_trace(mVcdFile, and_ln10_4_fu_182_p2, "and_ln10_4_fu_182_p2");
    sc_trace(mVcdFile, zext_ln16_fu_188_p1, "zext_ln16_fu_188_p1");
    sc_trace(mVcdFile, ap_CS_fsm_state2, "ap_CS_fsm_state2");
    sc_trace(mVcdFile, grp_fu_103_p1, "grp_fu_103_p1");
    sc_trace(mVcdFile, tmp_4_reg_356, "tmp_4_reg_356");
    sc_trace(mVcdFile, zext_ln16_2_fu_196_p1, "zext_ln16_2_fu_196_p1");
    sc_trace(mVcdFile, ap_CS_fsm_state7, "ap_CS_fsm_state7");
    sc_trace(mVcdFile, grp_fu_94_p2, "grp_fu_94_p2");
    sc_trace(mVcdFile, tmp_5_reg_366, "tmp_5_reg_366");
    sc_trace(mVcdFile, tmp_V_reg_371, "tmp_V_reg_371");
    sc_trace(mVcdFile, ap_CS_fsm_state26, "ap_CS_fsm_state26");
    sc_trace(mVcdFile, tmp_V_1_fu_214_p1, "tmp_V_1_fu_214_p1");
    sc_trace(mVcdFile, tmp_V_1_reg_377, "tmp_V_1_reg_377");
    sc_trace(mVcdFile, grp_fu_84_p0, "grp_fu_84_p0");
    sc_trace(mVcdFile, grp_fu_84_p1, "grp_fu_84_p1");
    sc_trace(mVcdFile, ap_CS_fsm_state12, "ap_CS_fsm_state12");
    sc_trace(mVcdFile, ap_CS_fsm_state17, "ap_CS_fsm_state17");
    sc_trace(mVcdFile, ap_CS_fsm_state22, "ap_CS_fsm_state22");
    sc_trace(mVcdFile, grp_fu_89_p1, "grp_fu_89_p1");
    sc_trace(mVcdFile, grp_fu_100_p0, "grp_fu_100_p0");
    sc_trace(mVcdFile, grp_fu_103_p0, "grp_fu_103_p0");
    sc_trace(mVcdFile, icmp_ln10_1_fu_128_p2, "icmp_ln10_1_fu_128_p2");
    sc_trace(mVcdFile, icmp_ln10_2_fu_134_p2, "icmp_ln10_2_fu_134_p2");
    sc_trace(mVcdFile, and_ln10_fu_158_p2, "and_ln10_fu_158_p2");
    sc_trace(mVcdFile, icmp_ln10_fu_122_p2, "icmp_ln10_fu_122_p2");
    sc_trace(mVcdFile, icmp_ln10_4_fu_146_p2, "icmp_ln10_4_fu_146_p2");
    sc_trace(mVcdFile, icmp_ln10_5_fu_152_p2, "icmp_ln10_5_fu_152_p2");
    sc_trace(mVcdFile, and_ln10_2_fu_170_p2, "and_ln10_2_fu_170_p2");
    sc_trace(mVcdFile, icmp_ln10_3_fu_140_p2, "icmp_ln10_3_fu_140_p2");
    sc_trace(mVcdFile, and_ln10_3_fu_176_p2, "and_ln10_3_fu_176_p2");
    sc_trace(mVcdFile, and_ln10_1_fu_164_p2, "and_ln10_1_fu_164_p2");
    sc_trace(mVcdFile, p_Val2_s_fu_200_p1, "p_Val2_s_fu_200_p1");
    sc_trace(mVcdFile, ap_CS_fsm_state27, "ap_CS_fsm_state27");
    sc_trace(mVcdFile, mantissa_V_fu_218_p4, "mantissa_V_fu_218_p4");
    sc_trace(mVcdFile, zext_ln502_fu_231_p1, "zext_ln502_fu_231_p1");
    sc_trace(mVcdFile, add_ln502_fu_234_p2, "add_ln502_fu_234_p2");
    sc_trace(mVcdFile, sub_ln1311_fu_248_p2, "sub_ln1311_fu_248_p2");
    sc_trace(mVcdFile, isNeg_fu_240_p3, "isNeg_fu_240_p3");
    sc_trace(mVcdFile, sext_ln1311_fu_253_p1, "sext_ln1311_fu_253_p1");
    sc_trace(mVcdFile, ush_fu_257_p3, "ush_fu_257_p3");
    sc_trace(mVcdFile, sext_ln1311_1_fu_265_p1, "sext_ln1311_1_fu_265_p1");
    sc_trace(mVcdFile, zext_ln1285_fu_273_p1, "zext_ln1285_fu_273_p1");
    sc_trace(mVcdFile, zext_ln682_fu_227_p1, "zext_ln682_fu_227_p1");
    sc_trace(mVcdFile, zext_ln1287_fu_269_p1, "zext_ln1287_fu_269_p1");
    sc_trace(mVcdFile, r_V_fu_277_p2, "r_V_fu_277_p2");
    sc_trace(mVcdFile, tmp_10_fu_289_p3, "tmp_10_fu_289_p3");
    sc_trace(mVcdFile, r_V_1_fu_283_p2, "r_V_1_fu_283_p2");
    sc_trace(mVcdFile, zext_ln662_fu_297_p1, "zext_ln662_fu_297_p1");
    sc_trace(mVcdFile, tmp_2_fu_301_p4, "tmp_2_fu_301_p4");
    sc_trace(mVcdFile, val_V_fu_311_p3, "val_V_fu_311_p3");
    sc_trace(mVcdFile, grp_fu_84_opcode, "grp_fu_84_opcode");
    sc_trace(mVcdFile, ap_NS_fsm, "ap_NS_fsm");
#endif

    }
    mHdltvinHandle.open("Cb.hdltvin.dat");
    mHdltvoutHandle.open("Cb.hdltvout.dat");
}

Cb::~Cb() {
    if (mVcdFile) 
        sc_close_vcd_trace_file(mVcdFile);

    mHdltvinHandle << "] " << endl;
    mHdltvoutHandle << "] " << endl;
    mHdltvinHandle.close();
    mHdltvoutHandle.close();
    delete Cb_dadddsub_64ns_bkb_U1;
    delete Cb_dmul_64ns_64nscud_U2;
    delete Cb_dmul_64ns_64nscud_U3;
    delete Cb_sitodp_32ns_64dEe_U4;
    delete Cb_sitodp_32ns_64dEe_U5;
}

void Cb::thread_ap_var_for_const0() {
    ap_var_for_const0 = ap_const_logic_1;
}

void Cb::thread_ap_var_for_const1() {
    ap_var_for_const1 = ap_const_lv64_3FD29FBE76C8B439;
}

void Cb::thread_ap_clk_no_reset_() {
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_CS_fsm = ap_ST_fsm_state1;
    } else {
        ap_CS_fsm = ap_NS_fsm.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
        and_ln10_4_reg_341 = and_ln10_4_fu_182_p2.read();
    }
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state6.read()) && 
  esl_seteq<1,1,1>(and_ln10_4_reg_341.read(), ap_const_lv1_0)) || (esl_seteq<1,1,1>(and_ln10_4_reg_341.read(), ap_const_lv1_0) && 
  esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state11.read())))) {
        reg_106 = grp_fu_100_p1.read();
    }
    if (((esl_seteq<1,1,1>(and_ln10_4_reg_341.read(), ap_const_lv1_0) && 
  esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state11.read())) || (esl_seteq<1,1,1>(and_ln10_4_reg_341.read(), ap_const_lv1_0) && 
  esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state16.read())))) {
        reg_111 = grp_fu_89_p2.read();
    }
    if (((esl_seteq<1,1,1>(and_ln10_4_reg_341.read(), ap_const_lv1_0) && 
  esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state16.read())) || (esl_seteq<1,1,1>(and_ln10_4_reg_341.read(), ap_const_lv1_0) && 
  esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state21.read())))) {
        reg_117 = grp_fu_84_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state6.read()) && esl_seteq<1,1,1>(and_ln10_4_reg_341.read(), ap_const_lv1_0))) {
        tmp_4_reg_356 = grp_fu_103_p1.read();
    }
    if ((esl_seteq<1,1,1>(and_ln10_4_reg_341.read(), ap_const_lv1_0) && esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state11.read()))) {
        tmp_5_reg_366 = grp_fu_94_p2.read();
    }
    if ((esl_seteq<1,1,1>(and_ln10_4_reg_341.read(), ap_const_lv1_0) && esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state26.read()))) {
        tmp_V_1_reg_377 = tmp_V_1_fu_214_p1.read();
        tmp_V_reg_371 = p_Val2_s_fu_200_p1.read().range(62, 52);
    }
}

void Cb::thread_add_ln502_fu_234_p2() {
    add_ln502_fu_234_p2 = (!ap_const_lv12_C01.is_01() || !zext_ln502_fu_231_p1.read().is_01())? sc_lv<12>(): (sc_bigint<12>(ap_const_lv12_C01) + sc_biguint<12>(zext_ln502_fu_231_p1.read()));
}

void Cb::thread_and_ln10_1_fu_164_p2() {
    and_ln10_1_fu_164_p2 = (and_ln10_fu_158_p2.read() & icmp_ln10_fu_122_p2.read());
}

void Cb::thread_and_ln10_2_fu_170_p2() {
    and_ln10_2_fu_170_p2 = (icmp_ln10_4_fu_146_p2.read() & icmp_ln10_5_fu_152_p2.read());
}

void Cb::thread_and_ln10_3_fu_176_p2() {
    and_ln10_3_fu_176_p2 = (and_ln10_2_fu_170_p2.read() & icmp_ln10_3_fu_140_p2.read());
}

void Cb::thread_and_ln10_4_fu_182_p2() {
    and_ln10_4_fu_182_p2 = (and_ln10_3_fu_176_p2.read() & and_ln10_1_fu_164_p2.read());
}

void Cb::thread_and_ln10_fu_158_p2() {
    and_ln10_fu_158_p2 = (icmp_ln10_1_fu_128_p2.read() & icmp_ln10_2_fu_134_p2.read());
}

void Cb::thread_ap_CS_fsm_state1() {
    ap_CS_fsm_state1 = ap_CS_fsm.read()[0];
}

void Cb::thread_ap_CS_fsm_state11() {
    ap_CS_fsm_state11 = ap_CS_fsm.read()[10];
}

void Cb::thread_ap_CS_fsm_state12() {
    ap_CS_fsm_state12 = ap_CS_fsm.read()[11];
}

void Cb::thread_ap_CS_fsm_state16() {
    ap_CS_fsm_state16 = ap_CS_fsm.read()[15];
}

void Cb::thread_ap_CS_fsm_state17() {
    ap_CS_fsm_state17 = ap_CS_fsm.read()[16];
}

void Cb::thread_ap_CS_fsm_state2() {
    ap_CS_fsm_state2 = ap_CS_fsm.read()[1];
}

void Cb::thread_ap_CS_fsm_state21() {
    ap_CS_fsm_state21 = ap_CS_fsm.read()[20];
}

void Cb::thread_ap_CS_fsm_state22() {
    ap_CS_fsm_state22 = ap_CS_fsm.read()[21];
}

void Cb::thread_ap_CS_fsm_state26() {
    ap_CS_fsm_state26 = ap_CS_fsm.read()[25];
}

void Cb::thread_ap_CS_fsm_state27() {
    ap_CS_fsm_state27 = ap_CS_fsm.read()[26];
}

void Cb::thread_ap_CS_fsm_state6() {
    ap_CS_fsm_state6 = ap_CS_fsm.read()[5];
}

void Cb::thread_ap_CS_fsm_state7() {
    ap_CS_fsm_state7 = ap_CS_fsm.read()[6];
}

void Cb::thread_ap_done() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state27.read())) {
        ap_done = ap_const_logic_1;
    } else {
        ap_done = ap_const_logic_0;
    }
}

void Cb::thread_ap_idle() {
    if ((esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()))) {
        ap_idle = ap_const_logic_1;
    } else {
        ap_idle = ap_const_logic_0;
    }
}

void Cb::thread_ap_ready() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state27.read())) {
        ap_ready = ap_const_logic_1;
    } else {
        ap_ready = ap_const_logic_0;
    }
}

void Cb::thread_ap_return() {
    ap_return = (!and_ln10_4_reg_341.read()[0].is_01())? sc_lv<8>(): ((and_ln10_4_reg_341.read()[0].to_bool())? ap_const_lv8_85: val_V_fu_311_p3.read());
}

void Cb::thread_grp_fu_100_p0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state7.read())) {
        grp_fu_100_p0 = zext_ln16_2_fu_196_p1.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read())) {
        grp_fu_100_p0 = zext_ln16_fu_188_p1.read();
    } else {
        grp_fu_100_p0 = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
    }
}

void Cb::thread_grp_fu_103_p0() {
    grp_fu_103_p0 = esl_zext<32,8>(G.read());
}

void Cb::thread_grp_fu_84_opcode() {
    if ((esl_seteq<1,1,1>(and_ln10_4_reg_341.read(), ap_const_lv1_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state12.read()))) {
        grp_fu_84_opcode = ap_const_lv2_1;
    } else if (((esl_seteq<1,1,1>(and_ln10_4_reg_341.read(), ap_const_lv1_0) && 
                 esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state17.read())) || 
                (esl_seteq<1,1,1>(and_ln10_4_reg_341.read(), ap_const_lv1_0) && 
                 esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state22.read())))) {
        grp_fu_84_opcode = ap_const_lv2_0;
    } else {
        grp_fu_84_opcode =  (sc_lv<2>) ("XX");
    }
}

void Cb::thread_grp_fu_84_p0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state17.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state22.read()))) {
        grp_fu_84_p0 = reg_117.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state12.read())) {
        grp_fu_84_p0 = reg_111.read();
    } else {
        grp_fu_84_p0 =  (sc_lv<64>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void Cb::thread_grp_fu_84_p1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state22.read())) {
        grp_fu_84_p1 = ap_const_lv64_4060000000000000;
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state17.read())) {
        grp_fu_84_p1 = reg_111.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state12.read())) {
        grp_fu_84_p1 = tmp_5_reg_366.read();
    } else {
        grp_fu_84_p1 =  (sc_lv<64>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void Cb::thread_grp_fu_89_p1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state12.read())) {
        grp_fu_89_p1 = ap_const_lv64_3FDC189374BC6A7F;
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state7.read())) {
        grp_fu_89_p1 = ap_const_lv64_BFC2F1A9FBE76C8B;
    } else {
        grp_fu_89_p1 =  (sc_lv<64>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void Cb::thread_icmp_ln10_1_fu_128_p2() {
    icmp_ln10_1_fu_128_p2 = (!R.read().is_01() || !ap_const_lv8_1A.is_01())? sc_lv<1>(): (sc_biguint<8>(R.read()) > sc_biguint<8>(ap_const_lv8_1A));
}

void Cb::thread_icmp_ln10_2_fu_134_p2() {
    icmp_ln10_2_fu_134_p2 = (!G.read().is_01() || !ap_const_lv8_4C.is_01())? sc_lv<1>(): (sc_biguint<8>(G.read()) < sc_biguint<8>(ap_const_lv8_4C));
}

void Cb::thread_icmp_ln10_3_fu_140_p2() {
    icmp_ln10_3_fu_140_p2 = (!G.read().is_01() || !ap_const_lv8_24.is_01())? sc_lv<1>(): (sc_biguint<8>(G.read()) > sc_biguint<8>(ap_const_lv8_24));
}

void Cb::thread_icmp_ln10_4_fu_146_p2() {
    icmp_ln10_4_fu_146_p2 = (!B.read().is_01() || !ap_const_lv8_55.is_01())? sc_lv<1>(): (sc_biguint<8>(B.read()) < sc_biguint<8>(ap_const_lv8_55));
}

void Cb::thread_icmp_ln10_5_fu_152_p2() {
    icmp_ln10_5_fu_152_p2 = (!B.read().is_01() || !ap_const_lv8_2D.is_01())? sc_lv<1>(): (sc_biguint<8>(B.read()) > sc_biguint<8>(ap_const_lv8_2D));
}

void Cb::thread_icmp_ln10_fu_122_p2() {
    icmp_ln10_fu_122_p2 = (!R.read().is_01() || !ap_const_lv8_42.is_01())? sc_lv<1>(): (sc_biguint<8>(R.read()) < sc_biguint<8>(ap_const_lv8_42));
}

void Cb::thread_isNeg_fu_240_p3() {
    isNeg_fu_240_p3 = add_ln502_fu_234_p2.read().range(11, 11);
}

void Cb::thread_mantissa_V_fu_218_p4() {
    mantissa_V_fu_218_p4 = esl_concat<53,1>(esl_concat<1,52>(ap_const_lv1_1, tmp_V_1_reg_377.read()), ap_const_lv1_0);
}

void Cb::thread_p_Val2_s_fu_200_p1() {
    p_Val2_s_fu_200_p1 = grp_fu_84_p2.read();
}

void Cb::thread_r_V_1_fu_283_p2() {
    r_V_1_fu_283_p2 = (!zext_ln1287_fu_269_p1.read().is_01())? sc_lv<113>(): zext_ln682_fu_227_p1.read() << (unsigned short)zext_ln1287_fu_269_p1.read().to_uint();
}

void Cb::thread_r_V_fu_277_p2() {
    r_V_fu_277_p2 = (!zext_ln1285_fu_273_p1.read().is_01())? sc_lv<54>(): mantissa_V_fu_218_p4.read() >> (unsigned short)zext_ln1285_fu_273_p1.read().to_uint();
}

void Cb::thread_sext_ln1311_1_fu_265_p1() {
    sext_ln1311_1_fu_265_p1 = esl_sext<32,12>(ush_fu_257_p3.read());
}

void Cb::thread_sext_ln1311_fu_253_p1() {
    sext_ln1311_fu_253_p1 = esl_sext<12,11>(sub_ln1311_fu_248_p2.read());
}

void Cb::thread_sub_ln1311_fu_248_p2() {
    sub_ln1311_fu_248_p2 = (!ap_const_lv11_3FF.is_01() || !tmp_V_reg_371.read().is_01())? sc_lv<11>(): (sc_biguint<11>(ap_const_lv11_3FF) - sc_biguint<11>(tmp_V_reg_371.read()));
}

void Cb::thread_tmp_10_fu_289_p3() {
    tmp_10_fu_289_p3 = r_V_fu_277_p2.read().range(53, 53);
}

void Cb::thread_tmp_2_fu_301_p4() {
    tmp_2_fu_301_p4 = r_V_1_fu_283_p2.read().range(60, 53);
}

void Cb::thread_tmp_V_1_fu_214_p1() {
    tmp_V_1_fu_214_p1 = p_Val2_s_fu_200_p1.read().range(52-1, 0);
}

void Cb::thread_ush_fu_257_p3() {
    ush_fu_257_p3 = (!isNeg_fu_240_p3.read()[0].is_01())? sc_lv<12>(): ((isNeg_fu_240_p3.read()[0].to_bool())? sext_ln1311_fu_253_p1.read(): add_ln502_fu_234_p2.read());
}

void Cb::thread_val_V_fu_311_p3() {
    val_V_fu_311_p3 = (!isNeg_fu_240_p3.read()[0].is_01())? sc_lv<8>(): ((isNeg_fu_240_p3.read()[0].to_bool())? zext_ln662_fu_297_p1.read(): tmp_2_fu_301_p4.read());
}

void Cb::thread_zext_ln1285_fu_273_p1() {
    zext_ln1285_fu_273_p1 = esl_zext<54,32>(sext_ln1311_1_fu_265_p1.read());
}

void Cb::thread_zext_ln1287_fu_269_p1() {
    zext_ln1287_fu_269_p1 = esl_zext<113,32>(sext_ln1311_1_fu_265_p1.read());
}

void Cb::thread_zext_ln16_2_fu_196_p1() {
    zext_ln16_2_fu_196_p1 = esl_zext<32,8>(B.read());
}

void Cb::thread_zext_ln16_fu_188_p1() {
    zext_ln16_fu_188_p1 = esl_zext<32,8>(R.read());
}

void Cb::thread_zext_ln502_fu_231_p1() {
    zext_ln502_fu_231_p1 = esl_zext<12,11>(tmp_V_reg_371.read());
}

void Cb::thread_zext_ln662_fu_297_p1() {
    zext_ln662_fu_297_p1 = esl_zext<8,1>(tmp_10_fu_289_p3.read());
}

void Cb::thread_zext_ln682_fu_227_p1() {
    zext_ln682_fu_227_p1 = esl_zext<113,54>(mantissa_V_fu_218_p4.read());
}

void Cb::thread_ap_NS_fsm() {
    switch (ap_CS_fsm.read().to_uint64()) {
        case 1 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
                ap_NS_fsm = ap_ST_fsm_state2;
            } else {
                ap_NS_fsm = ap_ST_fsm_state1;
            }
            break;
        case 2 : 
            ap_NS_fsm = ap_ST_fsm_state3;
            break;
        case 4 : 
            ap_NS_fsm = ap_ST_fsm_state4;
            break;
        case 8 : 
            ap_NS_fsm = ap_ST_fsm_state5;
            break;
        case 16 : 
            ap_NS_fsm = ap_ST_fsm_state6;
            break;
        case 32 : 
            ap_NS_fsm = ap_ST_fsm_state7;
            break;
        case 64 : 
            ap_NS_fsm = ap_ST_fsm_state8;
            break;
        case 128 : 
            ap_NS_fsm = ap_ST_fsm_state9;
            break;
        case 256 : 
            ap_NS_fsm = ap_ST_fsm_state10;
            break;
        case 512 : 
            ap_NS_fsm = ap_ST_fsm_state11;
            break;
        case 1024 : 
            ap_NS_fsm = ap_ST_fsm_state12;
            break;
        case 2048 : 
            ap_NS_fsm = ap_ST_fsm_state13;
            break;
        case 4096 : 
            ap_NS_fsm = ap_ST_fsm_state14;
            break;
        case 8192 : 
            ap_NS_fsm = ap_ST_fsm_state15;
            break;
        case 16384 : 
            ap_NS_fsm = ap_ST_fsm_state16;
            break;
        case 32768 : 
            ap_NS_fsm = ap_ST_fsm_state17;
            break;
        case 65536 : 
            ap_NS_fsm = ap_ST_fsm_state18;
            break;
        case 131072 : 
            ap_NS_fsm = ap_ST_fsm_state19;
            break;
        case 262144 : 
            ap_NS_fsm = ap_ST_fsm_state20;
            break;
        case 524288 : 
            ap_NS_fsm = ap_ST_fsm_state21;
            break;
        case 1048576 : 
            ap_NS_fsm = ap_ST_fsm_state22;
            break;
        case 2097152 : 
            ap_NS_fsm = ap_ST_fsm_state23;
            break;
        case 4194304 : 
            ap_NS_fsm = ap_ST_fsm_state24;
            break;
        case 8388608 : 
            ap_NS_fsm = ap_ST_fsm_state25;
            break;
        case 16777216 : 
            ap_NS_fsm = ap_ST_fsm_state26;
            break;
        case 33554432 : 
            ap_NS_fsm = ap_ST_fsm_state27;
            break;
        case 67108864 : 
            ap_NS_fsm = ap_ST_fsm_state1;
            break;
        default : 
            ap_NS_fsm =  (sc_lv<27>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXX");
            break;
    }
}

void Cb::thread_hdltv_gen() {
    const char* dump_tv = std::getenv("AP_WRITE_TV");
    if (!(dump_tv && string(dump_tv) == "on")) return;

    wait();

    mHdltvinHandle << "[ " << endl;
    mHdltvoutHandle << "[ " << endl;
    int ap_cycleNo = 0;
    while (1) {
        wait();
        const char* mComma = ap_cycleNo == 0 ? " " : ", " ;
        mHdltvinHandle << mComma << "{"  <<  " \"ap_rst\" :  \"" << ap_rst.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"ap_start\" :  \"" << ap_start.read() << "\" ";
        mHdltvoutHandle << mComma << "{"  <<  " \"ap_done\" :  \"" << ap_done.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"ap_idle\" :  \"" << ap_idle.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"ap_ready\" :  \"" << ap_ready.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"R\" :  \"" << R.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"G\" :  \"" << G.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"B\" :  \"" << B.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"ap_return\" :  \"" << ap_return.read() << "\" ";
        mHdltvinHandle << "}" << std::endl;
        mHdltvoutHandle << "}" << std::endl;
        ap_cycleNo++;
    }
}

}
