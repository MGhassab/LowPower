----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 07/29/2023 04:11:30 PM
-- Design Name: 
-- Module Name: memoization - memoization_beh
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.all;
-- library UNISIM;
-- use UNISIM.VComponents.all;

entity memoization is
port ( 	
        clk	        : 	  in std_logic;
		rst		    : 	  in std_logic;
		start      	:	  in std_logic;
		input 	    :	  in std_logic_vector(7 downto 0);
		row   	    :	  in std_logic_vector(7 downto 0);
		column 	    :	  in std_logic_vector(7 downto 0);
        trigger     :     out std_logic;
		output    	:	  inout std_logic_vector(7 downto 0)		
);
end memoization;

architecture memoization_beh of memoization is
 type ram_type is array (0 to 999) of std_logic_vector (7 downto 0);    -- define 100000x8 bit RAM Type        
 type rom_type is array (0 to 255) of std_logic_vector (7 downto 0);    -- define 100000x8 bit RAM Type        
    type    state_type  is  (idle,start_rows,approximate,proces);                        -- State = idle  ,  start_rows  ,  proces 
    signal state_reg , state_next     : state_type;                          -- state register                    
    signal in_ram                     : ram_type;                            -- input Ram for save inputs(4 rows)
    signal data_in                    : std_logic_vector(7 downto 0);                    -- Input Port RAM_IN
    signal data_in_mem                : std_logic_vector(7 downto 0);     
    signal data_out                   : std_logic_vector(15 downto 0);                    -- Ouput Port RAM_IN_Memoization
    signal data_out_1                 : std_logic_vector(7 downto 0) := in_ram(0);       -- use for compute filter output . GET pixel value form input RAM
    signal data_out_2                 : std_logic_vector(7 downto 0) := in_ram(1);       -- use for compute filter output . GET pixel value form input RAM
    signal data_out_3                 : std_logic_vector(7 downto 0) := in_ram(2);       -- use for compute filter output . GET pixel value form input RAM
    signal data_out_4                 : std_logic_vector(7 downto 0) := in_ram(3);       -- use for compute filter output . GET pixel value form input RAM
    signal data_out_5                 : std_logic_vector(7 downto 0) := in_ram(4);       -- use for compute filter output . GET pixel value form input RAM
    signal data_out_6                 : std_logic_vector(7 downto 0) := in_ram(5);       -- use for compute filter output . GET pixel value form input RAM
    signal data_out_7                 : std_logic_vector(7 downto 0) := in_ram(6);       -- use for compute filter output . GET pixel value form input RAM
    signal data_out_8                 : std_logic_vector(7 downto 0) := in_ram(7);       -- use for compute filter output . GET pixel value form input RAM
    signal data_out_9                 : std_logic_vector(7 downto 0) := in_ram(8);       -- use for compute filter output . GET pixel value form input RAM
    signal add_inram_reg , add_inram_next : std_logic_vector(15 downto 0) := (others => '0');   -- Address RAM_IN
    signal diff_cntr_reg , diff_cntr_next : std_logic_vector(15 downto 0) := (others => '0');
    signal column_cntr_reg , column_cntr_next : std_logic_vector(7 downto 0) := (others => '0');  
    signal threshold  : std_logic_vector(15 downto 0) := "0000000000001010";  -- make constant 1 for multiplexer
    signal writeSignal_reg, writeSignal_next  : std_logic; 
    signal trigger_reg, trigger_next  : std_logic; 
    signal last_ram_addr  : std_logic_vector(15 downto 0) := std_logic_vector(to_unsigned(255,16));
    signal one  : std_logic_vector(7 downto 0) := "00000001";  -- make constant 1 for multiplexer
    signal four : std_logic_vector(7 downto 0) := "00000100";  -- make constant 4 for multiplexer
    signal temp4 , temp1 : std_logic_vector(15 downto 0);  -- temporary signal
    signal in_memoizated: rom_type :=(
        std_logic_vector(to_unsigned(186,8)),std_logic_vector(to_unsigned(171,8)),std_logic_vector(to_unsigned(158,8)),std_logic_vector(to_unsigned(170,8)),std_logic_vector(to_unsigned(169,8)),std_logic_vector(to_unsigned(165,8)),std_logic_vector(to_unsigned(222,8)),std_logic_vector(to_unsigned(202,8)),std_logic_vector(to_unsigned(193,8)),std_logic_vector(to_unsigned(166,8)),std_logic_vector(to_unsigned(151,8)),std_logic_vector(to_unsigned(112,8)),std_logic_vector(to_unsigned(140,8)),std_logic_vector(to_unsigned(95,8)),std_logic_vector(to_unsigned(89,8)),std_logic_vector(to_unsigned(116,8)),
        std_logic_vector(to_unsigned(176,8)),std_logic_vector(to_unsigned(164,8)),std_logic_vector(to_unsigned(151,8)),std_logic_vector(to_unsigned(162,8)),std_logic_vector(to_unsigned(157,8)),std_logic_vector(to_unsigned(189,8)),std_logic_vector(to_unsigned(225,8)),std_logic_vector(to_unsigned(203,8)),std_logic_vector(to_unsigned(194,8)),std_logic_vector(to_unsigned(172,8)),std_logic_vector(to_unsigned(151,8)),std_logic_vector(to_unsigned(113,8)),std_logic_vector(to_unsigned(118,8)),std_logic_vector(to_unsigned(98,8)),std_logic_vector(to_unsigned(118,8)),std_logic_vector(to_unsigned(121,8)),
        std_logic_vector(to_unsigned(162,8)),std_logic_vector(to_unsigned(154,8)),std_logic_vector(to_unsigned(146,8)),std_logic_vector(to_unsigned(150,8)),std_logic_vector(to_unsigned(150,8)),std_logic_vector(to_unsigned(184,8)),std_logic_vector(to_unsigned(222,8)),std_logic_vector(to_unsigned(206,8)),std_logic_vector(to_unsigned(194,8)),std_logic_vector(to_unsigned(167,8)),std_logic_vector(to_unsigned(151,8)),std_logic_vector(to_unsigned(117,8)),std_logic_vector(to_unsigned(100,8)),std_logic_vector(to_unsigned(108,8)),std_logic_vector(to_unsigned(135,8)),std_logic_vector(to_unsigned(107,8)),
        std_logic_vector(to_unsigned(152,8)),std_logic_vector(to_unsigned(150,8)),std_logic_vector(to_unsigned(133,8)),std_logic_vector(to_unsigned(139,8)),std_logic_vector(to_unsigned(130,8)),std_logic_vector(to_unsigned(167,8)),std_logic_vector(to_unsigned(227,8)),std_logic_vector(to_unsigned(198,8)),std_logic_vector(to_unsigned(115,8)),std_logic_vector(to_unsigned(82,8)),std_logic_vector(to_unsigned(94,8)),std_logic_vector(to_unsigned(127,8)),std_logic_vector(to_unsigned(126,8)),std_logic_vector(to_unsigned(107,8)),std_logic_vector(to_unsigned(130,8)),std_logic_vector(to_unsigned(102,8)),
        std_logic_vector(to_unsigned(154,8)),std_logic_vector(to_unsigned(146,8)),std_logic_vector(to_unsigned(134,8)),std_logic_vector(to_unsigned(130,8)),std_logic_vector(to_unsigned(157,8)),std_logic_vector(to_unsigned(202,8)),std_logic_vector(to_unsigned(187,8)),std_logic_vector(to_unsigned(99,8)),std_logic_vector(to_unsigned(67,8)),std_logic_vector(to_unsigned(83,8)),std_logic_vector(to_unsigned(76,8)),std_logic_vector(to_unsigned(79,8)),std_logic_vector(to_unsigned(127,8)),std_logic_vector(to_unsigned(107,8)),std_logic_vector(to_unsigned(101,8)),std_logic_vector(to_unsigned(87,8)),
        std_logic_vector(to_unsigned(141,8)),std_logic_vector(to_unsigned(135,8)),std_logic_vector(to_unsigned(145,8)),std_logic_vector(to_unsigned(179,8)),std_logic_vector(to_unsigned(197,8)),std_logic_vector(to_unsigned(159,8)),std_logic_vector(to_unsigned(102,8)),std_logic_vector(to_unsigned(85,8)),std_logic_vector(to_unsigned(82,8)),std_logic_vector(to_unsigned(83,8)),std_logic_vector(to_unsigned(78,8)),std_logic_vector(to_unsigned(64,8)),std_logic_vector(to_unsigned(96,8)),std_logic_vector(to_unsigned(105,8)),std_logic_vector(to_unsigned(79,8)),std_logic_vector(to_unsigned(81,8)),
        std_logic_vector(to_unsigned(134,8)),std_logic_vector(to_unsigned(129,8)),std_logic_vector(to_unsigned(134,8)),std_logic_vector(to_unsigned(179,8)),std_logic_vector(to_unsigned(187,8)),std_logic_vector(to_unsigned(144,8)),std_logic_vector(to_unsigned(108,8)),std_logic_vector(to_unsigned(107,8)),std_logic_vector(to_unsigned(88,8)),std_logic_vector(to_unsigned(88,8)),std_logic_vector(to_unsigned(76,8)),std_logic_vector(to_unsigned(62,8)),std_logic_vector(to_unsigned(72,8)),std_logic_vector(to_unsigned(93,8)),std_logic_vector(to_unsigned(75,8)),std_logic_vector(to_unsigned(90,8)),
        std_logic_vector(to_unsigned(114,8)),std_logic_vector(to_unsigned(123,8)),std_logic_vector(to_unsigned(119,8)),std_logic_vector(to_unsigned(143,8)),std_logic_vector(to_unsigned(182,8)),std_logic_vector(to_unsigned(166,8)),std_logic_vector(to_unsigned(144,8)),std_logic_vector(to_unsigned(134,8)),std_logic_vector(to_unsigned(115,8)),std_logic_vector(to_unsigned(113,8)),std_logic_vector(to_unsigned(73,8)),std_logic_vector(to_unsigned(63,8)),std_logic_vector(to_unsigned(70,8)),std_logic_vector(to_unsigned(97,8)),std_logic_vector(to_unsigned(96,8)),std_logic_vector(to_unsigned(105,8)),
        std_logic_vector(to_unsigned(107,8)),std_logic_vector(to_unsigned(132,8)),std_logic_vector(to_unsigned(129,8)),std_logic_vector(to_unsigned(128,8)),std_logic_vector(to_unsigned(132,8)),std_logic_vector(to_unsigned(141,8)),std_logic_vector(to_unsigned(151,8)),std_logic_vector(to_unsigned(137,8)),std_logic_vector(to_unsigned(105,8)),std_logic_vector(to_unsigned(104,8)),std_logic_vector(to_unsigned(79,8)),std_logic_vector(to_unsigned(56,8)),std_logic_vector(to_unsigned(74,8)),std_logic_vector(to_unsigned(121,8)),std_logic_vector(to_unsigned(129,8)),std_logic_vector(to_unsigned(124,8)),
        std_logic_vector(to_unsigned(123,8)),std_logic_vector(to_unsigned(143,8)),std_logic_vector(to_unsigned(145,8)),std_logic_vector(to_unsigned(131,8)),std_logic_vector(to_unsigned(132,8)),std_logic_vector(to_unsigned(110,8)),std_logic_vector(to_unsigned(134,8)),std_logic_vector(to_unsigned(150,8)),std_logic_vector(to_unsigned(132,8)),std_logic_vector(to_unsigned(114,8)),std_logic_vector(to_unsigned(126,8)),std_logic_vector(to_unsigned(127,8)),std_logic_vector(to_unsigned(119,8)),std_logic_vector(to_unsigned(123,8)),std_logic_vector(to_unsigned(144,8)),std_logic_vector(to_unsigned(139,8)),
        std_logic_vector(to_unsigned(133,8)),std_logic_vector(to_unsigned(148,8)),std_logic_vector(to_unsigned(138,8)),std_logic_vector(to_unsigned(138,8)),std_logic_vector(to_unsigned(128,8)),std_logic_vector(to_unsigned(107,8)),std_logic_vector(to_unsigned(125,8)),std_logic_vector(to_unsigned(153,8)),std_logic_vector(to_unsigned(164,8)),std_logic_vector(to_unsigned(187,8)),std_logic_vector(to_unsigned(169,8)),std_logic_vector(to_unsigned(156,8)),std_logic_vector(to_unsigned(153,8)),std_logic_vector(to_unsigned(150,8)),std_logic_vector(to_unsigned(114,8)),std_logic_vector(to_unsigned(131,8)),
        std_logic_vector(to_unsigned(135,8)),std_logic_vector(to_unsigned(127,8)),std_logic_vector(to_unsigned(124,8)),std_logic_vector(to_unsigned(139,8)),std_logic_vector(to_unsigned(129,8)),std_logic_vector(to_unsigned(113,8)),std_logic_vector(to_unsigned(119,8)),std_logic_vector(to_unsigned(165,8)),std_logic_vector(to_unsigned(195,8)),std_logic_vector(to_unsigned(176,8)),std_logic_vector(to_unsigned(164,8)),std_logic_vector(to_unsigned(167,8)),std_logic_vector(to_unsigned(147,8)),std_logic_vector(to_unsigned(163,8)),std_logic_vector(to_unsigned(168,8)),std_logic_vector(to_unsigned(134,8)),
        std_logic_vector(to_unsigned(125,8)),std_logic_vector(to_unsigned(117,8)),std_logic_vector(to_unsigned(119,8)),std_logic_vector(to_unsigned(117,8)),std_logic_vector(to_unsigned(108,8)),std_logic_vector(to_unsigned(120,8)),std_logic_vector(to_unsigned(158,8)),std_logic_vector(to_unsigned(167,8)),std_logic_vector(to_unsigned(172,8)),std_logic_vector(to_unsigned(158,8)),std_logic_vector(to_unsigned(167,8)),std_logic_vector(to_unsigned(169,8)),std_logic_vector(to_unsigned(165,8)),std_logic_vector(to_unsigned(159,8)),std_logic_vector(to_unsigned(194,8)),std_logic_vector(to_unsigned(161,8)),
        std_logic_vector(to_unsigned(120,8)),std_logic_vector(to_unsigned(136,8)),std_logic_vector(to_unsigned(129,8)),std_logic_vector(to_unsigned(123,8)),std_logic_vector(to_unsigned(115,8)),std_logic_vector(to_unsigned(156,8)),std_logic_vector(to_unsigned(167,8)),std_logic_vector(to_unsigned(170,8)),std_logic_vector(to_unsigned(146,8)),std_logic_vector(to_unsigned(132,8)),std_logic_vector(to_unsigned(168,8)),std_logic_vector(to_unsigned(167,8)),std_logic_vector(to_unsigned(182,8)),std_logic_vector(to_unsigned(176,8)),std_logic_vector(to_unsigned(162,8)),std_logic_vector(to_unsigned(164,8)),
        std_logic_vector(to_unsigned(137,8)),std_logic_vector(to_unsigned(134,8)),std_logic_vector(to_unsigned(128,8)),std_logic_vector(to_unsigned(120,8)),std_logic_vector(to_unsigned(105,8)),std_logic_vector(to_unsigned(165,8)),std_logic_vector(to_unsigned(168,8)),std_logic_vector(to_unsigned(180,8)),std_logic_vector(to_unsigned(143,8)),std_logic_vector(to_unsigned(111,8)),std_logic_vector(to_unsigned(131,8)),std_logic_vector(to_unsigned(170,8)),std_logic_vector(to_unsigned(191,8)),std_logic_vector(to_unsigned(186,8)),std_logic_vector(to_unsigned(140,8)),std_logic_vector(to_unsigned(183,8)),
        std_logic_vector(to_unsigned(113,8)),std_logic_vector(to_unsigned(120,8)),std_logic_vector(to_unsigned(106,8)),std_logic_vector(to_unsigned(72,8)),std_logic_vector(to_unsigned(115,8)),std_logic_vector(to_unsigned(184,8)),std_logic_vector(to_unsigned(176,8)),std_logic_vector(to_unsigned(159,8)),std_logic_vector(to_unsigned(130,8)),std_logic_vector(to_unsigned(111,8)),std_logic_vector(to_unsigned(84,8)),std_logic_vector(to_unsigned(172,8)),std_logic_vector(to_unsigned(161,8)),std_logic_vector(to_unsigned(148,8)),std_logic_vector(to_unsigned(143,8)),std_logic_vector(to_unsigned(140,8))   
        );

    signal out_memoizated: rom_type :=(
        std_logic_vector(to_unsigned(105,8)),std_logic_vector(to_unsigned(0,8)),std_logic_vector(to_unsigned(99,8)),std_logic_vector(to_unsigned(0,8)),std_logic_vector(to_unsigned(101,8)),std_logic_vector(to_unsigned(0,8)),std_logic_vector(to_unsigned(92,8)),std_logic_vector(to_unsigned(0,8)),std_logic_vector(to_unsigned(72,8)),std_logic_vector(to_unsigned(0,8)),std_logic_vector(to_unsigned(97,8)),std_logic_vector(to_unsigned(0,8)),std_logic_vector(to_unsigned(114,8)),std_logic_vector(to_unsigned(0,8)),std_logic_vector(to_unsigned(100,8)),std_logic_vector(to_unsigned(0,8)),
        std_logic_vector(to_unsigned(152,8)),std_logic_vector(to_unsigned(4,8)),std_logic_vector(to_unsigned(26,8)),std_logic_vector(to_unsigned(20,8)),std_logic_vector(to_unsigned(42,8)),std_logic_vector(to_unsigned(25,8)),std_logic_vector(to_unsigned(64,8)),std_logic_vector(to_unsigned(15,8)),std_logic_vector(to_unsigned(14,8)),std_logic_vector(to_unsigned(10,8)),std_logic_vector(to_unsigned(17,8)),std_logic_vector(to_unsigned(46,8)),std_logic_vector(to_unsigned(21,8)),std_logic_vector(to_unsigned(47,8)),std_logic_vector(to_unsigned(29,8)),std_logic_vector(to_unsigned(0,8)),
        std_logic_vector(to_unsigned(109,8)),std_logic_vector(to_unsigned(6,8)),std_logic_vector(to_unsigned(4,8)),std_logic_vector(to_unsigned(3,8)),std_logic_vector(to_unsigned(21,8)),std_logic_vector(to_unsigned(8,8)),std_logic_vector(to_unsigned(46,8)),std_logic_vector(to_unsigned(7,8)),std_logic_vector(to_unsigned(94,8)),std_logic_vector(to_unsigned(69,8)),std_logic_vector(to_unsigned(75,8)),std_logic_vector(to_unsigned(23,8)),std_logic_vector(to_unsigned(69,8)),std_logic_vector(to_unsigned(8,8)),std_logic_vector(to_unsigned(77,8)),std_logic_vector(to_unsigned(0,8)),
        std_logic_vector(to_unsigned(115,8)),std_logic_vector(to_unsigned(15,8)),std_logic_vector(to_unsigned(37,8)),std_logic_vector(to_unsigned(13,8)),std_logic_vector(to_unsigned(93,8)),std_logic_vector(to_unsigned(75,8)),std_logic_vector(to_unsigned(134,8)),std_logic_vector(to_unsigned(145,8)),std_logic_vector(to_unsigned(81,8)),std_logic_vector(to_unsigned(131,8)),std_logic_vector(to_unsigned(60,8)),std_logic_vector(to_unsigned(92,8)),std_logic_vector(to_unsigned(43,8)),std_logic_vector(to_unsigned(43,8)),std_logic_vector(to_unsigned(75,8)),std_logic_vector(to_unsigned(0,8)),
        std_logic_vector(to_unsigned(68,8)),std_logic_vector(to_unsigned(11,8)),std_logic_vector(to_unsigned(18,8)),std_logic_vector(to_unsigned(89,8)),std_logic_vector(to_unsigned(31,8)),std_logic_vector(to_unsigned(138,8)),std_logic_vector(to_unsigned(118,8)),std_logic_vector(to_unsigned(141,8)),std_logic_vector(to_unsigned(111,8)),std_logic_vector(to_unsigned(24,8)),std_logic_vector(to_unsigned(30,8)),std_logic_vector(to_unsigned(78,8)),std_logic_vector(to_unsigned(100,8)),std_logic_vector(to_unsigned(12,8)),std_logic_vector(to_unsigned(1,8)),std_logic_vector(to_unsigned(0,8)),
        std_logic_vector(to_unsigned(76,8)),std_logic_vector(to_unsigned(21,8)),std_logic_vector(to_unsigned(2,8)),std_logic_vector(to_unsigned(65,8)),std_logic_vector(to_unsigned(106,8)),std_logic_vector(to_unsigned(9,8)),std_logic_vector(to_unsigned(131,8)),std_logic_vector(to_unsigned(50,8)),std_logic_vector(to_unsigned(5,8)),std_logic_vector(to_unsigned(1,8)),std_logic_vector(to_unsigned(13,8)),std_logic_vector(to_unsigned(59,8)),std_logic_vector(to_unsigned(16,8)),std_logic_vector(to_unsigned(45,8)),std_logic_vector(to_unsigned(46,8)),std_logic_vector(to_unsigned(0,8)),
        std_logic_vector(to_unsigned(92,8)),std_logic_vector(to_unsigned(10,8)),std_logic_vector(to_unsigned(36,8)),std_logic_vector(to_unsigned(73,8)),std_logic_vector(to_unsigned(46,8)),std_logic_vector(to_unsigned(44,8)),std_logic_vector(to_unsigned(65,8)),std_logic_vector(to_unsigned(13,8)),std_logic_vector(to_unsigned(40,8)),std_logic_vector(to_unsigned(8,8)),std_logic_vector(to_unsigned(3,8)),std_logic_vector(to_unsigned(27,8)),std_logic_vector(to_unsigned(33,8)),std_logic_vector(to_unsigned(23,8)),std_logic_vector(to_unsigned(58,8)),std_logic_vector(to_unsigned(0,8)),
        std_logic_vector(to_unsigned(109,8)),std_logic_vector(to_unsigned(2,8)),std_logic_vector(to_unsigned(53,8)),std_logic_vector(to_unsigned(36,8)),std_logic_vector(to_unsigned(100,8)),std_logic_vector(to_unsigned(53,8)),std_logic_vector(to_unsigned(17,8)),std_logic_vector(to_unsigned(33,8)),std_logic_vector(to_unsigned(20,8)),std_logic_vector(to_unsigned(72,8)),std_logic_vector(to_unsigned(39,8)),std_logic_vector(to_unsigned(9,8)),std_logic_vector(to_unsigned(26,8)),std_logic_vector(to_unsigned(8,8)),std_logic_vector(to_unsigned(22,8)),std_logic_vector(to_unsigned(0,8)),
        std_logic_vector(to_unsigned(101,8)),std_logic_vector(to_unsigned(26,8)),std_logic_vector(to_unsigned(8,8)),std_logic_vector(to_unsigned(23,8)),std_logic_vector(to_unsigned(55,8)),std_logic_vector(to_unsigned(5,8)),std_logic_vector(to_unsigned(48,8)),std_logic_vector(to_unsigned(8,8)),std_logic_vector(to_unsigned(68,8)),std_logic_vector(to_unsigned(5,8)),std_logic_vector(to_unsigned(43,8)),std_logic_vector(to_unsigned(119,8)),std_logic_vector(to_unsigned(70,8)),std_logic_vector(to_unsigned(61,8)),std_logic_vector(to_unsigned(31,8)),std_logic_vector(to_unsigned(0,8)),
        std_logic_vector(to_unsigned(160,8)),std_logic_vector(to_unsigned(24,8)),std_logic_vector(to_unsigned(39,8)),std_logic_vector(to_unsigned(19,8)),std_logic_vector(to_unsigned(27,8)),std_logic_vector(to_unsigned(74,8)),std_logic_vector(to_unsigned(0,8)),std_logic_vector(to_unsigned(44,8)),std_logic_vector(to_unsigned(5,8)),std_logic_vector(to_unsigned(93,8)),std_logic_vector(to_unsigned(15,8)),std_logic_vector(to_unsigned(51,8)),std_logic_vector(to_unsigned(1,8)),std_logic_vector(to_unsigned(42,8)),std_logic_vector(to_unsigned(71,8)),std_logic_vector(to_unsigned(0,8)),
        std_logic_vector(to_unsigned(0,8)),std_logic_vector(to_unsigned(51,8)),std_logic_vector(to_unsigned(3,8)),std_logic_vector(to_unsigned(16,8)),std_logic_vector(to_unsigned(6,8)),std_logic_vector(to_unsigned(48,8)),std_logic_vector(to_unsigned(13,8)),std_logic_vector(to_unsigned(8,8)),std_logic_vector(to_unsigned(11,8)),std_logic_vector(to_unsigned(125,8)),std_logic_vector(to_unsigned(43,8)),std_logic_vector(to_unsigned(8,8)),std_logic_vector(to_unsigned(40,8)),std_logic_vector(to_unsigned(47,8)),std_logic_vector(to_unsigned(137,8)),std_logic_vector(to_unsigned(0,8)),
        std_logic_vector(to_unsigned(64,8)),std_logic_vector(to_unsigned(16,8)),std_logic_vector(to_unsigned(27,8)),std_logic_vector(to_unsigned(48,8)),std_logic_vector(to_unsigned(28,8)),std_logic_vector(to_unsigned(23,8)),std_logic_vector(to_unsigned(85,8)),std_logic_vector(to_unsigned(26,8)),std_logic_vector(to_unsigned(103,8)),std_logic_vector(to_unsigned(0,8)),std_logic_vector(to_unsigned(23,8)),std_logic_vector(to_unsigned(32,8)),std_logic_vector(to_unsigned(60,8)),std_logic_vector(to_unsigned(28,8)),std_logic_vector(to_unsigned(67,8)),std_logic_vector(to_unsigned(0,8)),
        std_logic_vector(to_unsigned(16,8)),std_logic_vector(to_unsigned(39,8)),std_logic_vector(to_unsigned(11,8)),std_logic_vector(to_unsigned(21,8)),std_logic_vector(to_unsigned(49,8)),std_logic_vector(to_unsigned(55,8)),std_logic_vector(to_unsigned(59,8)),std_logic_vector(to_unsigned(3,8)),std_logic_vector(to_unsigned(22,8)),std_logic_vector(to_unsigned(15,8)),std_logic_vector(to_unsigned(9,8)),std_logic_vector(to_unsigned(10,8)),std_logic_vector(to_unsigned(3,8)),std_logic_vector(to_unsigned(62,8)),std_logic_vector(to_unsigned(126,8)),std_logic_vector(to_unsigned(0,8)),
        std_logic_vector(to_unsigned(4,8)),std_logic_vector(to_unsigned(44,8)),std_logic_vector(to_unsigned(10,8)),std_logic_vector(to_unsigned(11,8)),std_logic_vector(to_unsigned(32,8)),std_logic_vector(to_unsigned(57,8)),std_logic_vector(to_unsigned(16,8)),std_logic_vector(to_unsigned(20,8)),std_logic_vector(to_unsigned(33,8)),std_logic_vector(to_unsigned(55,8)),std_logic_vector(to_unsigned(75,8)),std_logic_vector(to_unsigned(21,8)),std_logic_vector(to_unsigned(29,8)),std_logic_vector(to_unsigned(15,8)),std_logic_vector(to_unsigned(26,8)),std_logic_vector(to_unsigned(0,8)),
        std_logic_vector(to_unsigned(0,8)),std_logic_vector(to_unsigned(15,8)),std_logic_vector(to_unsigned(23,8)),std_logic_vector(to_unsigned(52,8)),std_logic_vector(to_unsigned(95,8)),std_logic_vector(to_unsigned(47,8)),std_logic_vector(to_unsigned(16,8)),std_logic_vector(to_unsigned(80,8)),std_logic_vector(to_unsigned(5,8)),std_logic_vector(to_unsigned(73,8)),std_logic_vector(to_unsigned(9,8)),std_logic_vector(to_unsigned(19,8)),std_logic_vector(to_unsigned(65,8)),std_logic_vector(to_unsigned(89,8)),std_logic_vector(to_unsigned(114,8)),std_logic_vector(to_unsigned(0,8)),
        std_logic_vector(to_unsigned(51,8)),std_logic_vector(to_unsigned(0,8)),std_logic_vector(to_unsigned(0,8)),std_logic_vector(to_unsigned(0,8)),std_logic_vector(to_unsigned(0,8)),std_logic_vector(to_unsigned(0,8)),std_logic_vector(to_unsigned(0,8)),std_logic_vector(to_unsigned(0,8)),std_logic_vector(to_unsigned(0,8)),std_logic_vector(to_unsigned(0,8)),std_logic_vector(to_unsigned(0,8)),std_logic_vector(to_unsigned(0,8)),std_logic_vector(to_unsigned(0,8)),std_logic_vector(to_unsigned(0,8)),std_logic_vector(to_unsigned(0,8)),std_logic_vector(to_unsigned(0,8))
         );

    
  begin
   -- registers
   process (clk,rst)
   begin
        if (rst = '1')  then                    -- determine reset values
            state_reg <=  idle;                   --  reset state
            diff_cntr_reg <= (others => '0');     -- determine reset values
            add_inram_reg <= (others => '0');     -- determine reset values
            writeSignal_reg <= '0';
            trigger_reg <= '0';
            column_cntr_reg <= (others => '0');
            -- state_next <=  idle;                   --  reset state
            -- diff_cntr_next <= (others => '0');     -- determine reset values
            -- add_inram_next <= (others => '0');     -- determine reset values
            -- writeSignal_next <= '0';
            -- trigger_next <= '0';
       
        elsif (clk'event and clk='1') then      -- update RAM and registers in HIGH_EDGE_CLOCK
            state_reg <=  state_next;             -- state register
            diff_cntr_reg <= diff_cntr_next;      -- row counter
            add_inram_reg <= add_inram_next;      -- IN_RAM address
            writeSignal_reg <= writeSignal_next;
            trigger_reg <= trigger_next;
            column_cntr_reg <= column_cntr_next;
            data_in_mem <= in_memoizated(to_integer(unsigned(add_inram_next(7 downto 0))));
            if (writeSignal_reg = '1') then
                in_ram(to_integer(unsigned(add_inram_reg))) <= data_in;                         -- write new data on IN_RAM
            end if;
            --data_out <= out_memoizated(to_integer(unsigned(add_inram_reg)));
            -- if (state_next = proces) then
            --     data_out_1 <= in_ram(to_integer(unsigned(add_inram_reg)-unsigned(column)-1));
            --     data_out_2 <= in_ram(to_integer(unsigned(add_inram_reg)-unsigned(column)));
            --     data_out_3 <= in_ram(to_integer(unsigned(add_inram_reg)-unsigned(column)+1));
                
            --     data_out_4 <= in_ram(to_integer(unsigned(add_inram_reg)-1));
            --     data_out_5 <= in_ram(to_integer(unsigned(add_inram_reg))); --center house
            --     data_out_6 <= in_ram(to_integer(unsigned(add_inram_reg)+1));
                
            --     data_out_7 <= in_ram(to_integer(unsigned(add_inram_reg)+unsigned(column)-1));
            --     data_out_8 <= in_ram(to_integer(unsigned(add_inram_reg)+unsigned(column)));
            --     data_out_9 <= in_ram(to_integer(unsigned(add_inram_reg)+unsigned(column)+1));
            -- end if;
        end if;
    end process;
-- next_state / output logic
process(state_reg,start,input,column,row,add_inram_reg,diff_cntr_reg)
begin
  case state_reg is       -- determine state
  
  
    when    idle    =>                            -- 1)IDLE state : wait for start
        trigger_next <= '0';
        if (start = '1') then                     -- wait for start command
            state_next     <= start_rows;         -- next state
            add_inram_next <= (others => '0');    -- set address IN_RAM 
            diff_cntr_next <= (others => '0');   -- set address OUT_RAM
            writeSignal_next <= '1';
            column_cntr_next <= "00000001";
        end if;
      
             
    when   start_rows    =>                        -- 2)START_ROWS state : get first 3 rows from INPUT
        if(add_inram_reg = std_logic_vector(unsigned(last_ram_addr)+1)) then    -- Diagnostic 3 rows     
            writeSignal_next <= '0';           
            if(diff_cntr_reg < threshold) then
                state_next <= approximate;               -- next state
                trigger_next <= '0';
                add_inram_next <= (others => '0');    -- set address IN_RAM 

            else
                state_next <= proces;               -- next state
                trigger_next <= '1';
                add_inram_next <= "00000000" & std_logic_vector(unsigned(column)+1);    -- set address IN_RAM 

            end if;
        else
            data_in <= input;       -- for write new data
            add_inram_next <= std_logic_vector(unsigned(add_inram_reg) + 1);    -- increment address IN_RAM 
            if(data_in_mem = input) then
                diff_cntr_next <= diff_cntr_reg;
            else
                diff_cntr_next <= std_logic_vector(unsigned(diff_cntr_reg) + 1);
            end if;
                
        end if;

    when   approximate    =>                            -- 3)PROCES state : compute and generate filter OUT and GET new data from input port
        trigger_next <= '0';
        if(add_inram_reg = last_ram_addr) then   -- for determin end of process
            state_next <= idle;      -- go to idle state in end
            
        else
            add_inram_next <= std_logic_vector(unsigned(add_inram_reg) + 1);    -- increment address IN_RAM
            data_out <= "00000001" & out_memoizated(to_integer(unsigned(add_inram_reg)));
        end if;

    

   when   proces    =>                            -- 3)PROCES state : compute and generate filter OUT and GET new data from input port
        trigger_next <= '0';
        if(add_inram_reg = std_logic_vector(unsigned(last_ram_addr)-unsigned(column)+3)) then   -- for determin end of process
            state_next <= idle;      -- go to idle state in end
            
        else
            
            if (column_cntr_reg < std_logic_vector(unsigned(column)-2)) then           -- for go to column-1 pixel 
                add_inram_next <= std_logic_vector(unsigned(add_inram_reg) + 1);   -- increment address OUT_RAM
                column_cntr_next <= std_logic_vector(unsigned(column_cntr_reg) + 1);
                -- temp4 <= std_logic_vector(unsigned(data_out_5)*unsigned(four));
                -- temp1 <= std_logic_vector(unsigned(data_out_2)*unsigned(one)+unsigned(data_out_6)*unsigned(one)+unsigned(data_out_8)*unsigned(one)+unsigned(data_out_4)*unsigned(one));
                -- -- for set output between 0 and 255 and sure that not negetive
                
            else
                add_inram_next <= std_logic_vector(unsigned(add_inram_reg) + 3);   -- increment address OUT_RAM
                column_cntr_next <= "00000001";
            end if;
            data_out_1 <= in_ram(to_integer(unsigned(add_inram_reg)-unsigned(column)-1));
            data_out_2 <= in_ram(to_integer(unsigned(add_inram_reg)-unsigned(column)));
            data_out_3 <= in_ram(to_integer(unsigned(add_inram_reg)-unsigned(column)+1));
            
            data_out_4 <= in_ram(to_integer(unsigned(add_inram_reg)-1));
            data_out_5 <= in_ram(to_integer(unsigned(add_inram_reg))); --center house
            data_out_6 <= in_ram(to_integer(unsigned(add_inram_reg)+1));
            
            data_out_7 <= in_ram(to_integer(unsigned(add_inram_reg)+unsigned(column)-1));
            data_out_8 <= in_ram(to_integer(unsigned(add_inram_reg)+unsigned(column)));
            data_out_9 <= in_ram(to_integer(unsigned(add_inram_reg)+unsigned(column)+1));
            if (temp4 > temp1) then
                data_out <= std_logic_vector(unsigned(temp4) - unsigned(temp1));
            else
                data_out <= std_logic_vector(unsigned(temp1) - unsigned(temp4));
            end if;
        end if;
        
        


   end case;
end process;
output <= data_out(7 downto 0);    -- assign the output
trigger <= trigger_next;
temp4 <= std_logic_vector(unsigned(data_out_5)*unsigned(four));
temp1 <= std_logic_vector(unsigned(data_out_2)*unsigned(one)+unsigned(data_out_6)*unsigned(one)+unsigned(data_out_8)*unsigned(one)+unsigned(data_out_4)*unsigned(one));

end memoization_beh;
