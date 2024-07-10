# Copyright zeroRISC Inc.
# Confidential information of zeroRISC Inc. All rights reserved.

if {[llength $argv] != 1} {
    puts "expected -tclargs /path/to/bistream.bit"
    exit 1
}
set bitstream [lindex $argv 0]

open_hw_manager
connect_hw_server -allow_non_jtag

open_hw_target
current_hw_device [get_hw_devices xcvu9p_0]
refresh_hw_device -update_hw_probes false [lindex [get_hw_devices xcvu9p_0] 0]

set_property PROBES.FILE {} [get_hw_devices xcvu9p_0]
set_property FULL_PROBES.FILE {} [get_hw_devices xcvu9p_0]
set_property PROGRAM.FILE $bitstream [get_hw_devices xcvu9p_0]
program_hw_devices [get_hw_devices xcvu9p_0]

refresh_hw_device [lindex [get_hw_devices xcvu9p_0] 0]
