## Copyright lowRISC contributors (OpenTitan project).
## Licensed under the Apache License, Version 2.0, see LICENSE for details.
## SPDX-License-Identifier: Apache-2.0

## AMD VCU118
##

## Clock Signal (300 MHz)
set_property -dict { PACKAGE_PIN G31 IOSTANDARD DIFF_SSTL12 } [get_ports { IO_CLK_P }];
set_property -dict { PACKAGE_PIN F31 IOSTANDARD DIFF_SSTL12 } [get_ports { IO_CLK_N }];

## Clock constraints
## set via clocks.xdc

## Power-on Reset (1 + 1 protect)
### BEGIN PROTECT ###
set_property -dict { PACKAGE_PIN L33  IOSTANDARD LVCMOS18 PULLTYPE PULLUP } [get_ports { POR_N }]; # Main PORN, VCU118:FMCP_HSPC_LA32_P
# Guard FMCP_HSPC_LA32_N
### END PROTECT ###

## MIOs
# All MIOS except for IOC7 are connected to nets of the same name (prefixed
# with OT_ in the PCB design). IOC7 is connected to USRUSB_VBUS_DETECT on the
# CW341, not the OT_IOC7 signal.

## IOA bank (9 + 1 protect)
set_property -dict { PACKAGE_PIN R31  IOSTANDARD LVCMOS18 } [get_ports { IOA0 }]; # EarlGrey:UART2_RX VCU118:FMCP_HSPC_LA18_CC_P
set_property -dict { PACKAGE_PIN R34  IOSTANDARD LVCMOS18 } [get_ports { IOA1 }]; # EarlGrey:UART2_TX VCU118:FMCP_HSPC_LA17_CC_P
set_property -dict { PACKAGE_PIN P34  IOSTANDARD LVCMOS18 } [get_ports { IOA2 }]; # EarlGrey:GPIO VCU118:FMCP_HSPC_LA17_CC_N
set_property -dict { PACKAGE_PIN AG34 IOSTANDARD LVCMOS18 } [get_ports { IOA3 }]; # EarlGrey:GPIO VCU118:FMCP_HSPC_LA16_P
set_property -dict { PACKAGE_PIN AH35 IOSTANDARD LVCMOS18 } [get_ports { IOA4 }]; # EarlGrey:UART3_RX VCU118:FMCP_HSPC_LA16_N
set_property -dict { PACKAGE_PIN AG32 IOSTANDARD LVCMOS18 } [get_ports { IOA5 }]; # EarlGrey:UART3_TX VCU118:FMCP_HSPC_LA15_P
set_property -dict { PACKAGE_PIN AG33 IOSTANDARD LVCMOS18 } [get_ports { IOA6 }]; # EarlGrey:GPIO VCU118:FMCP_HSPC_LA15_N
### BEGIN PROTECT (if TPM CSB) ###
set_property -dict { PACKAGE_PIN AG31 IOSTANDARD LVCMOS18 } [get_ports { IOA7 }]; # EarlGrey:SPI_TPM_CSB,I2C_TARGET_SDA VCU118:FMCP_HSPC_LA14_P
# Protect FMCP_HSPC_LA14_N (AH31)
### END PROTECT ###
set_property -dict { PACKAGE_PIN AJ36 IOSTANDARD LVCMOS18 } [get_ports { IOA8 }]; # EarlGrey:I2C_TARGET_SCL VCU118:FMCP_HSPC_LA13_N

## IOB bank (13 pins)
set_property -dict { PACKAGE_PIN P31  IOSTANDARD LVCMOS18 } [get_ports { IOB0  }]; # EarlGrey:SPI_HOST1_CSB VCU118:FMCP_HSPC_LA18_CC_N
set_property -dict { PACKAGE_PIN N33  IOSTANDARD LVCMOS18 } [get_ports { IOB1  }]; # EarlGrey:SPI_HOST1_CSB VCU118:FMCP_HSPC_LA19_P
set_property -dict { PACKAGE_PIN M33  IOSTANDARD LVCMOS18 } [get_ports { IOB2  }]; # EarlGrey:SPI_HOST1_CSB VCU118:FMCP_HSPC_LA19_N
set_property -dict { PACKAGE_PIN N32  IOSTANDARD LVCMOS18 } [get_ports { IOB3  }]; # EarlGrey:SPI_HOST1_CSB VCU118:FMCP_HSPC_LA20_P
set_property -dict { PACKAGE_PIN M32  IOSTANDARD LVCMOS18 } [get_ports { IOB4  }]; # EarlGrey:UART1_RX VCU118:FMCP_HSPC_LA20_P
set_property -dict { PACKAGE_PIN M35  IOSTANDARD LVCMOS18 } [get_ports { IOB5  }]; # EarlGrey:UART1_TX VCU118:FMCP_HSPC_LA21_P
set_property -dict { PACKAGE_PIN L35  IOSTANDARD LVCMOS18 } [get_ports { IOB6  }]; # EarlGrey:GPIO VCU118:FMCP_HSPC_LA21_N
set_property -dict { PACKAGE_PIN N34  IOSTANDARD LVCMOS18 } [get_ports { IOB7  }]; # EarlGrey:GPIO VCU118:FMCP_HSPC_LA22_P
set_property -dict { PACKAGE_PIN N35  IOSTANDARD LVCMOS18 } [get_ports { IOB8  }]; # EarlGrey:GPIO VCU118:FMCP_HSPC_LA22_N
set_property -dict { PACKAGE_PIN Y32  IOSTANDARD LVCMOS18 } [get_ports { IOB9  }]; # EarlGrey:I2C_HOST_SDA VCU118:FMCP_HSPC_LA23_P
set_property -dict { PACKAGE_PIN W32  IOSTANDARD LVCMOS18 } [get_ports { IOB10 }]; # EarlGrey:I2C_HOST_SCL VCU118:FMCP_HSPC_LA23_N
set_property -dict { PACKAGE_PIN T34  IOSTANDARD LVCMOS18 } [get_ports { IOB11 }]; # EarlGrey:I2C_HOST_SCL VCU118:FMCP_HSPC_LA24_P
set_property -dict { PACKAGE_PIN T35  IOSTANDARD LVCMOS18 } [get_ports { IOB12 }]; # EarlGrey:I2C_HOST_SDA VCU118:FMCP_HSPC_LA24_N


## IOC bank (13 pins)
set_property -dict { PACKAGE_PIN  Y34  IOSTANDARD LVCMOS18 PULLTYPE PULLDOWN } [get_ports { IOC0 }]; # EarlGrey:SW_STRAP0 VCU118:FMCP_HSPC_LA25_P
set_property -dict { PACKAGE_PIN  W34  IOSTANDARD LVCMOS18 PULLTYPE PULLDOWN } [get_ports { IOC1 }]; # EarlGrey:SW_STRAP1 VCU118:FMCP_HSPC_LA25_N
set_property -dict { PACKAGE_PIN  V32  IOSTANDARD LVCMOS18 PULLTYPE PULLDOWN } [get_ports { IOC2 }]; # EarlGrey:SW_STRAP2 VCU118:FMCP_HSPC_LA26_P
set_property -dict { PACKAGE_PIN  U33  IOSTANDARD LVCMOS18 } [get_ports { IOC3 }]; # EarlGrey:UART0_RX VCU118:FMCP_HSPC_LA26_N
set_property -dict { PACKAGE_PIN  V33  IOSTANDARD LVCMOS18 } [get_ports { IOC4 }]; # EarlGrey:UART0_TX VCU118:FMCP_HSPC_LA27_P
set_property -dict { PACKAGE_PIN  V34  IOSTANDARD LVCMOS18 PULLTYPE PULLDOWN } [get_ports { IOC5 }]; # EarlGrey:TAP_STRAP1 VCU118:FMCP_HSPC_LA27_N
set_property -dict { PACKAGE_PIN  M36  IOSTANDARD LVCMOS18 } [get_ports { IOC6 }]; # EarlGrey:GPIO VCU118:FMCP_HSPC_LA28_P
set_property -dict { PACKAGE_PIN  L36  IOSTANDARD LVCMOS18 } [get_ports { IOC7 }]; # EarlGrey:VBUS_DETECT VCU118:FMCP_HSPC_LA28_N
set_property -dict { PACKAGE_PIN  U35  IOSTANDARD LVCMOS18 PULLTYPE PULLDOWN } [get_ports { IOC8 }]; # EarlGrey:TAP_STRAP0 VCU118:FMCP_HSPC_LA29_P
set_property -dict { PACKAGE_PIN  T36  IOSTANDARD LVCMOS18 } [get_ports { IOC9  }]; # EarlGrey:GPIO VCU118:FMCP_HSPC_LA29_N
set_property -dict { PACKAGE_PIN  N38  IOSTANDARD LVCMOS18 } [get_ports { IOC10 }]; # EarlGrey:GPIO VCU118:FMCP_HSPC_LA30_P
set_property -dict { PACKAGE_PIN  M38  IOSTANDARD LVCMOS18 } [get_ports { IOC11 }]; # EarlGrey:GPIO VCU118:FMCP_HSPC_LA30_N
set_property -dict { PACKAGE_PIN  P37  IOSTANDARD LVCMOS18 } [get_ports { IOC12 }]; # EarlGrey:GPIO VCU118:FMCP_HSPC_LA31_P

## IOR bank (14 pins)
# JTAG
set_property -dict { PACKAGE_PIN N14  IOSTANDARD LVCMOS18 PULLTYPE PULLUP } [get_ports { IOR0  }]; # VCU118:FMCP_HSPC_HA00_CC_P EarlGrey:JTAG_TMS
set_property -dict { PACKAGE_PIN N13  IOSTANDARD LVCMOS18 PULLTYPE PULLUP } [get_ports { IOR1  }]; # VCU118:FMCP_HSPC_HA00_CC_N EarlGrey:JTAG_TDO
set_property -dict { PACKAGE_PIN V15  IOSTANDARD LVCMOS18 PULLTYPE PULLUP } [get_ports { IOR2  }]; # VCU118:FMCP_HSPC_HA01_CC_P EarlGrey:JTAG_TDI
set_property -dict { PACKAGE_PIN U15  IOSTANDARD LVCMOS18 PULLTYPE PULLUP } [get_ports { IOR3  }]; # VCU118:FMCP_HSPC_HA01_CC_N EarlGrey:JTAG_TCK
set_property -dict { PACKAGE_PIN AA12 IOSTANDARD LVCMOS18 PULLTYPE PULLUP } [get_ports { IOR4  }]; # VCU118:FMCP_HSPC_HA02_P EarlGrey:JTAG_TRSTn
set_property -dict { PACKAGE_PIN Y12  IOSTANDARD LVCMOS18                 } [get_ports { IOR5  }]; # VCU118:FMCP_HSPC_HA02_N DFT Strap 0
set_property -dict { PACKAGE_PIN W12  DRIVE 8 IOSTANDARD LVCMOS18         } [get_ports { IOR6  }]; # VCU118:FMCP_HSPC_HA03_P EarlGrey:GPIO(LED0)
set_property -dict { PACKAGE_PIN V12  DRIVE 8 IOSTANDARD LVCMOS18         } [get_ports { IOR7  }]; # VCU118:FMCP_HSPC_HA03_N DFT Strap 1
set_property -dict { PACKAGE_PIN AA13 DRIVE 8 IOSTANDARD LVCMOS18         } [get_ports { IOR8  }]; # VCU118:FMCP_HSPC_HA04_P EarlGrey:GPIO(LED2)
set_property -dict { PACKAGE_PIN Y13  DRIVE 8 IOSTANDARD LVCMOS18         } [get_ports { IOR9  }]; # VCU118:FMCP_HSPC_HA04_N EarlGrey:GPIO(LED3)
set_property -dict { PACKAGE_PIN R14  DRIVE 8 IOSTANDARD LVCMOS18         } [get_ports { IOR10 }]; # VCU118:FMCP_HSPC_HA05_P EarlGrey:GPIO(LED4)
set_property -dict { PACKAGE_PIN P14  DRIVE 8 IOSTANDARD LVCMOS18         } [get_ports { IOR11 }]; # VCU118:FMCP_HSPC_HA05_N EarlGrey:GPIO(LED5)
set_property -dict { PACKAGE_PIN U13  DRIVE 8 IOSTANDARD LVCMOS18         } [get_ports { IOR12 }]; # VCU118:FMCP_HSPC_HA06_P EarlGrey:GPIO(LED6)
set_property -dict { PACKAGE_PIN T13  DRIVE 8 IOSTANDARD LVCMOS18         } [get_ports { IOR13 }]; # VCU118:FMCP_HSPC_HA06_N EarlGrey:GPIO(LED7)

## DIOs
# For DIOs, the port name maps directly to the function in Earl Grey, so
# instead, the net names on the PCB are provided in comments.

## SPI device (6 + 2 protect)
### BEGIN PROTECT ###
set_property -dict { PACKAGE_PIN AL35 IOSTANDARD LVCMOS18 } [get_ports { SPI_DEV_CLK  }]; # VCU118:FMCP_HSPC_LA00_CC_P
# Protect FMCP_HSPC_LA00_CC_N (AL36)
### END PROTECT ###
set_property -dict { PACKAGE_PIN AJ32 IOSTANDARD LVCMOS18 } [get_ports { SPI_DEV_D0   }]; # VCU118:FMCP_HSPC_LA02_P
set_property -dict { PACKAGE_PIN AK32 IOSTANDARD LVCMOS18 } [get_ports { SPI_DEV_D1   }]; # VCU118:FMCP_HSPC_LA02_N
set_property -dict { PACKAGE_PIN AT39 IOSTANDARD LVCMOS18 } [get_ports { SPI_DEV_D2   }]; # VCU118:FMCP_HSPC_LA03_P
set_property -dict { PACKAGE_PIN AT40 IOSTANDARD LVCMOS18 } [get_ports { SPI_DEV_D3   }]; # VCU118:FMCP_HSPC_LA03_N
### BEGIN PROTECT ###
set_property -dict { PACKAGE_PIN AL30 IOSTANDARD LVCMOS18 } [get_ports { SPI_DEV_CS_L }]; # VCU118:FMCP_HSPC_LA01_CC_P
# Protect FMCP_HSPC_LA01_CC_N (AL31)
### END PROTECT ###

## SPI HOST (6 + 1 protect)
### BEGIN PROTECT ###
set_property -dict { PACKAGE_PIN AR37 IOSTANDARD LVCMOS18 } [get_ports { SPI_HOST_CLK }]; # VCU118:FMCP_HSPC_LA04_P
# Protect FMCP_HSPC_LA04_N (AT37)
### END PROTECT ###
set_property -dict { PACKAGE_PIN AP38 IOSTANDARD LVCMOS18 PULLTYPE PULLUP } [get_ports { SPI_HOST_D0 }]; # VCU118:FMCP_HSPC_LA05_P
set_property -dict { PACKAGE_PIN AR38 IOSTANDARD LVCMOS18 PULLTYPE PULLUP } [get_ports { SPI_HOST_D1 }]; # VCU118:FMCP_HSPC_LA05_N
set_property -dict { PACKAGE_PIN AT35 IOSTANDARD LVCMOS18 PULLTYPE PULLUP } [get_ports { SPI_HOST_D2 }]; # VCU118:FMCP_HSPC_LA06_P
set_property -dict { PACKAGE_PIN AT36 IOSTANDARD LVCMOS18 PULLTYPE PULLUP } [get_ports { SPI_HOST_D3 }]; # VCU118:FMCP_HSPC_LA06_N
### BEGIN PROTECT ###
set_property -dict { PACKAGE_PIN AP36 IOSTANDARD LVCMOS18 PULLTYPE PULLUP } [get_ports { SPI_HOST_CS_L }]; # VCU118:FMCP_HSPC_LA07_P
# Protect FMCP_HSPC_LA07_N (AP37)
### END PROTECT ###

## TODO: Delete these pins that aren't used on the VCU118. These are specific to the ChipWhisperer
## boards.
set_property -dict { PACKAGE_PIN AY9  IOSTANDARD LVCMOS18 } [get_ports { IO_TRIGGER }]; # VCU118:FMC_HPC1_LA00_CC_P
set_property -dict { PACKAGE_PIN BF10 IOSTANDARD LVCMOS18 } [get_ports { IO_CLKOUT }];  # VCU118:FMC_HPC1_LA01_CC_P

## TI TUSB1106 USB PHY usbdev testing (9 + 2 protect)
set_property -dict { PACKAGE_PIN AK29 IOSTANDARD LVCMOS18 } [get_ports { IO_USB_DP_TX   }]; # VCU118:FMCP_HSPC_LA08_P TUSB1106:VPO
set_property -dict { PACKAGE_PIN AK30 IOSTANDARD LVCMOS18 } [get_ports { IO_USB_DN_TX   }]; # VCU118:FMCP_HSPC_LA08_N TUSB1106:VMO
set_property -dict { PACKAGE_PIN AJ33 IOSTANDARD LVCMOS18 } [get_ports { IO_USB_DP_RX   }]; # VCU118:FMCP_HSPC_LA09_P TUSB1106:VP
set_property -dict { PACKAGE_PIN AK33 IOSTANDARD LVCMOS18 } [get_ports { IO_USB_DN_RX   }]; # VCU118:FMCP_HSPC_LA09_N TUSB1106:VM
### BEGIN PROTECT ###
set_property -dict { PACKAGE_PIN AP35 IOSTANDARD LVCMOS18 } [get_ports { IO_USB_OE_N    }]; # VCU118:FMCP_HSPC_LA10_P TUSB1106:OE
# Protect FMCP_HSPC_LA10_N (AR35)
set_property -dict { PACKAGE_PIN AJ30 IOSTANDARD LVCMOS18 } [get_ports { IO_USB_D_RX    }]; # VCU118:FMCP_HSPC_LA11_P TUSB1106:RCV
# Protect FMCP_HSPC_LA11_N (AJ31)
### END PROTECT ###
set_property -dict { PACKAGE_PIN AH33 IOSTANDARD LVCMOS18 } [get_ports { IO_USB_CONNECT }]; # VCU118:FMCP_HSPC_LA12_P TUSB1106:SOFTCON
set_property -dict { PACKAGE_PIN AH34 IOSTANDARD LVCMOS18 } [get_ports { IO_USB_SPEED   }]; # VCU118:FMCP_HSPC_LA12_N TUSB1106:SPEED
set_property -dict { PACKAGE_PIN AJ35 IOSTANDARD LVCMOS18 } [get_ports { IO_USB_SUSPEND }]; # VCU118:FMCP_HSPC_LA13_P TUSB1106:SUSPEND

## Configuration options, can be used for all designs
set_property CONFIG_VOLTAGE 1.8 [current_design]
set_property CFGBVS GND [current_design]
