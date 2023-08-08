
################################################################
# This is a generated script based on design: design_1
#
# Though there are limitations about the generated script,
# the main purpose of this utility is to make learning
# IP Integrator Tcl commands easier.
################################################################

namespace eval _tcl {
proc get_script_folder {} {
   set script_path [file normalize [info script]]
   set script_folder [file dirname $script_path]
   return $script_folder
}
}
variable script_folder
set script_folder [_tcl::get_script_folder]

################################################################
# Check if script is running in correct Vivado version.
################################################################
set scripts_vivado_version 2019.1
set current_vivado_version [version -short]

if { [string first $scripts_vivado_version $current_vivado_version] == -1 } {
   puts ""
   catch {common::send_msg_id "BD_TCL-109" "ERROR" "This script was generated using Vivado <$scripts_vivado_version> and is being run in <$current_vivado_version> of Vivado. Please run the script in Vivado <$scripts_vivado_version> then open the design in Vivado <$current_vivado_version>. Upgrade the design by running \"Tools => Report => Report IP Status...\", then run write_bd_tcl to create an updated script."}

   return 1
}

################################################################
# START
################################################################

# To test this script, run the following commands from Vivado Tcl console:
# source design_1_script.tcl

# If there is no project opened, this script will create a
# project, but make sure you do not have an existing project
# <./myproj/project_1.xpr> in the current working folder.

set list_projs [get_projects -quiet]
if { $list_projs eq "" } {
   create_project project_1 myproj -part xc7s100fgga676-2
   set_property BOARD_PART xilinx.com:sp701:part0:1.0 [current_project]
}


# CHANGE DESIGN NAME HERE
variable design_name
set design_name design_1

# If you do not already have an existing IP Integrator design open,
# you can create a design using the following command:
#    create_bd_design $design_name

# Creating design if needed
set errMsg ""
set nRet 0

set cur_design [current_bd_design -quiet]
set list_cells [get_bd_cells -quiet]

if { ${design_name} eq "" } {
   # USE CASES:
   #    1) Design_name not set

   set errMsg "Please set the variable <design_name> to a non-empty value."
   set nRet 1

} elseif { ${cur_design} ne "" && ${list_cells} eq "" } {
   # USE CASES:
   #    2): Current design opened AND is empty AND names same.
   #    3): Current design opened AND is empty AND names diff; design_name NOT in project.
   #    4): Current design opened AND is empty AND names diff; design_name exists in project.

   if { $cur_design ne $design_name } {
      common::send_msg_id "BD_TCL-001" "INFO" "Changing value of <design_name> from <$design_name> to <$cur_design> since current design is empty."
      set design_name [get_property NAME $cur_design]
   }
   common::send_msg_id "BD_TCL-002" "INFO" "Constructing design in IPI design <$cur_design>..."

} elseif { ${cur_design} ne "" && $list_cells ne "" && $cur_design eq $design_name } {
   # USE CASES:
   #    5) Current design opened AND has components AND same names.

   set errMsg "Design <$design_name> already exists in your project, please set the variable <design_name> to another value."
   set nRet 1
} elseif { [get_files -quiet ${design_name}.bd] ne "" } {
   # USE CASES: 
   #    6) Current opened design, has components, but diff names, design_name exists in project.
   #    7) No opened design, design_name exists in project.

   set errMsg "Design <$design_name> already exists in your project, please set the variable <design_name> to another value."
   set nRet 2

} else {
   # USE CASES:
   #    8) No opened design, design_name not in project.
   #    9) Current opened design, has components, but diff names, design_name not in project.

   common::send_msg_id "BD_TCL-003" "INFO" "Currently there is no design <$design_name> in project, so creating one..."

   create_bd_design $design_name

   common::send_msg_id "BD_TCL-004" "INFO" "Making design <$design_name> as current_bd_design."
   current_bd_design $design_name

}

common::send_msg_id "BD_TCL-005" "INFO" "Currently the variable <design_name> is equal to \"$design_name\"."

if { $nRet != 0 } {
   catch {common::send_msg_id "BD_TCL-114" "ERROR" $errMsg}
   return $nRet
}

##################################################################
# DESIGN PROCs
##################################################################



# Procedure to create entire design; Provide argument to make
# procedure reusable. If parentCell is "", will use root.
proc create_root_design { parentCell } {

  variable script_folder
  variable design_name

  if { $parentCell eq "" } {
     set parentCell [get_bd_cells /]
  }

  # Get object for parentCell
  set parentObj [get_bd_cells $parentCell]
  if { $parentObj == "" } {
     catch {common::send_msg_id "BD_TCL-100" "ERROR" "Unable to find parent cell <$parentCell>!"}
     return
  }

  # Make sure parentObj is hier blk
  set parentType [get_property TYPE $parentObj]
  if { $parentType ne "hier" } {
     catch {common::send_msg_id "BD_TCL-101" "ERROR" "Parent <$parentObj> has TYPE = <$parentType>. Expected to be <hier>."}
     return
  }

  # Save current instance; Restore later
  set oldCurInst [current_bd_instance .]

  # Set parent object as current
  current_bd_instance $parentObj


  # Create interface ports
  set ap_ctrl [ create_bd_intf_port -mode Slave -vlnv xilinx.com:interface:acc_handshake_rtl:1.0 ap_ctrl ]

  set ap_ctrl_1 [ create_bd_intf_port -mode Slave -vlnv xilinx.com:interface:acc_handshake_rtl:1.0 ap_ctrl_1 ]

  set ap_ctrl_2 [ create_bd_intf_port -mode Slave -vlnv xilinx.com:interface:acc_handshake_rtl:1.0 ap_ctrl_2 ]


  # Create ports
  set B [ create_bd_port -dir I -from 7 -to 0 -type data B ]
  set G [ create_bd_port -dir I -from 7 -to 0 -type data G ]
  set R [ create_bd_port -dir I -from 7 -to 0 -type data R ]
  set ap_clk [ create_bd_port -dir I -type clk ap_clk ]
  set_property -dict [ list \
   CONFIG.FREQ_HZ {100000000} \
 ] $ap_clk
  set ap_return [ create_bd_port -dir O -from 7 -to 0 -type data ap_return ]
  set ap_return_1 [ create_bd_port -dir O -from 7 -to 0 -type data ap_return_1 ]
  set ap_return_2 [ create_bd_port -dir O -from 7 -to 0 -type data ap_return_2 ]
  set ap_rst [ create_bd_port -dir I -type rst ap_rst ]
  set_property -dict [ list \
   CONFIG.POLARITY {ACTIVE_HIGH} \
 ] $ap_rst

  # Create instance: Cb_0, and set properties
  set Cb_0 [ create_bd_cell -type ip -vlnv xilinx.com:hls:Cb:1.0 Cb_0 ]

  # Create instance: Cr_0, and set properties
  set Cr_0 [ create_bd_cell -type ip -vlnv xilinx.com:hls:Cr:1.0 Cr_0 ]

  # Create instance: Y_0, and set properties
  set Y_0 [ create_bd_cell -type ip -vlnv xilinx.com:hls:Y:1.0 Y_0 ]

  # Create interface connections
  connect_bd_intf_net -intf_net ap_ctrl_1 [get_bd_intf_ports ap_ctrl] [get_bd_intf_pins Y_0/ap_ctrl]
  connect_bd_intf_net -intf_net ap_ctrl_1_1 [get_bd_intf_ports ap_ctrl_1] [get_bd_intf_pins Cb_0/ap_ctrl]
  connect_bd_intf_net -intf_net ap_ctrl_2_1 [get_bd_intf_ports ap_ctrl_2] [get_bd_intf_pins Cr_0/ap_ctrl]

  # Create port connections
  connect_bd_net -net B_1 [get_bd_ports B] [get_bd_pins Cb_0/B] [get_bd_pins Cr_0/B] [get_bd_pins Y_0/B]
  connect_bd_net -net Cb_0_ap_return [get_bd_ports ap_return_1] [get_bd_pins Cb_0/ap_return]
  connect_bd_net -net Cr_0_ap_return [get_bd_ports ap_return_2] [get_bd_pins Cr_0/ap_return]
  connect_bd_net -net G_1 [get_bd_ports G] [get_bd_pins Cb_0/G] [get_bd_pins Cr_0/G] [get_bd_pins Y_0/G]
  connect_bd_net -net R_1 [get_bd_ports R] [get_bd_pins Cb_0/R] [get_bd_pins Cr_0/R] [get_bd_pins Y_0/R]
  connect_bd_net -net Y_0_ap_return [get_bd_ports ap_return] [get_bd_pins Y_0/ap_return]
  connect_bd_net -net ap_clk_1 [get_bd_ports ap_clk] [get_bd_pins Cb_0/ap_clk] [get_bd_pins Cr_0/ap_clk] [get_bd_pins Y_0/ap_clk]
  connect_bd_net -net ap_rst_1 [get_bd_ports ap_rst] [get_bd_pins Cb_0/ap_rst] [get_bd_pins Cr_0/ap_rst] [get_bd_pins Y_0/ap_rst]

  # Create address segments


  # Restore current instance
  current_bd_instance $oldCurInst

  validate_bd_design
  save_bd_design
}
# End of create_root_design()


##################################################################
# MAIN FLOW
##################################################################

create_root_design ""


