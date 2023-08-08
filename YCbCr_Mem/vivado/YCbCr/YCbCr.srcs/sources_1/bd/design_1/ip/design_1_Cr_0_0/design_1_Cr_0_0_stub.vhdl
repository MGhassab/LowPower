-- Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2019.1 (win64) Build 2552052 Fri May 24 14:49:42 MDT 2019
-- Date        : Sun Aug  6 20:12:26 2023
-- Host        : DESKTOP-NSCBN50 running 64-bit major release  (build 9200)
-- Command     : write_vhdl -force -mode synth_stub
--               c:/Users/ESRLab-04/Desktop/vivado/YCbCr/YCbCr.srcs/sources_1/bd/design_1/ip/design_1_Cr_0_0/design_1_Cr_0_0_stub.vhdl
-- Design      : design_1_Cr_0_0
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xc7s100fgga676-2
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity design_1_Cr_0_0 is
  Port ( 
    ap_clk : in STD_LOGIC;
    ap_rst : in STD_LOGIC;
    ap_start : in STD_LOGIC;
    ap_done : out STD_LOGIC;
    ap_idle : out STD_LOGIC;
    ap_ready : out STD_LOGIC;
    ap_return : out STD_LOGIC_VECTOR ( 7 downto 0 );
    R : in STD_LOGIC_VECTOR ( 7 downto 0 );
    G : in STD_LOGIC_VECTOR ( 7 downto 0 );
    B : in STD_LOGIC_VECTOR ( 7 downto 0 )
  );

end design_1_Cr_0_0;

architecture stub of design_1_Cr_0_0 is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "ap_clk,ap_rst,ap_start,ap_done,ap_idle,ap_ready,ap_return[7:0],R[7:0],G[7:0],B[7:0]";
attribute x_core_info : string;
attribute x_core_info of stub : architecture is "Cr,Vivado 2019.1";
begin
end;
