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

## JTAG manual pads
set_property -dict { PACKAGE_PIN N14  IOSTANDARD LVCMOS18 PULLTYPE PULLUP   } [get_ports { JTAG_TMS  }]; # Darjeeling:JTAG_TMS VCU118:FMCP_HSPC_HA00_CC_P
set_property -dict { PACKAGE_PIN N13  IOSTANDARD LVCMOS18 PULLTYPE PULLUP   } [get_ports { JTAG_TDO  }]; # Darjeeling:JTAG_TDO VCU118:FMCP_HSPC_HA00_CC_N
set_property -dict { PACKAGE_PIN V15  IOSTANDARD LVCMOS18 PULLTYPE PULLUP   } [get_ports { JTAG_TDI  }]; # Darjeeling:JTAG_TDI VCU118:FMCP_HSPC_HA01_CC_P
set_property -dict { PACKAGE_PIN U15  IOSTANDARD LVCMOS18 PULLTYPE PULLUP   } [get_ports { JTAG_TCK  }]; # Darjeeling:JTAG_TCK VCU118:FMCP_HSPC_HA01_CC_N
set_property -dict { PACKAGE_PIN AA12 IOSTANDARD LVCMOS18 PULLTYPE PULLUP   } [get_ports { JTAG_TRST_N  }]; # Darjeeling:JTAG_TRST_N VCU118:FMCP_HSPC_HA02_P

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
set_property -dict { PACKAGE_PIN V14 IOSTANDARD LVCMOS18 } [get_ports { SPI_DEV_TPM_CS_L }]; # VCU118:FMCP_HSPC_HA09_N

## UART, I2C
set_property -dict { PACKAGE_PIN U33 IOSTANDARD LVCMOS18 } [get_ports { UART_RX }]; # VCU118:FMCP_HSPC_LA26_N
set_property -dict { PACKAGE_PIN V33 IOSTANDARD LVCMOS18 } [get_ports { UART_TX }]; # VCU118:FMCP_HSPC_LA27_P
set_property -dict { PACKAGE_PIN R12 IOSTANDARD LVCMOS18 } [get_ports { I2C_SCL }]; # VCU118:FMCP_HSPC_HA11_P
set_property -dict { PACKAGE_PIN P12 IOSTANDARD LVCMOS18 } [get_ports { I2C_SDA }]; # VCU118:FMCP_HSPC_HA11_N

## GPIO
set_property -dict { PACKAGE_PIN R31  IOSTANDARD LVCMOS18 } [get_ports { GPIO0  }]; # VCU118:FMCP_HSPC_LA18_CC_P
set_property -dict { PACKAGE_PIN R34  IOSTANDARD LVCMOS18 } [get_ports { GPIO1  }]; # VCU118:FMCP_HSPC_LA17_CC_P
set_property -dict { PACKAGE_PIN P34  IOSTANDARD LVCMOS18 } [get_ports { GPIO2  }]; # VCU118:FMCP_HSPC_LA17_CC_N
set_property -dict { PACKAGE_PIN AG34 IOSTANDARD LVCMOS18 } [get_ports { GPIO3  }]; # VCU118:FMCP_HSPC_LA16_P
set_property -dict { PACKAGE_PIN AH35 IOSTANDARD LVCMOS18 } [get_ports { GPIO4  }]; # VCU118:FMCP_HSPC_LA16_N
set_property -dict { PACKAGE_PIN AG32 IOSTANDARD LVCMOS18 } [get_ports { GPIO5  }]; # VCU118:FMCP_HSPC_LA15_P
set_property -dict { PACKAGE_PIN AG33 IOSTANDARD LVCMOS18 } [get_ports { GPIO6  }]; # VCU118:FMCP_HSPC_LA15_N
set_property -dict { PACKAGE_PIN AG31 IOSTANDARD LVCMOS18 } [get_ports { GPIO7  }]; # VCU118:FMCP_HSPC_LA14_P
set_property -dict { PACKAGE_PIN AJ36 IOSTANDARD LVCMOS18 } [get_ports { GPIO8  }]; # VCU118:FMCP_HSPC_LA13_N
set_property -dict { PACKAGE_PIN P31  IOSTANDARD LVCMOS18 } [get_ports { GPIO9  }]; # VCU118:FMCP_HSPC_LA18_CC_N
set_property -dict { PACKAGE_PIN N33  IOSTANDARD LVCMOS18 } [get_ports { GPIO10 }]; # VCU118:FMCP_HSPC_LA19_P
set_property -dict { PACKAGE_PIN M33  IOSTANDARD LVCMOS18 } [get_ports { GPIO11 }]; # VCU118:FMCP_HSPC_LA19_N
set_property -dict { PACKAGE_PIN N32  IOSTANDARD LVCMOS18 } [get_ports { GPIO12 }]; # VCU118:FMCP_HSPC_LA20_P
set_property -dict { PACKAGE_PIN M32  IOSTANDARD LVCMOS18 } [get_ports { GPIO13 }]; # VCU118:FMCP_HSPC_LA20_N
set_property -dict { PACKAGE_PIN M35  IOSTANDARD LVCMOS18 } [get_ports { GPIO14 }]; # VCU118:FMCP_HSPC_LA21_P
set_property -dict { PACKAGE_PIN L35  IOSTANDARD LVCMOS18 } [get_ports { GPIO15 }]; # VCU118:FMCP_HSPC_LA21_N
set_property -dict { PACKAGE_PIN N34  IOSTANDARD LVCMOS18 } [get_ports { GPIO16 }]; # VCU118:FMCP_HSPC_LA22_P
set_property -dict { PACKAGE_PIN N35  IOSTANDARD LVCMOS18 } [get_ports { GPIO17 }]; # VCU118:FMCP_HSPC_LA22_N
set_property -dict { PACKAGE_PIN Y32  IOSTANDARD LVCMOS18 } [get_ports { GPIO18 }]; # VCU118:FMCP_HSPC_LA23_P
set_property -dict { PACKAGE_PIN W32  IOSTANDARD LVCMOS18 } [get_ports { GPIO19 }]; # VCU118:FMCP_HSPC_LA23_N
set_property -dict { PACKAGE_PIN T34  IOSTANDARD LVCMOS18 } [get_ports { GPIO20 }]; # VCU118:FMCP_HSPC_LA24_P
set_property -dict { PACKAGE_PIN T35  IOSTANDARD LVCMOS18 } [get_ports { GPIO21 }]; # VCU118:FMCP_HSPC_LA24_N
set_property -dict { PACKAGE_PIN Y34  IOSTANDARD LVCMOS18 PULLTYPE PULLDOWN } [get_ports { GPIO22 }]; # Darjeeling:SW_STRAP0 # VCU118:FMCP_HSPC_LA25_P
set_property -dict { PACKAGE_PIN W34  IOSTANDARD LVCMOS18 PULLTYPE PULLDOWN } [get_ports { GPIO23 }]; # Darjeeling:SW_STRAP1 # VCU118:FMCP_HSPC_LA25_N
set_property -dict { PACKAGE_PIN V32  IOSTANDARD LVCMOS18 PULLTYPE PULLDOWN } [get_ports { GPIO24 }]; # Darjeeling:SW_STRAP2 # VCU118:FMCP_HSPC_LA26_P
set_property -dict { PACKAGE_PIN V16  IOSTANDARD LVCMOS18 } [get_ports { GPIO25 }]; # VCU118:FMCP_HSPC_LA10_P -- swapped with UART_RX
set_property -dict { PACKAGE_PIN U16  IOSTANDARD LVCMOS18 } [get_ports { GPIO26 }]; # VCU118:FMCP_HSPC_LA10_N -- swapped with UART_TX
set_property -dict { PACKAGE_PIN M36  IOSTANDARD LVCMOS18 } [get_ports { GPIO27 }]; # VCU118:FMCP_HSPC_LA28_P
set_property -dict { PACKAGE_PIN L36  IOSTANDARD LVCMOS18 } [get_ports { GPIO28 }]; # VCU118:FMCP_HSPC_LA28_N
set_property -dict { PACKAGE_PIN T36  IOSTANDARD LVCMOS18 } [get_ports { GPIO29 }]; # VCU118:FMCP_HSPC_LA29_N
set_property -dict { PACKAGE_PIN N38  IOSTANDARD LVCMOS18 } [get_ports { GPIO30 }]; # VCU118:FMCP_HSPC_LA30_P
set_property -dict { PACKAGE_PIN M38  IOSTANDARD LVCMOS18 } [get_ports { GPIO31 }]; # VCU118:FMCP_HSPC_LA30_N

## SOC_GPI
set_property -dict { PACKAGE_PIN P37  IOSTANDARD LVCMOS18 } [get_ports { SOC_GPI0 }];  # VCU118:FMCP_HSPC_LA31_P
set_property -dict { PACKAGE_PIN W12  IOSTANDARD LVCMOS18 } [get_ports { SOC_GPI1 }];  # VCU118:FMCP_HSPC_HA03_P
set_property -dict { PACKAGE_PIN AA13 IOSTANDARD LVCMOS18 } [get_ports { SOC_GPI2 }];  # VCU118:FMCP_HSPC_HA04_P
set_property -dict { PACKAGE_PIN Y13  IOSTANDARD LVCMOS18 } [get_ports { SOC_GPI3 }];  # VCU118:FMCP_HSPC_HA04_N
set_property -dict { PACKAGE_PIN R14  IOSTANDARD LVCMOS18 } [get_ports { SOC_GPI4 }];  # VCU118:FMCP_HSPC_HA05_P
set_property -dict { PACKAGE_PIN P14  IOSTANDARD LVCMOS18 } [get_ports { SOC_GPI5 }];  # VCU118:FMCP_HSPC_HA05_N
set_property -dict { PACKAGE_PIN U13  IOSTANDARD LVCMOS18 } [get_ports { SOC_GPI6 }];  # VCU118:FMCP_HSPC_HA06_P
set_property -dict { PACKAGE_PIN T13  IOSTANDARD LVCMOS18 } [get_ports { SOC_GPI7 }];  # VCU118:FMCP_HSPC_HA06_N
set_property -dict { PACKAGE_PIN AY9  IOSTANDARD LVCMOS18 } [get_ports { SOC_GPI8 }];  # VCU118:FMCP_HPC1_LA00_CC_P
set_property -dict { PACKAGE_PIN BF10 IOSTANDARD LVCMOS18 } [get_ports { SOC_GPI9 }];  # VCU118:FMCP_HPC1_LA01_CC_P
set_property -dict { PACKAGE_PIN AK29 IOSTANDARD LVCMOS18 } [get_ports { SOC_GPI10 }]; # VCU118:FMCP_HSPC_LA08_P
set_property -dict { PACKAGE_PIN AK30 IOSTANDARD LVCMOS18 } [get_ports { SOC_GPI11 }]; # VCU118:FMCP_HSPC_LA08_N

## SOC_GPO
set_property -dict { PACKAGE_PIN AJ33 IOSTANDARD LVCMOS18 } [get_ports { SOC_GPO0  }]; # VCU118:FMCP_HSPC_LA09_P
set_property -dict { PACKAGE_PIN AK33 IOSTANDARD LVCMOS18 } [get_ports { SOC_GPO1  }]; # VCU118:FMCP_HSPC_LA09_N
set_property -dict { PACKAGE_PIN AP35 IOSTANDARD LVCMOS18 } [get_ports { SOC_GPO2  }]; # VCU118:FMCP_HSPC_LA10_P
set_property -dict { PACKAGE_PIN AJ30 IOSTANDARD LVCMOS18 } [get_ports { SOC_GPO3  }]; # VCU118:FMCP_HSPC_LA11_P
set_property -dict { PACKAGE_PIN AH33 IOSTANDARD LVCMOS18 } [get_ports { SOC_GPO4  }]; # VCU118:FMCP_HSPC_LA12_P
set_property -dict { PACKAGE_PIN AH34 IOSTANDARD LVCMOS18 } [get_ports { SOC_GPO5  }]; # VCU118:FMCP_HSPC_LA12_N
set_property -dict { PACKAGE_PIN AJ35 IOSTANDARD LVCMOS18 } [get_ports { SOC_GPO6  }]; # VCU118:FMCP_HSPC_LA13_P
set_property -dict { PACKAGE_PIN U12  IOSTANDARD LVCMOS18 } [get_ports { SOC_GPO7  }]; # VCU118:FMCP_HSPC_HA13_N
set_property -dict { PACKAGE_PIN M11  IOSTANDARD LVCMOS18 } [get_ports { SOC_GPO8  }]; # VCU118:FMCP_HSPC_HA14_P
set_property -dict { PACKAGE_PIN L11  IOSTANDARD LVCMOS18 } [get_ports { SOC_GPO9  }]; # VCU118:FMCP_HSPC_HA14_N
set_property -dict { PACKAGE_PIN M13  IOSTANDARD LVCMOS18 } [get_ports { SOC_GPO10 }]; # VCU118:FMCP_HSPC_HA15_P
set_property -dict { PACKAGE_PIN M12  IOSTANDARD LVCMOS18 } [get_ports { SOC_GPO11 }]; # VCU118:FMCP_HSPC_HA15_N

## Repeated from the Earl Grey XDC:
## TODO: Delete these pins that aren't used on the VCU118. These are specific to the ChipWhisperer
## boards.
set_property -dict { PACKAGE_PIN T14  IOSTANDARD LVCMOS18 } [get_ports { IO_TRIGGER }]; # VCU118:FMC_HSPC_HA16_P
set_property -dict { PACKAGE_PIN R13  IOSTANDARD LVCMOS18 } [get_ports { IO_CLKOUT }];  # VCU118:FMC_HSPC_HA16_N

### MIOs
set_property -dict { PACKAGE_PIN U35  IOSTANDARD LVCMOS18 PULLTYPE PULLDOWN } [get_ports { MIO0  }]; # Darjeeling:TAP_STRAP0 VCU118:FMCP_HSPC_LA29_P
set_property -dict { PACKAGE_PIN V34  IOSTANDARD LVCMOS18 PULLTYPE PULLDOWN } [get_ports { MIO1  }]; # Darjeeling:TAP_STRAP1 VCU118:FMCP_HSPC_LA27_N
set_property -dict { PACKAGE_PIN Y12  IOSTANDARD LVCMOS18                   } [get_ports { MIO2  }]; # Darjeeling:DFT_STRAP0 VCU118:FMCP_HSPC_HA02_N
set_property -dict { PACKAGE_PIN V12  IOSTANDARD LVCMOS18                   } [get_ports { MIO3  }]; # Darjeeling:DFT_STRAP1 VCU118:FMCP_HSPC_HA03_N
set_property -dict { PACKAGE_PIN AA14 IOSTANDARD LVCMOS18                   } [get_ports { MIO4  }]; # VCU118:FMCP_HSPC_HA07_P
set_property -dict { PACKAGE_PIN Y14  IOSTANDARD LVCMOS18                   } [get_ports { MIO5  }]; # VCU118:FMCP_HSPC_HA07_N
set_property -dict { PACKAGE_PIN U11  IOSTANDARD LVCMOS18                   } [get_ports { MIO6  }]; # VCU118:FMCP_HSPC_HA08_P
set_property -dict { PACKAGE_PIN T11  IOSTANDARD LVCMOS18                   } [get_ports { MIO7  }]; # VCU118:FMCP_HSPC_HA08_N
set_property -dict { PACKAGE_PIN W14  IOSTANDARD LVCMOS18                   } [get_ports { MIO8  }]; # VCU118:FMCP_HSPC_HA09_P
set_property -dict { PACKAGE_PIN T16  IOSTANDARD LVCMOS18                   } [get_ports { MIO9  }]; # VCU118:FMCP_HSPC_HA12_P
set_property -dict { PACKAGE_PIN T15  IOSTANDARD LVCMOS18                   } [get_ports { MIO10 }]; # VCU118:FMCP_HSPC_HA12_N
set_property -dict { PACKAGE_PIN V13  IOSTANDARD LVCMOS18                   } [get_ports { MIO11 }]; # VCU118:FMCP_HSPC_HA13_P


## Configuration options, can be used for all designs
set_property CONFIG_VOLTAGE 1.8 [current_design]
set_property CFGBVS GND [current_design]
