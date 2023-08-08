--Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
----------------------------------------------------------------------------------
--Tool Version: Vivado v.2019.1 (win64) Build 2552052 Fri May 24 14:49:42 MDT 2019
--Date        : Sun Aug  6 20:08:43 2023
--Host        : DESKTOP-NSCBN50 running 64-bit major release  (build 9200)
--Command     : generate_target design_1.bd
--Design      : design_1
--Purpose     : IP block netlist
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity design_1 is
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
  attribute CORE_GENERATION_INFO : string;
  attribute CORE_GENERATION_INFO of design_1 : entity is "design_1,IP_Integrator,{x_ipVendor=xilinx.com,x_ipLibrary=BlockDiagram,x_ipName=design_1,x_ipVersion=1.00.a,x_ipLanguage=VHDL,numBlks=3,numReposBlks=3,numNonXlnxBlks=0,numHierBlks=0,maxHierDepth=0,numSysgenBlks=0,numHlsBlks=3,numHdlrefBlks=0,numPkgbdBlks=0,bdsource=USER,synth_mode=OOC_per_IP}";
  attribute HW_HANDOFF : string;
  attribute HW_HANDOFF of design_1 : entity is "design_1.hwdef";
end design_1;

architecture STRUCTURE of design_1 is
  component design_1_Y_0_0 is
  port (
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
  end component design_1_Y_0_0;
  component design_1_Cb_0_0 is
  port (
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
  end component design_1_Cb_0_0;
  component design_1_Cr_0_0 is
  port (
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
  end component design_1_Cr_0_0;
  signal B_1 : STD_LOGIC_VECTOR ( 7 downto 0 );
  signal Cb_0_ap_return : STD_LOGIC_VECTOR ( 7 downto 0 );
  signal Cr_0_ap_return : STD_LOGIC_VECTOR ( 7 downto 0 );
  signal G_1 : STD_LOGIC_VECTOR ( 7 downto 0 );
  signal R_1 : STD_LOGIC_VECTOR ( 7 downto 0 );
  signal Y_0_ap_return : STD_LOGIC_VECTOR ( 7 downto 0 );
  signal ap_clk_1 : STD_LOGIC;
  signal ap_ctrl_1_1_done : STD_LOGIC;
  signal ap_ctrl_1_1_idle : STD_LOGIC;
  signal ap_ctrl_1_1_ready : STD_LOGIC;
  signal ap_ctrl_1_1_start : STD_LOGIC;
  signal \^ap_ctrl_1_done\ : STD_LOGIC;
  signal \^ap_ctrl_1_idle\ : STD_LOGIC;
  signal \^ap_ctrl_1_ready\ : STD_LOGIC;
  signal \^ap_ctrl_1_start\ : STD_LOGIC;
  signal ap_ctrl_2_1_done : STD_LOGIC;
  signal ap_ctrl_2_1_idle : STD_LOGIC;
  signal ap_ctrl_2_1_ready : STD_LOGIC;
  signal ap_ctrl_2_1_start : STD_LOGIC;
  signal ap_rst_1 : STD_LOGIC;
  attribute X_INTERFACE_INFO : string;
  attribute X_INTERFACE_INFO of ap_clk : signal is "xilinx.com:signal:clock:1.0 CLK.AP_CLK CLK";
  attribute X_INTERFACE_PARAMETER : string;
  attribute X_INTERFACE_PARAMETER of ap_clk : signal is "XIL_INTERFACENAME CLK.AP_CLK, ASSOCIATED_RESET ap_rst, CLK_DOMAIN design_1_ap_clk, FREQ_HZ 100000000, INSERT_VIP 0, PHASE 0.000";
  attribute X_INTERFACE_INFO of ap_ctrl_1_done : signal is "xilinx.com:interface:acc_handshake:1.0 ap_ctrl_1 done";
  attribute X_INTERFACE_INFO of ap_ctrl_1_idle : signal is "xilinx.com:interface:acc_handshake:1.0 ap_ctrl_1 idle";
  attribute X_INTERFACE_INFO of ap_ctrl_1_ready : signal is "xilinx.com:interface:acc_handshake:1.0 ap_ctrl_1 ready";
  attribute X_INTERFACE_INFO of ap_ctrl_1_start : signal is "xilinx.com:interface:acc_handshake:1.0 ap_ctrl_1 start";
  attribute X_INTERFACE_INFO of ap_ctrl_2_done : signal is "xilinx.com:interface:acc_handshake:1.0 ap_ctrl_2 done";
  attribute X_INTERFACE_INFO of ap_ctrl_2_idle : signal is "xilinx.com:interface:acc_handshake:1.0 ap_ctrl_2 idle";
  attribute X_INTERFACE_INFO of ap_ctrl_2_ready : signal is "xilinx.com:interface:acc_handshake:1.0 ap_ctrl_2 ready";
  attribute X_INTERFACE_INFO of ap_ctrl_2_start : signal is "xilinx.com:interface:acc_handshake:1.0 ap_ctrl_2 start";
  attribute X_INTERFACE_INFO of ap_ctrl_done : signal is "xilinx.com:interface:acc_handshake:1.0 ap_ctrl done";
  attribute X_INTERFACE_INFO of ap_ctrl_idle : signal is "xilinx.com:interface:acc_handshake:1.0 ap_ctrl idle";
  attribute X_INTERFACE_INFO of ap_ctrl_ready : signal is "xilinx.com:interface:acc_handshake:1.0 ap_ctrl ready";
  attribute X_INTERFACE_INFO of ap_ctrl_start : signal is "xilinx.com:interface:acc_handshake:1.0 ap_ctrl start";
  attribute X_INTERFACE_INFO of ap_rst : signal is "xilinx.com:signal:reset:1.0 RST.AP_RST RST";
  attribute X_INTERFACE_PARAMETER of ap_rst : signal is "XIL_INTERFACENAME RST.AP_RST, INSERT_VIP 0, POLARITY ACTIVE_HIGH";
  attribute X_INTERFACE_INFO of B : signal is "xilinx.com:signal:data:1.0 DATA.B DATA";
  attribute X_INTERFACE_PARAMETER of B : signal is "XIL_INTERFACENAME DATA.B, LAYERED_METADATA undef";
  attribute X_INTERFACE_INFO of G : signal is "xilinx.com:signal:data:1.0 DATA.G DATA";
  attribute X_INTERFACE_PARAMETER of G : signal is "XIL_INTERFACENAME DATA.G, LAYERED_METADATA undef";
  attribute X_INTERFACE_INFO of R : signal is "xilinx.com:signal:data:1.0 DATA.R DATA";
  attribute X_INTERFACE_PARAMETER of R : signal is "XIL_INTERFACENAME DATA.R, LAYERED_METADATA undef";
  attribute X_INTERFACE_INFO of ap_return : signal is "xilinx.com:signal:data:1.0 DATA.AP_RETURN DATA";
  attribute X_INTERFACE_PARAMETER of ap_return : signal is "XIL_INTERFACENAME DATA.AP_RETURN, LAYERED_METADATA undef";
  attribute X_INTERFACE_INFO of ap_return_1 : signal is "xilinx.com:signal:data:1.0 DATA.AP_RETURN_1 DATA";
  attribute X_INTERFACE_PARAMETER of ap_return_1 : signal is "XIL_INTERFACENAME DATA.AP_RETURN_1, LAYERED_METADATA undef";
  attribute X_INTERFACE_INFO of ap_return_2 : signal is "xilinx.com:signal:data:1.0 DATA.AP_RETURN_2 DATA";
  attribute X_INTERFACE_PARAMETER of ap_return_2 : signal is "XIL_INTERFACENAME DATA.AP_RETURN_2, LAYERED_METADATA undef";
begin
  B_1(7 downto 0) <= B(7 downto 0);
  G_1(7 downto 0) <= G(7 downto 0);
  R_1(7 downto 0) <= R(7 downto 0);
  \^ap_ctrl_1_start\ <= ap_ctrl_start;
  ap_clk_1 <= ap_clk;
  ap_ctrl_1_1_start <= ap_ctrl_1_start;
  ap_ctrl_1_done <= ap_ctrl_1_1_done;
  ap_ctrl_1_idle <= ap_ctrl_1_1_idle;
  ap_ctrl_1_ready <= ap_ctrl_1_1_ready;
  ap_ctrl_2_1_start <= ap_ctrl_2_start;
  ap_ctrl_2_done <= ap_ctrl_2_1_done;
  ap_ctrl_2_idle <= ap_ctrl_2_1_idle;
  ap_ctrl_2_ready <= ap_ctrl_2_1_ready;
  ap_ctrl_done <= \^ap_ctrl_1_done\;
  ap_ctrl_idle <= \^ap_ctrl_1_idle\;
  ap_ctrl_ready <= \^ap_ctrl_1_ready\;
  ap_return(7 downto 0) <= Y_0_ap_return(7 downto 0);
  ap_return_1(7 downto 0) <= Cb_0_ap_return(7 downto 0);
  ap_return_2(7 downto 0) <= Cr_0_ap_return(7 downto 0);
  ap_rst_1 <= ap_rst;
Cb_0: component design_1_Cb_0_0
     port map (
      B(7 downto 0) => B_1(7 downto 0),
      G(7 downto 0) => G_1(7 downto 0),
      R(7 downto 0) => R_1(7 downto 0),
      ap_clk => ap_clk_1,
      ap_done => ap_ctrl_1_1_done,
      ap_idle => ap_ctrl_1_1_idle,
      ap_ready => ap_ctrl_1_1_ready,
      ap_return(7 downto 0) => Cb_0_ap_return(7 downto 0),
      ap_rst => ap_rst_1,
      ap_start => ap_ctrl_1_1_start
    );
Cr_0: component design_1_Cr_0_0
     port map (
      B(7 downto 0) => B_1(7 downto 0),
      G(7 downto 0) => G_1(7 downto 0),
      R(7 downto 0) => R_1(7 downto 0),
      ap_clk => ap_clk_1,
      ap_done => ap_ctrl_2_1_done,
      ap_idle => ap_ctrl_2_1_idle,
      ap_ready => ap_ctrl_2_1_ready,
      ap_return(7 downto 0) => Cr_0_ap_return(7 downto 0),
      ap_rst => ap_rst_1,
      ap_start => ap_ctrl_2_1_start
    );
Y_0: component design_1_Y_0_0
     port map (
      B(7 downto 0) => B_1(7 downto 0),
      G(7 downto 0) => G_1(7 downto 0),
      R(7 downto 0) => R_1(7 downto 0),
      ap_clk => ap_clk_1,
      ap_done => \^ap_ctrl_1_done\,
      ap_idle => \^ap_ctrl_1_idle\,
      ap_ready => \^ap_ctrl_1_ready\,
      ap_return(7 downto 0) => Y_0_ap_return(7 downto 0),
      ap_rst => ap_rst_1,
      ap_start => \^ap_ctrl_1_start\
    );
end STRUCTURE;
