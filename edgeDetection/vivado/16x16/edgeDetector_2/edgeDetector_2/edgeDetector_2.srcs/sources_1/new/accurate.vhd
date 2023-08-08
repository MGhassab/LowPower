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

entity accurate is
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
end accurate;

architecture accurate_beh of accurate is
 type ram_type is array (0 to 999) of std_logic_vector (7 downto 0);    -- define 100000x8 bit RAM Type        
    type    state_type  is  (idle,start_rows,proces);                        -- State = idle  ,  start_rows  ,  proces 
    signal state_reg , state_next     : state_type;                          -- state register                    
    signal in_ram                     : ram_type;                            -- input Ram for save inputs(4 rows)
    signal data_in                    : std_logic_vector(7 downto 0);                    -- Input Port RAM_IN
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
    signal column_cntr_reg , column_cntr_next : std_logic_vector(7 downto 0) := (others => '0');  
    signal writeSignal_reg, writeSignal_next  : std_logic; 
    signal trigger_reg, trigger_next  : std_logic; 
    signal last_ram_addr  : std_logic_vector(15 downto 0) := std_logic_vector(to_unsigned(255,16));
    signal one  : std_logic_vector(7 downto 0) := "00000001";  -- make constant 1 for multiplexer
    signal four : std_logic_vector(7 downto 0) := "00000100";  -- make constant 4 for multiplexer
    signal temp4 , temp1 : std_logic_vector(15 downto 0);  -- temporary signal
    

    
  begin
   -- registers
   process (clk,rst)
   begin
        if (rst = '1')  then                    -- determine reset values
            state_reg <=  idle;                   --  reset state
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
            add_inram_reg <= add_inram_next;      -- IN_RAM address
            writeSignal_reg <= writeSignal_next;
            trigger_reg <= trigger_next;
            column_cntr_reg <= column_cntr_next;
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
process(state_reg,start,input,column,row,add_inram_reg)
begin
  case state_reg is       -- determine state
  
  
    when    idle    =>                            -- 1)IDLE state : wait for start
        trigger_next <= '0';
        if (start = '1') then                     -- wait for start command
            state_next     <= start_rows;         -- next state
            add_inram_next <= (others => '0');    -- set address IN_RAM 
            writeSignal_next <= '1';
            column_cntr_next <= "00000001";
        end if;
      
             
    when   start_rows    =>                        -- 2)START_ROWS state : get first 3 rows from INPUT
        if(add_inram_reg = std_logic_vector(unsigned(last_ram_addr)+1)) then    -- Diagnostic 3 rows     
            writeSignal_next <= '0';           
            state_next <= proces;               -- next state
            trigger_next <= '1';
            add_inram_next <= "00000000" & std_logic_vector(unsigned(column)+1);    -- set address IN_RAM 
        else
            data_in <= input;       -- for write new data
            add_inram_next <= std_logic_vector(unsigned(add_inram_reg) + 1);    -- increment address IN_RAM   
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

end accurate_beh;
