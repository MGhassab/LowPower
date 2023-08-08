--Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
----------------------------------------------------------------------------------
--Tool Version: Vivado v.2019.1 (win64) Build 2552052 Fri May 24 14:49:42 MDT 2019
--Date        : Sun Aug  6 20:08:43 2023
--Host        : DESKTOP-NSCBN50 running 64-bit major release  (build 9200)
--Command     : generate_target design_1_wrapper.bd
--Design      : design_1_wrapper
--Purpose     : IP block netlist
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity design_1_wrapper is
  port (
    B : in STD_LOGIC_VECTOR ( 7 downto 0 );
    G : in STD_LOGIC_VECTOR ( 7 downto 0 );
    R : in STD_LOGIC_VECTOR ( 7 downto 0 );
    ap_clk : in STD_LOGIC;
    ap_ctrl_1_done : out STD_LOGIC;
    ap_ctrl_1_idle : out STD_LOGIC;
    ap_ctrl_1_ready : out STD_LOGIC;
    ap_ctrl_1_start : in STD_LOGIC;
    ap_ctrl_2_done : out STD_LOGIC;
    ap_ctrl_2_idle : out STD_LOGIC;
    ap_ctrl_2_ready : out STD_LOGIC;
    ap_ctrl_2_start : in STD_LOGIC;
    ap_ctrl_done : out STD_LOGIC;
    ap_ctrl_idle : out STD_LOGIC;
    ap_ctrl_ready : out STD_LOGIC;
    ap_ctrl_start : in STD_LOGIC;
    ap_return : out STD_LOGIC_VECTOR ( 7 downto 0 );
    ap_return_1 : out STD_LOGIC_VECTOR ( 7 downto 0 );
    ap_return_2 : out STD_LOGIC_VECTOR ( 7 downto 0 );
    ap_rst : in STD_LOGIC
  );
end design_1_wrapper;

architecture STRUCTURE of design_1_wrapper is
  component design_1 is
  port (
    ap_clk : in STD_LOGIC;
    ap_rst : in STD_LOGIC;
    R : in STD_LOGIC_VECTOR ( 7 downto 0 );
    G : in STD_LOGIC_VECTOR ( 7 downto 0 );
    B : in STD_LOGIC_VECTOR ( 7 downto 0 );
    ap_return : out STD_LOGIC_VECTOR ( 7 downto 0 );
    ap_return_1 : out STD_LOGIC_VECTOR ( 7 downto 0 );
    ap_return_2 : out STD_LOGIC_VECTOR ( 7 downto 0 );
    ap_ctrl_start : in STD_LOGIC;
    ap_ctrl_done : out STD_LOGIC;
    ap_ctrl_idle : out STD_LOGIC;
    ap_ctrl_ready : out STD_LOGIC;
    ap_ctrl_1_start : in STD_LOGIC;
    ap_ctrl_1_done : out STD_LOGIC;
    ap_ctrl_1_idle : out STD_LOGIC;
    ap_ctrl_1_ready : out STD_LOGIC;
    ap_ctrl_2_start : in STD_LOGIC;
    ap_ctrl_2_done : out STD_LOGIC;
    ap_ctrl_2_idle : out STD_LOGIC;
    ap_ctrl_2_ready : out STD_LOGIC
  );
  end component design_1;
begin
design_1_i: component design_1
     port map (
      B(7 downto 0) => B(7 downto 0),
      G(7 downto 0) => G(7 downto 0),
      R(7 downto 0) => R(7 downto 0),
      ap_clk => ap_clk,
      ap_ctrl_1_done => ap_ctrl_1_done,
      ap_ctrl_1_idle => ap_ctrl_1_idle,
      ap_ctrl_1_ready => ap_ctrl_1_ready,
      ap_ctrl_1_start => ap_ctrl_1_start,
      ap_ctrl_2_done => ap_ctrl_2_done,
      ap_ctrl_2_idle => ap_ctrl_2_idle,
      ap_ctrl_2_ready => ap_ctrl_2_ready,
      ap_ctrl_2_start => ap_ctrl_2_start,
      ap_ctrl_done => ap_ctrl_done,
      ap_ctrl_idle => ap_ctrl_idle,
      ap_ctrl_ready => ap_ctrl_ready,
      ap_ctrl_start => ap_ctrl_start,
      ap_return(7 downto 0) => ap_return(7 downto 0),
      ap_return_1(7 downto 0) => ap_return_1(7 downto 0),
      ap_return_2(7 downto 0) => ap_return_2(7 downto 0),
      ap_rst => ap_rst
    );
end STRUCTURE;
