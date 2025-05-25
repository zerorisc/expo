# Registers

<!-- BEGIN CMDGEN util/regtool.py -d ./hw/top_daric2/ip_autogen/pinmux/data/pinmux.hjson -->
## Summary

| Name                                                           | Offset   |   Length | Description                                                         |
|:---------------------------------------------------------------|:---------|---------:|:--------------------------------------------------------------------|
| pinmux.[`ALERT_TEST`](#alert_test)                             | 0x0      |        4 | Alert Test Register                                                 |
| pinmux.[`MIO_PERIPH_INSEL_REGWEN_0`](#mio_periph_insel_regwen) | 0x4      |        4 | Register write enable for MIO peripheral input selects.             |
| pinmux.[`MIO_PERIPH_INSEL_REGWEN_1`](#mio_periph_insel_regwen) | 0x8      |        4 | Register write enable for MIO peripheral input selects.             |
| pinmux.[`MIO_PERIPH_INSEL_REGWEN_2`](#mio_periph_insel_regwen) | 0xc      |        4 | Register write enable for MIO peripheral input selects.             |
| pinmux.[`MIO_PERIPH_INSEL_REGWEN_3`](#mio_periph_insel_regwen) | 0x10     |        4 | Register write enable for MIO peripheral input selects.             |
| pinmux.[`MIO_PERIPH_INSEL_0`](#mio_periph_insel)               | 0x14     |        4 | For each peripheral input, this selects the muxable pad input.      |
| pinmux.[`MIO_PERIPH_INSEL_1`](#mio_periph_insel)               | 0x18     |        4 | For each peripheral input, this selects the muxable pad input.      |
| pinmux.[`MIO_PERIPH_INSEL_2`](#mio_periph_insel)               | 0x1c     |        4 | For each peripheral input, this selects the muxable pad input.      |
| pinmux.[`MIO_PERIPH_INSEL_3`](#mio_periph_insel)               | 0x20     |        4 | For each peripheral input, this selects the muxable pad input.      |
| pinmux.[`MIO_OUTSEL_REGWEN_0`](#mio_outsel_regwen)             | 0x24     |        4 | Register write enable for MIO output selects.                       |
| pinmux.[`MIO_OUTSEL_REGWEN_1`](#mio_outsel_regwen)             | 0x28     |        4 | Register write enable for MIO output selects.                       |
| pinmux.[`MIO_OUTSEL_REGWEN_2`](#mio_outsel_regwen)             | 0x2c     |        4 | Register write enable for MIO output selects.                       |
| pinmux.[`MIO_OUTSEL_REGWEN_3`](#mio_outsel_regwen)             | 0x30     |        4 | Register write enable for MIO output selects.                       |
| pinmux.[`MIO_OUTSEL_REGWEN_4`](#mio_outsel_regwen)             | 0x34     |        4 | Register write enable for MIO output selects.                       |
| pinmux.[`MIO_OUTSEL_REGWEN_5`](#mio_outsel_regwen)             | 0x38     |        4 | Register write enable for MIO output selects.                       |
| pinmux.[`MIO_OUTSEL_REGWEN_6`](#mio_outsel_regwen)             | 0x3c     |        4 | Register write enable for MIO output selects.                       |
| pinmux.[`MIO_OUTSEL_REGWEN_7`](#mio_outsel_regwen)             | 0x40     |        4 | Register write enable for MIO output selects.                       |
| pinmux.[`MIO_OUTSEL_REGWEN_8`](#mio_outsel_regwen)             | 0x44     |        4 | Register write enable for MIO output selects.                       |
| pinmux.[`MIO_OUTSEL_REGWEN_9`](#mio_outsel_regwen)             | 0x48     |        4 | Register write enable for MIO output selects.                       |
| pinmux.[`MIO_OUTSEL_REGWEN_10`](#mio_outsel_regwen)            | 0x4c     |        4 | Register write enable for MIO output selects.                       |
| pinmux.[`MIO_OUTSEL_REGWEN_11`](#mio_outsel_regwen)            | 0x50     |        4 | Register write enable for MIO output selects.                       |
| pinmux.[`MIO_OUTSEL_0`](#mio_outsel)                           | 0x54     |        4 | For each muxable pad, this selects the peripheral output.           |
| pinmux.[`MIO_OUTSEL_1`](#mio_outsel)                           | 0x58     |        4 | For each muxable pad, this selects the peripheral output.           |
| pinmux.[`MIO_OUTSEL_2`](#mio_outsel)                           | 0x5c     |        4 | For each muxable pad, this selects the peripheral output.           |
| pinmux.[`MIO_OUTSEL_3`](#mio_outsel)                           | 0x60     |        4 | For each muxable pad, this selects the peripheral output.           |
| pinmux.[`MIO_OUTSEL_4`](#mio_outsel)                           | 0x64     |        4 | For each muxable pad, this selects the peripheral output.           |
| pinmux.[`MIO_OUTSEL_5`](#mio_outsel)                           | 0x68     |        4 | For each muxable pad, this selects the peripheral output.           |
| pinmux.[`MIO_OUTSEL_6`](#mio_outsel)                           | 0x6c     |        4 | For each muxable pad, this selects the peripheral output.           |
| pinmux.[`MIO_OUTSEL_7`](#mio_outsel)                           | 0x70     |        4 | For each muxable pad, this selects the peripheral output.           |
| pinmux.[`MIO_OUTSEL_8`](#mio_outsel)                           | 0x74     |        4 | For each muxable pad, this selects the peripheral output.           |
| pinmux.[`MIO_OUTSEL_9`](#mio_outsel)                           | 0x78     |        4 | For each muxable pad, this selects the peripheral output.           |
| pinmux.[`MIO_OUTSEL_10`](#mio_outsel)                          | 0x7c     |        4 | For each muxable pad, this selects the peripheral output.           |
| pinmux.[`MIO_OUTSEL_11`](#mio_outsel)                          | 0x80     |        4 | For each muxable pad, this selects the peripheral output.           |
| pinmux.[`MIO_PAD_ATTR_REGWEN_0`](#mio_pad_attr_regwen)         | 0x84     |        4 | Register write enable for MIO PAD attributes.                       |
| pinmux.[`MIO_PAD_ATTR_REGWEN_1`](#mio_pad_attr_regwen)         | 0x88     |        4 | Register write enable for MIO PAD attributes.                       |
| pinmux.[`MIO_PAD_ATTR_REGWEN_2`](#mio_pad_attr_regwen)         | 0x8c     |        4 | Register write enable for MIO PAD attributes.                       |
| pinmux.[`MIO_PAD_ATTR_REGWEN_3`](#mio_pad_attr_regwen)         | 0x90     |        4 | Register write enable for MIO PAD attributes.                       |
| pinmux.[`MIO_PAD_ATTR_REGWEN_4`](#mio_pad_attr_regwen)         | 0x94     |        4 | Register write enable for MIO PAD attributes.                       |
| pinmux.[`MIO_PAD_ATTR_REGWEN_5`](#mio_pad_attr_regwen)         | 0x98     |        4 | Register write enable for MIO PAD attributes.                       |
| pinmux.[`MIO_PAD_ATTR_REGWEN_6`](#mio_pad_attr_regwen)         | 0x9c     |        4 | Register write enable for MIO PAD attributes.                       |
| pinmux.[`MIO_PAD_ATTR_REGWEN_7`](#mio_pad_attr_regwen)         | 0xa0     |        4 | Register write enable for MIO PAD attributes.                       |
| pinmux.[`MIO_PAD_ATTR_REGWEN_8`](#mio_pad_attr_regwen)         | 0xa4     |        4 | Register write enable for MIO PAD attributes.                       |
| pinmux.[`MIO_PAD_ATTR_REGWEN_9`](#mio_pad_attr_regwen)         | 0xa8     |        4 | Register write enable for MIO PAD attributes.                       |
| pinmux.[`MIO_PAD_ATTR_REGWEN_10`](#mio_pad_attr_regwen)        | 0xac     |        4 | Register write enable for MIO PAD attributes.                       |
| pinmux.[`MIO_PAD_ATTR_REGWEN_11`](#mio_pad_attr_regwen)        | 0xb0     |        4 | Register write enable for MIO PAD attributes.                       |
| pinmux.[`MIO_PAD_ATTR_0`](#mio_pad_attr)                       | 0xb4     |        4 | Muxed pad attributes.                                               |
| pinmux.[`MIO_PAD_ATTR_1`](#mio_pad_attr)                       | 0xb8     |        4 | Muxed pad attributes.                                               |
| pinmux.[`MIO_PAD_ATTR_2`](#mio_pad_attr)                       | 0xbc     |        4 | Muxed pad attributes.                                               |
| pinmux.[`MIO_PAD_ATTR_3`](#mio_pad_attr)                       | 0xc0     |        4 | Muxed pad attributes.                                               |
| pinmux.[`MIO_PAD_ATTR_4`](#mio_pad_attr)                       | 0xc4     |        4 | Muxed pad attributes.                                               |
| pinmux.[`MIO_PAD_ATTR_5`](#mio_pad_attr)                       | 0xc8     |        4 | Muxed pad attributes.                                               |
| pinmux.[`MIO_PAD_ATTR_6`](#mio_pad_attr)                       | 0xcc     |        4 | Muxed pad attributes.                                               |
| pinmux.[`MIO_PAD_ATTR_7`](#mio_pad_attr)                       | 0xd0     |        4 | Muxed pad attributes.                                               |
| pinmux.[`MIO_PAD_ATTR_8`](#mio_pad_attr)                       | 0xd4     |        4 | Muxed pad attributes.                                               |
| pinmux.[`MIO_PAD_ATTR_9`](#mio_pad_attr)                       | 0xd8     |        4 | Muxed pad attributes.                                               |
| pinmux.[`MIO_PAD_ATTR_10`](#mio_pad_attr)                      | 0xdc     |        4 | Muxed pad attributes.                                               |
| pinmux.[`MIO_PAD_ATTR_11`](#mio_pad_attr)                      | 0xe0     |        4 | Muxed pad attributes.                                               |
| pinmux.[`DIO_PAD_ATTR_REGWEN_0`](#dio_pad_attr_regwen)         | 0xe4     |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_1`](#dio_pad_attr_regwen)         | 0xe8     |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_2`](#dio_pad_attr_regwen)         | 0xec     |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_3`](#dio_pad_attr_regwen)         | 0xf0     |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_4`](#dio_pad_attr_regwen)         | 0xf4     |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_5`](#dio_pad_attr_regwen)         | 0xf8     |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_6`](#dio_pad_attr_regwen)         | 0xfc     |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_7`](#dio_pad_attr_regwen)         | 0x100    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_8`](#dio_pad_attr_regwen)         | 0x104    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_9`](#dio_pad_attr_regwen)         | 0x108    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_10`](#dio_pad_attr_regwen)        | 0x10c    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_11`](#dio_pad_attr_regwen)        | 0x110    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_12`](#dio_pad_attr_regwen)        | 0x114    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_13`](#dio_pad_attr_regwen)        | 0x118    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_14`](#dio_pad_attr_regwen)        | 0x11c    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_15`](#dio_pad_attr_regwen)        | 0x120    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_16`](#dio_pad_attr_regwen)        | 0x124    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_17`](#dio_pad_attr_regwen)        | 0x128    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_18`](#dio_pad_attr_regwen)        | 0x12c    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_19`](#dio_pad_attr_regwen)        | 0x130    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_20`](#dio_pad_attr_regwen)        | 0x134    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_21`](#dio_pad_attr_regwen)        | 0x138    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_22`](#dio_pad_attr_regwen)        | 0x13c    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_23`](#dio_pad_attr_regwen)        | 0x140    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_24`](#dio_pad_attr_regwen)        | 0x144    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_25`](#dio_pad_attr_regwen)        | 0x148    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_26`](#dio_pad_attr_regwen)        | 0x14c    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_27`](#dio_pad_attr_regwen)        | 0x150    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_28`](#dio_pad_attr_regwen)        | 0x154    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_29`](#dio_pad_attr_regwen)        | 0x158    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_30`](#dio_pad_attr_regwen)        | 0x15c    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_31`](#dio_pad_attr_regwen)        | 0x160    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_32`](#dio_pad_attr_regwen)        | 0x164    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_33`](#dio_pad_attr_regwen)        | 0x168    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_34`](#dio_pad_attr_regwen)        | 0x16c    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_35`](#dio_pad_attr_regwen)        | 0x170    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_36`](#dio_pad_attr_regwen)        | 0x174    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_37`](#dio_pad_attr_regwen)        | 0x178    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_38`](#dio_pad_attr_regwen)        | 0x17c    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_39`](#dio_pad_attr_regwen)        | 0x180    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_40`](#dio_pad_attr_regwen)        | 0x184    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_41`](#dio_pad_attr_regwen)        | 0x188    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_42`](#dio_pad_attr_regwen)        | 0x18c    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_43`](#dio_pad_attr_regwen)        | 0x190    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_44`](#dio_pad_attr_regwen)        | 0x194    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_45`](#dio_pad_attr_regwen)        | 0x198    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_46`](#dio_pad_attr_regwen)        | 0x19c    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_47`](#dio_pad_attr_regwen)        | 0x1a0    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_48`](#dio_pad_attr_regwen)        | 0x1a4    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_49`](#dio_pad_attr_regwen)        | 0x1a8    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_50`](#dio_pad_attr_regwen)        | 0x1ac    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_51`](#dio_pad_attr_regwen)        | 0x1b0    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_52`](#dio_pad_attr_regwen)        | 0x1b4    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_53`](#dio_pad_attr_regwen)        | 0x1b8    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_54`](#dio_pad_attr_regwen)        | 0x1bc    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_55`](#dio_pad_attr_regwen)        | 0x1c0    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_56`](#dio_pad_attr_regwen)        | 0x1c4    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_REGWEN_57`](#dio_pad_attr_regwen)        | 0x1c8    |        4 | Register write enable for DIO PAD attributes.                       |
| pinmux.[`DIO_PAD_ATTR_0`](#dio_pad_attr)                       | 0x1cc    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_1`](#dio_pad_attr)                       | 0x1d0    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_2`](#dio_pad_attr)                       | 0x1d4    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_3`](#dio_pad_attr)                       | 0x1d8    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_4`](#dio_pad_attr)                       | 0x1dc    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_5`](#dio_pad_attr)                       | 0x1e0    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_6`](#dio_pad_attr)                       | 0x1e4    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_7`](#dio_pad_attr)                       | 0x1e8    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_8`](#dio_pad_attr)                       | 0x1ec    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_9`](#dio_pad_attr)                       | 0x1f0    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_10`](#dio_pad_attr)                      | 0x1f4    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_11`](#dio_pad_attr)                      | 0x1f8    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_12`](#dio_pad_attr)                      | 0x1fc    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_13`](#dio_pad_attr)                      | 0x200    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_14`](#dio_pad_attr)                      | 0x204    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_15`](#dio_pad_attr)                      | 0x208    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_16`](#dio_pad_attr)                      | 0x20c    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_17`](#dio_pad_attr)                      | 0x210    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_18`](#dio_pad_attr)                      | 0x214    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_19`](#dio_pad_attr)                      | 0x218    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_20`](#dio_pad_attr)                      | 0x21c    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_21`](#dio_pad_attr)                      | 0x220    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_22`](#dio_pad_attr)                      | 0x224    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_23`](#dio_pad_attr)                      | 0x228    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_24`](#dio_pad_attr)                      | 0x22c    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_25`](#dio_pad_attr)                      | 0x230    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_26`](#dio_pad_attr)                      | 0x234    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_27`](#dio_pad_attr)                      | 0x238    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_28`](#dio_pad_attr)                      | 0x23c    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_29`](#dio_pad_attr)                      | 0x240    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_30`](#dio_pad_attr)                      | 0x244    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_31`](#dio_pad_attr)                      | 0x248    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_32`](#dio_pad_attr)                      | 0x24c    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_33`](#dio_pad_attr)                      | 0x250    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_34`](#dio_pad_attr)                      | 0x254    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_35`](#dio_pad_attr)                      | 0x258    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_36`](#dio_pad_attr)                      | 0x25c    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_37`](#dio_pad_attr)                      | 0x260    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_38`](#dio_pad_attr)                      | 0x264    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_39`](#dio_pad_attr)                      | 0x268    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_40`](#dio_pad_attr)                      | 0x26c    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_41`](#dio_pad_attr)                      | 0x270    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_42`](#dio_pad_attr)                      | 0x274    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_43`](#dio_pad_attr)                      | 0x278    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_44`](#dio_pad_attr)                      | 0x27c    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_45`](#dio_pad_attr)                      | 0x280    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_46`](#dio_pad_attr)                      | 0x284    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_47`](#dio_pad_attr)                      | 0x288    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_48`](#dio_pad_attr)                      | 0x28c    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_49`](#dio_pad_attr)                      | 0x290    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_50`](#dio_pad_attr)                      | 0x294    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_51`](#dio_pad_attr)                      | 0x298    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_52`](#dio_pad_attr)                      | 0x29c    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_53`](#dio_pad_attr)                      | 0x2a0    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_54`](#dio_pad_attr)                      | 0x2a4    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_55`](#dio_pad_attr)                      | 0x2a8    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_56`](#dio_pad_attr)                      | 0x2ac    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`DIO_PAD_ATTR_57`](#dio_pad_attr)                      | 0x2b0    |        4 | Dedicated pad attributes.                                           |
| pinmux.[`MIO_PAD_SLEEP_STATUS`](#mio_pad_sleep_status)         | 0x2b4    |        4 | Register indicating whether the corresponding pad is in sleep mode. |
| pinmux.[`MIO_PAD_SLEEP_REGWEN_0`](#mio_pad_sleep_regwen)       | 0x2b8    |        4 | Register write enable for MIO sleep value configuration.            |
| pinmux.[`MIO_PAD_SLEEP_REGWEN_1`](#mio_pad_sleep_regwen)       | 0x2bc    |        4 | Register write enable for MIO sleep value configuration.            |
| pinmux.[`MIO_PAD_SLEEP_REGWEN_2`](#mio_pad_sleep_regwen)       | 0x2c0    |        4 | Register write enable for MIO sleep value configuration.            |
| pinmux.[`MIO_PAD_SLEEP_REGWEN_3`](#mio_pad_sleep_regwen)       | 0x2c4    |        4 | Register write enable for MIO sleep value configuration.            |
| pinmux.[`MIO_PAD_SLEEP_REGWEN_4`](#mio_pad_sleep_regwen)       | 0x2c8    |        4 | Register write enable for MIO sleep value configuration.            |
| pinmux.[`MIO_PAD_SLEEP_REGWEN_5`](#mio_pad_sleep_regwen)       | 0x2cc    |        4 | Register write enable for MIO sleep value configuration.            |
| pinmux.[`MIO_PAD_SLEEP_REGWEN_6`](#mio_pad_sleep_regwen)       | 0x2d0    |        4 | Register write enable for MIO sleep value configuration.            |
| pinmux.[`MIO_PAD_SLEEP_REGWEN_7`](#mio_pad_sleep_regwen)       | 0x2d4    |        4 | Register write enable for MIO sleep value configuration.            |
| pinmux.[`MIO_PAD_SLEEP_REGWEN_8`](#mio_pad_sleep_regwen)       | 0x2d8    |        4 | Register write enable for MIO sleep value configuration.            |
| pinmux.[`MIO_PAD_SLEEP_REGWEN_9`](#mio_pad_sleep_regwen)       | 0x2dc    |        4 | Register write enable for MIO sleep value configuration.            |
| pinmux.[`MIO_PAD_SLEEP_REGWEN_10`](#mio_pad_sleep_regwen)      | 0x2e0    |        4 | Register write enable for MIO sleep value configuration.            |
| pinmux.[`MIO_PAD_SLEEP_REGWEN_11`](#mio_pad_sleep_regwen)      | 0x2e4    |        4 | Register write enable for MIO sleep value configuration.            |
| pinmux.[`MIO_PAD_SLEEP_EN_0`](#mio_pad_sleep_en)               | 0x2e8    |        4 | Enables the sleep mode of the corresponding muxed pad.              |
| pinmux.[`MIO_PAD_SLEEP_EN_1`](#mio_pad_sleep_en)               | 0x2ec    |        4 | Enables the sleep mode of the corresponding muxed pad.              |
| pinmux.[`MIO_PAD_SLEEP_EN_2`](#mio_pad_sleep_en)               | 0x2f0    |        4 | Enables the sleep mode of the corresponding muxed pad.              |
| pinmux.[`MIO_PAD_SLEEP_EN_3`](#mio_pad_sleep_en)               | 0x2f4    |        4 | Enables the sleep mode of the corresponding muxed pad.              |
| pinmux.[`MIO_PAD_SLEEP_EN_4`](#mio_pad_sleep_en)               | 0x2f8    |        4 | Enables the sleep mode of the corresponding muxed pad.              |
| pinmux.[`MIO_PAD_SLEEP_EN_5`](#mio_pad_sleep_en)               | 0x2fc    |        4 | Enables the sleep mode of the corresponding muxed pad.              |
| pinmux.[`MIO_PAD_SLEEP_EN_6`](#mio_pad_sleep_en)               | 0x300    |        4 | Enables the sleep mode of the corresponding muxed pad.              |
| pinmux.[`MIO_PAD_SLEEP_EN_7`](#mio_pad_sleep_en)               | 0x304    |        4 | Enables the sleep mode of the corresponding muxed pad.              |
| pinmux.[`MIO_PAD_SLEEP_EN_8`](#mio_pad_sleep_en)               | 0x308    |        4 | Enables the sleep mode of the corresponding muxed pad.              |
| pinmux.[`MIO_PAD_SLEEP_EN_9`](#mio_pad_sleep_en)               | 0x30c    |        4 | Enables the sleep mode of the corresponding muxed pad.              |
| pinmux.[`MIO_PAD_SLEEP_EN_10`](#mio_pad_sleep_en)              | 0x310    |        4 | Enables the sleep mode of the corresponding muxed pad.              |
| pinmux.[`MIO_PAD_SLEEP_EN_11`](#mio_pad_sleep_en)              | 0x314    |        4 | Enables the sleep mode of the corresponding muxed pad.              |
| pinmux.[`MIO_PAD_SLEEP_MODE_0`](#mio_pad_sleep_mode)           | 0x318    |        4 | Defines sleep behavior of the corresponding muxed pad.              |
| pinmux.[`MIO_PAD_SLEEP_MODE_1`](#mio_pad_sleep_mode)           | 0x31c    |        4 | Defines sleep behavior of the corresponding muxed pad.              |
| pinmux.[`MIO_PAD_SLEEP_MODE_2`](#mio_pad_sleep_mode)           | 0x320    |        4 | Defines sleep behavior of the corresponding muxed pad.              |
| pinmux.[`MIO_PAD_SLEEP_MODE_3`](#mio_pad_sleep_mode)           | 0x324    |        4 | Defines sleep behavior of the corresponding muxed pad.              |
| pinmux.[`MIO_PAD_SLEEP_MODE_4`](#mio_pad_sleep_mode)           | 0x328    |        4 | Defines sleep behavior of the corresponding muxed pad.              |
| pinmux.[`MIO_PAD_SLEEP_MODE_5`](#mio_pad_sleep_mode)           | 0x32c    |        4 | Defines sleep behavior of the corresponding muxed pad.              |
| pinmux.[`MIO_PAD_SLEEP_MODE_6`](#mio_pad_sleep_mode)           | 0x330    |        4 | Defines sleep behavior of the corresponding muxed pad.              |
| pinmux.[`MIO_PAD_SLEEP_MODE_7`](#mio_pad_sleep_mode)           | 0x334    |        4 | Defines sleep behavior of the corresponding muxed pad.              |
| pinmux.[`MIO_PAD_SLEEP_MODE_8`](#mio_pad_sleep_mode)           | 0x338    |        4 | Defines sleep behavior of the corresponding muxed pad.              |
| pinmux.[`MIO_PAD_SLEEP_MODE_9`](#mio_pad_sleep_mode)           | 0x33c    |        4 | Defines sleep behavior of the corresponding muxed pad.              |
| pinmux.[`MIO_PAD_SLEEP_MODE_10`](#mio_pad_sleep_mode)          | 0x340    |        4 | Defines sleep behavior of the corresponding muxed pad.              |
| pinmux.[`MIO_PAD_SLEEP_MODE_11`](#mio_pad_sleep_mode)          | 0x344    |        4 | Defines sleep behavior of the corresponding muxed pad.              |
| pinmux.[`DIO_PAD_SLEEP_STATUS_0`](#dio_pad_sleep_status_0)     | 0x348    |        4 | Register indicating whether the corresponding pad is in sleep mode. |
| pinmux.[`DIO_PAD_SLEEP_STATUS_1`](#dio_pad_sleep_status_1)     | 0x34c    |        4 | Register indicating whether the corresponding pad is in sleep mode. |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_0`](#dio_pad_sleep_regwen)       | 0x350    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_1`](#dio_pad_sleep_regwen)       | 0x354    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_2`](#dio_pad_sleep_regwen)       | 0x358    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_3`](#dio_pad_sleep_regwen)       | 0x35c    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_4`](#dio_pad_sleep_regwen)       | 0x360    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_5`](#dio_pad_sleep_regwen)       | 0x364    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_6`](#dio_pad_sleep_regwen)       | 0x368    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_7`](#dio_pad_sleep_regwen)       | 0x36c    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_8`](#dio_pad_sleep_regwen)       | 0x370    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_9`](#dio_pad_sleep_regwen)       | 0x374    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_10`](#dio_pad_sleep_regwen)      | 0x378    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_11`](#dio_pad_sleep_regwen)      | 0x37c    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_12`](#dio_pad_sleep_regwen)      | 0x380    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_13`](#dio_pad_sleep_regwen)      | 0x384    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_14`](#dio_pad_sleep_regwen)      | 0x388    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_15`](#dio_pad_sleep_regwen)      | 0x38c    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_16`](#dio_pad_sleep_regwen)      | 0x390    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_17`](#dio_pad_sleep_regwen)      | 0x394    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_18`](#dio_pad_sleep_regwen)      | 0x398    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_19`](#dio_pad_sleep_regwen)      | 0x39c    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_20`](#dio_pad_sleep_regwen)      | 0x3a0    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_21`](#dio_pad_sleep_regwen)      | 0x3a4    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_22`](#dio_pad_sleep_regwen)      | 0x3a8    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_23`](#dio_pad_sleep_regwen)      | 0x3ac    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_24`](#dio_pad_sleep_regwen)      | 0x3b0    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_25`](#dio_pad_sleep_regwen)      | 0x3b4    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_26`](#dio_pad_sleep_regwen)      | 0x3b8    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_27`](#dio_pad_sleep_regwen)      | 0x3bc    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_28`](#dio_pad_sleep_regwen)      | 0x3c0    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_29`](#dio_pad_sleep_regwen)      | 0x3c4    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_30`](#dio_pad_sleep_regwen)      | 0x3c8    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_31`](#dio_pad_sleep_regwen)      | 0x3cc    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_32`](#dio_pad_sleep_regwen)      | 0x3d0    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_33`](#dio_pad_sleep_regwen)      | 0x3d4    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_34`](#dio_pad_sleep_regwen)      | 0x3d8    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_35`](#dio_pad_sleep_regwen)      | 0x3dc    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_36`](#dio_pad_sleep_regwen)      | 0x3e0    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_37`](#dio_pad_sleep_regwen)      | 0x3e4    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_38`](#dio_pad_sleep_regwen)      | 0x3e8    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_39`](#dio_pad_sleep_regwen)      | 0x3ec    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_40`](#dio_pad_sleep_regwen)      | 0x3f0    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_41`](#dio_pad_sleep_regwen)      | 0x3f4    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_42`](#dio_pad_sleep_regwen)      | 0x3f8    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_43`](#dio_pad_sleep_regwen)      | 0x3fc    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_44`](#dio_pad_sleep_regwen)      | 0x400    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_45`](#dio_pad_sleep_regwen)      | 0x404    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_46`](#dio_pad_sleep_regwen)      | 0x408    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_47`](#dio_pad_sleep_regwen)      | 0x40c    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_48`](#dio_pad_sleep_regwen)      | 0x410    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_49`](#dio_pad_sleep_regwen)      | 0x414    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_50`](#dio_pad_sleep_regwen)      | 0x418    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_51`](#dio_pad_sleep_regwen)      | 0x41c    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_52`](#dio_pad_sleep_regwen)      | 0x420    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_53`](#dio_pad_sleep_regwen)      | 0x424    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_54`](#dio_pad_sleep_regwen)      | 0x428    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_55`](#dio_pad_sleep_regwen)      | 0x42c    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_56`](#dio_pad_sleep_regwen)      | 0x430    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_REGWEN_57`](#dio_pad_sleep_regwen)      | 0x434    |        4 | Register write enable for DIO sleep value configuration.            |
| pinmux.[`DIO_PAD_SLEEP_EN_0`](#dio_pad_sleep_en)               | 0x438    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_1`](#dio_pad_sleep_en)               | 0x43c    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_2`](#dio_pad_sleep_en)               | 0x440    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_3`](#dio_pad_sleep_en)               | 0x444    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_4`](#dio_pad_sleep_en)               | 0x448    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_5`](#dio_pad_sleep_en)               | 0x44c    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_6`](#dio_pad_sleep_en)               | 0x450    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_7`](#dio_pad_sleep_en)               | 0x454    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_8`](#dio_pad_sleep_en)               | 0x458    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_9`](#dio_pad_sleep_en)               | 0x45c    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_10`](#dio_pad_sleep_en)              | 0x460    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_11`](#dio_pad_sleep_en)              | 0x464    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_12`](#dio_pad_sleep_en)              | 0x468    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_13`](#dio_pad_sleep_en)              | 0x46c    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_14`](#dio_pad_sleep_en)              | 0x470    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_15`](#dio_pad_sleep_en)              | 0x474    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_16`](#dio_pad_sleep_en)              | 0x478    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_17`](#dio_pad_sleep_en)              | 0x47c    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_18`](#dio_pad_sleep_en)              | 0x480    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_19`](#dio_pad_sleep_en)              | 0x484    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_20`](#dio_pad_sleep_en)              | 0x488    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_21`](#dio_pad_sleep_en)              | 0x48c    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_22`](#dio_pad_sleep_en)              | 0x490    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_23`](#dio_pad_sleep_en)              | 0x494    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_24`](#dio_pad_sleep_en)              | 0x498    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_25`](#dio_pad_sleep_en)              | 0x49c    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_26`](#dio_pad_sleep_en)              | 0x4a0    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_27`](#dio_pad_sleep_en)              | 0x4a4    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_28`](#dio_pad_sleep_en)              | 0x4a8    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_29`](#dio_pad_sleep_en)              | 0x4ac    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_30`](#dio_pad_sleep_en)              | 0x4b0    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_31`](#dio_pad_sleep_en)              | 0x4b4    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_32`](#dio_pad_sleep_en)              | 0x4b8    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_33`](#dio_pad_sleep_en)              | 0x4bc    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_34`](#dio_pad_sleep_en)              | 0x4c0    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_35`](#dio_pad_sleep_en)              | 0x4c4    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_36`](#dio_pad_sleep_en)              | 0x4c8    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_37`](#dio_pad_sleep_en)              | 0x4cc    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_38`](#dio_pad_sleep_en)              | 0x4d0    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_39`](#dio_pad_sleep_en)              | 0x4d4    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_40`](#dio_pad_sleep_en)              | 0x4d8    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_41`](#dio_pad_sleep_en)              | 0x4dc    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_42`](#dio_pad_sleep_en)              | 0x4e0    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_43`](#dio_pad_sleep_en)              | 0x4e4    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_44`](#dio_pad_sleep_en)              | 0x4e8    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_45`](#dio_pad_sleep_en)              | 0x4ec    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_46`](#dio_pad_sleep_en)              | 0x4f0    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_47`](#dio_pad_sleep_en)              | 0x4f4    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_48`](#dio_pad_sleep_en)              | 0x4f8    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_49`](#dio_pad_sleep_en)              | 0x4fc    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_50`](#dio_pad_sleep_en)              | 0x500    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_51`](#dio_pad_sleep_en)              | 0x504    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_52`](#dio_pad_sleep_en)              | 0x508    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_53`](#dio_pad_sleep_en)              | 0x50c    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_54`](#dio_pad_sleep_en)              | 0x510    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_55`](#dio_pad_sleep_en)              | 0x514    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_56`](#dio_pad_sleep_en)              | 0x518    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_EN_57`](#dio_pad_sleep_en)              | 0x51c    |        4 | Enables the sleep mode of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_0`](#dio_pad_sleep_mode)           | 0x520    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_1`](#dio_pad_sleep_mode)           | 0x524    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_2`](#dio_pad_sleep_mode)           | 0x528    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_3`](#dio_pad_sleep_mode)           | 0x52c    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_4`](#dio_pad_sleep_mode)           | 0x530    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_5`](#dio_pad_sleep_mode)           | 0x534    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_6`](#dio_pad_sleep_mode)           | 0x538    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_7`](#dio_pad_sleep_mode)           | 0x53c    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_8`](#dio_pad_sleep_mode)           | 0x540    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_9`](#dio_pad_sleep_mode)           | 0x544    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_10`](#dio_pad_sleep_mode)          | 0x548    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_11`](#dio_pad_sleep_mode)          | 0x54c    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_12`](#dio_pad_sleep_mode)          | 0x550    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_13`](#dio_pad_sleep_mode)          | 0x554    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_14`](#dio_pad_sleep_mode)          | 0x558    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_15`](#dio_pad_sleep_mode)          | 0x55c    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_16`](#dio_pad_sleep_mode)          | 0x560    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_17`](#dio_pad_sleep_mode)          | 0x564    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_18`](#dio_pad_sleep_mode)          | 0x568    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_19`](#dio_pad_sleep_mode)          | 0x56c    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_20`](#dio_pad_sleep_mode)          | 0x570    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_21`](#dio_pad_sleep_mode)          | 0x574    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_22`](#dio_pad_sleep_mode)          | 0x578    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_23`](#dio_pad_sleep_mode)          | 0x57c    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_24`](#dio_pad_sleep_mode)          | 0x580    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_25`](#dio_pad_sleep_mode)          | 0x584    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_26`](#dio_pad_sleep_mode)          | 0x588    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_27`](#dio_pad_sleep_mode)          | 0x58c    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_28`](#dio_pad_sleep_mode)          | 0x590    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_29`](#dio_pad_sleep_mode)          | 0x594    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_30`](#dio_pad_sleep_mode)          | 0x598    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_31`](#dio_pad_sleep_mode)          | 0x59c    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_32`](#dio_pad_sleep_mode)          | 0x5a0    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_33`](#dio_pad_sleep_mode)          | 0x5a4    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_34`](#dio_pad_sleep_mode)          | 0x5a8    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_35`](#dio_pad_sleep_mode)          | 0x5ac    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_36`](#dio_pad_sleep_mode)          | 0x5b0    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_37`](#dio_pad_sleep_mode)          | 0x5b4    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_38`](#dio_pad_sleep_mode)          | 0x5b8    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_39`](#dio_pad_sleep_mode)          | 0x5bc    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_40`](#dio_pad_sleep_mode)          | 0x5c0    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_41`](#dio_pad_sleep_mode)          | 0x5c4    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_42`](#dio_pad_sleep_mode)          | 0x5c8    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_43`](#dio_pad_sleep_mode)          | 0x5cc    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_44`](#dio_pad_sleep_mode)          | 0x5d0    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_45`](#dio_pad_sleep_mode)          | 0x5d4    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_46`](#dio_pad_sleep_mode)          | 0x5d8    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_47`](#dio_pad_sleep_mode)          | 0x5dc    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_48`](#dio_pad_sleep_mode)          | 0x5e0    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_49`](#dio_pad_sleep_mode)          | 0x5e4    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_50`](#dio_pad_sleep_mode)          | 0x5e8    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_51`](#dio_pad_sleep_mode)          | 0x5ec    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_52`](#dio_pad_sleep_mode)          | 0x5f0    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_53`](#dio_pad_sleep_mode)          | 0x5f4    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_54`](#dio_pad_sleep_mode)          | 0x5f8    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_55`](#dio_pad_sleep_mode)          | 0x5fc    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_56`](#dio_pad_sleep_mode)          | 0x600    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`DIO_PAD_SLEEP_MODE_57`](#dio_pad_sleep_mode)          | 0x604    |        4 | Defines sleep behavior of the corresponding dedicated pad.          |
| pinmux.[`WKUP_DETECTOR_REGWEN_0`](#wkup_detector_regwen)       | 0x608    |        4 | Register write enable for wakeup detectors.                         |
| pinmux.[`WKUP_DETECTOR_REGWEN_1`](#wkup_detector_regwen)       | 0x60c    |        4 | Register write enable for wakeup detectors.                         |
| pinmux.[`WKUP_DETECTOR_REGWEN_2`](#wkup_detector_regwen)       | 0x610    |        4 | Register write enable for wakeup detectors.                         |
| pinmux.[`WKUP_DETECTOR_REGWEN_3`](#wkup_detector_regwen)       | 0x614    |        4 | Register write enable for wakeup detectors.                         |
| pinmux.[`WKUP_DETECTOR_REGWEN_4`](#wkup_detector_regwen)       | 0x618    |        4 | Register write enable for wakeup detectors.                         |
| pinmux.[`WKUP_DETECTOR_REGWEN_5`](#wkup_detector_regwen)       | 0x61c    |        4 | Register write enable for wakeup detectors.                         |
| pinmux.[`WKUP_DETECTOR_REGWEN_6`](#wkup_detector_regwen)       | 0x620    |        4 | Register write enable for wakeup detectors.                         |
| pinmux.[`WKUP_DETECTOR_REGWEN_7`](#wkup_detector_regwen)       | 0x624    |        4 | Register write enable for wakeup detectors.                         |
| pinmux.[`WKUP_DETECTOR_EN_0`](#wkup_detector_en)               | 0x628    |        4 | Enables for the wakeup detectors.                                   |
| pinmux.[`WKUP_DETECTOR_EN_1`](#wkup_detector_en)               | 0x62c    |        4 | Enables for the wakeup detectors.                                   |
| pinmux.[`WKUP_DETECTOR_EN_2`](#wkup_detector_en)               | 0x630    |        4 | Enables for the wakeup detectors.                                   |
| pinmux.[`WKUP_DETECTOR_EN_3`](#wkup_detector_en)               | 0x634    |        4 | Enables for the wakeup detectors.                                   |
| pinmux.[`WKUP_DETECTOR_EN_4`](#wkup_detector_en)               | 0x638    |        4 | Enables for the wakeup detectors.                                   |
| pinmux.[`WKUP_DETECTOR_EN_5`](#wkup_detector_en)               | 0x63c    |        4 | Enables for the wakeup detectors.                                   |
| pinmux.[`WKUP_DETECTOR_EN_6`](#wkup_detector_en)               | 0x640    |        4 | Enables for the wakeup detectors.                                   |
| pinmux.[`WKUP_DETECTOR_EN_7`](#wkup_detector_en)               | 0x644    |        4 | Enables for the wakeup detectors.                                   |
| pinmux.[`WKUP_DETECTOR_0`](#wkup_detector)                     | 0x648    |        4 | Configuration of wakeup condition detectors.                        |
| pinmux.[`WKUP_DETECTOR_1`](#wkup_detector)                     | 0x64c    |        4 | Configuration of wakeup condition detectors.                        |
| pinmux.[`WKUP_DETECTOR_2`](#wkup_detector)                     | 0x650    |        4 | Configuration of wakeup condition detectors.                        |
| pinmux.[`WKUP_DETECTOR_3`](#wkup_detector)                     | 0x654    |        4 | Configuration of wakeup condition detectors.                        |
| pinmux.[`WKUP_DETECTOR_4`](#wkup_detector)                     | 0x658    |        4 | Configuration of wakeup condition detectors.                        |
| pinmux.[`WKUP_DETECTOR_5`](#wkup_detector)                     | 0x65c    |        4 | Configuration of wakeup condition detectors.                        |
| pinmux.[`WKUP_DETECTOR_6`](#wkup_detector)                     | 0x660    |        4 | Configuration of wakeup condition detectors.                        |
| pinmux.[`WKUP_DETECTOR_7`](#wkup_detector)                     | 0x664    |        4 | Configuration of wakeup condition detectors.                        |
| pinmux.[`WKUP_DETECTOR_CNT_TH_0`](#wkup_detector_cnt_th)       | 0x668    |        4 | Counter thresholds for wakeup condition detectors.                  |
| pinmux.[`WKUP_DETECTOR_CNT_TH_1`](#wkup_detector_cnt_th)       | 0x66c    |        4 | Counter thresholds for wakeup condition detectors.                  |
| pinmux.[`WKUP_DETECTOR_CNT_TH_2`](#wkup_detector_cnt_th)       | 0x670    |        4 | Counter thresholds for wakeup condition detectors.                  |
| pinmux.[`WKUP_DETECTOR_CNT_TH_3`](#wkup_detector_cnt_th)       | 0x674    |        4 | Counter thresholds for wakeup condition detectors.                  |
| pinmux.[`WKUP_DETECTOR_CNT_TH_4`](#wkup_detector_cnt_th)       | 0x678    |        4 | Counter thresholds for wakeup condition detectors.                  |
| pinmux.[`WKUP_DETECTOR_CNT_TH_5`](#wkup_detector_cnt_th)       | 0x67c    |        4 | Counter thresholds for wakeup condition detectors.                  |
| pinmux.[`WKUP_DETECTOR_CNT_TH_6`](#wkup_detector_cnt_th)       | 0x680    |        4 | Counter thresholds for wakeup condition detectors.                  |
| pinmux.[`WKUP_DETECTOR_CNT_TH_7`](#wkup_detector_cnt_th)       | 0x684    |        4 | Counter thresholds for wakeup condition detectors.                  |
| pinmux.[`WKUP_DETECTOR_PADSEL_0`](#wkup_detector_padsel)       | 0x688    |        4 | Pad selects for pad wakeup condition detectors.                     |
| pinmux.[`WKUP_DETECTOR_PADSEL_1`](#wkup_detector_padsel)       | 0x68c    |        4 | Pad selects for pad wakeup condition detectors.                     |
| pinmux.[`WKUP_DETECTOR_PADSEL_2`](#wkup_detector_padsel)       | 0x690    |        4 | Pad selects for pad wakeup condition detectors.                     |
| pinmux.[`WKUP_DETECTOR_PADSEL_3`](#wkup_detector_padsel)       | 0x694    |        4 | Pad selects for pad wakeup condition detectors.                     |
| pinmux.[`WKUP_DETECTOR_PADSEL_4`](#wkup_detector_padsel)       | 0x698    |        4 | Pad selects for pad wakeup condition detectors.                     |
| pinmux.[`WKUP_DETECTOR_PADSEL_5`](#wkup_detector_padsel)       | 0x69c    |        4 | Pad selects for pad wakeup condition detectors.                     |
| pinmux.[`WKUP_DETECTOR_PADSEL_6`](#wkup_detector_padsel)       | 0x6a0    |        4 | Pad selects for pad wakeup condition detectors.                     |
| pinmux.[`WKUP_DETECTOR_PADSEL_7`](#wkup_detector_padsel)       | 0x6a4    |        4 | Pad selects for pad wakeup condition detectors.                     |
| pinmux.[`WKUP_CAUSE`](#wkup_cause)                             | 0x6a8    |        4 | Cause registers for wakeup detectors.                               |

## ALERT_TEST
Alert Test Register
- Offset: `0x0`
- Reset default: `0x0`
- Reset mask: `0x1`

### Fields

```wavejson
{"reg": [{"name": "fatal_fault", "bits": 1, "attr": ["wo"], "rotate": -90}, {"bits": 31}], "config": {"lanes": 1, "fontsize": 10, "vspace": 130}}
```

|  Bits  |  Type  |  Reset  | Name        | Description                                      |
|:------:|:------:|:-------:|:------------|:-------------------------------------------------|
|  31:1  |        |         |             | Reserved                                         |
|   0    |   wo   |   0x0   | fatal_fault | Write 1 to trigger one alert event of this kind. |

## MIO_PERIPH_INSEL_REGWEN
Register write enable for MIO peripheral input selects.
- Reset default: `0x1`
- Reset mask: `0x1`

### Instances

| Name                      | Offset   |
|:--------------------------|:---------|
| MIO_PERIPH_INSEL_REGWEN_0 | 0x4      |
| MIO_PERIPH_INSEL_REGWEN_1 | 0x8      |
| MIO_PERIPH_INSEL_REGWEN_2 | 0xc      |
| MIO_PERIPH_INSEL_REGWEN_3 | 0x10     |


### Fields

```wavejson
{"reg": [{"name": "EN", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"bits": 31}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name   | Description                                                                                                     |
|:------:|:------:|:-------:|:-------|:----------------------------------------------------------------------------------------------------------------|
|  31:1  |        |         |        | Reserved                                                                                                        |
|   0    |  rw0c  |   0x1   | EN     | Register write enable bit. If this is cleared to 0, the corresponding MIO_PERIPH_INSEL is not writable anymore. |

## MIO_PERIPH_INSEL
For each peripheral input, this selects the muxable pad input.
- Reset default: `0x0`
- Reset mask: `0xf`
- Register enable: [`MIO_PERIPH_INSEL_REGWEN`](#mio_periph_insel_regwen)

### Instances

| Name               | Offset   |
|:-------------------|:---------|
| MIO_PERIPH_INSEL_0 | 0x14     |
| MIO_PERIPH_INSEL_1 | 0x18     |
| MIO_PERIPH_INSEL_2 | 0x1c     |
| MIO_PERIPH_INSEL_3 | 0x20     |


### Fields

```wavejson
{"reg": [{"name": "IN", "bits": 4, "attr": ["rw"], "rotate": 0}, {"bits": 28}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name   | Description                                                                                                 |
|:------:|:------:|:-------:|:-------|:------------------------------------------------------------------------------------------------------------|
|  31:4  |        |         |        | Reserved                                                                                                    |
|  3:0   |   rw   |   0x0   | IN     | 0: tie constantly to zero, 1: tie constantly to 1, >=2: MIO pads (i.e., add 2 to the native MIO pad index). |

## MIO_OUTSEL_REGWEN
Register write enable for MIO output selects.
- Reset default: `0x1`
- Reset mask: `0x1`

### Instances

| Name                 | Offset   |
|:---------------------|:---------|
| MIO_OUTSEL_REGWEN_0  | 0x24     |
| MIO_OUTSEL_REGWEN_1  | 0x28     |
| MIO_OUTSEL_REGWEN_2  | 0x2c     |
| MIO_OUTSEL_REGWEN_3  | 0x30     |
| MIO_OUTSEL_REGWEN_4  | 0x34     |
| MIO_OUTSEL_REGWEN_5  | 0x38     |
| MIO_OUTSEL_REGWEN_6  | 0x3c     |
| MIO_OUTSEL_REGWEN_7  | 0x40     |
| MIO_OUTSEL_REGWEN_8  | 0x44     |
| MIO_OUTSEL_REGWEN_9  | 0x48     |
| MIO_OUTSEL_REGWEN_10 | 0x4c     |
| MIO_OUTSEL_REGWEN_11 | 0x50     |


### Fields

```wavejson
{"reg": [{"name": "EN", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"bits": 31}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name   | Description                                                                                               |
|:------:|:------:|:-------:|:-------|:----------------------------------------------------------------------------------------------------------|
|  31:1  |        |         |        | Reserved                                                                                                  |
|   0    |  rw0c  |   0x1   | EN     | Register write enable bit. If this is cleared to 0, the corresponding MIO_OUTSEL is not writable anymore. |

## MIO_OUTSEL
For each muxable pad, this selects the peripheral output.
- Reset default: `0x2`
- Reset mask: `0x7`
- Register enable: [`MIO_OUTSEL_REGWEN`](#mio_outsel_regwen)

### Instances

| Name          | Offset   |
|:--------------|:---------|
| MIO_OUTSEL_0  | 0x54     |
| MIO_OUTSEL_1  | 0x58     |
| MIO_OUTSEL_2  | 0x5c     |
| MIO_OUTSEL_3  | 0x60     |
| MIO_OUTSEL_4  | 0x64     |
| MIO_OUTSEL_5  | 0x68     |
| MIO_OUTSEL_6  | 0x6c     |
| MIO_OUTSEL_7  | 0x70     |
| MIO_OUTSEL_8  | 0x74     |
| MIO_OUTSEL_9  | 0x78     |
| MIO_OUTSEL_10 | 0x7c     |
| MIO_OUTSEL_11 | 0x80     |


### Fields

```wavejson
{"reg": [{"name": "OUT", "bits": 3, "attr": ["rw"], "rotate": 0}, {"bits": 29}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name   | Description                                                                                                                             |
|:------:|:------:|:-------:|:-------|:----------------------------------------------------------------------------------------------------------------------------------------|
|  31:3  |        |         |        | Reserved                                                                                                                                |
|  2:0   |   rw   |   0x2   | OUT    | 0: tie constantly to zero, 1: tie constantly to 1, 2: high-Z, >=3: peripheral outputs (i.e., add 3 to the native peripheral pad index). |

## MIO_PAD_ATTR_REGWEN
Register write enable for MIO PAD attributes.
- Reset default: `0x1`
- Reset mask: `0x1`

### Instances

| Name                   | Offset   |
|:-----------------------|:---------|
| MIO_PAD_ATTR_REGWEN_0  | 0x84     |
| MIO_PAD_ATTR_REGWEN_1  | 0x88     |
| MIO_PAD_ATTR_REGWEN_2  | 0x8c     |
| MIO_PAD_ATTR_REGWEN_3  | 0x90     |
| MIO_PAD_ATTR_REGWEN_4  | 0x94     |
| MIO_PAD_ATTR_REGWEN_5  | 0x98     |
| MIO_PAD_ATTR_REGWEN_6  | 0x9c     |
| MIO_PAD_ATTR_REGWEN_7  | 0xa0     |
| MIO_PAD_ATTR_REGWEN_8  | 0xa4     |
| MIO_PAD_ATTR_REGWEN_9  | 0xa8     |
| MIO_PAD_ATTR_REGWEN_10 | 0xac     |
| MIO_PAD_ATTR_REGWEN_11 | 0xb0     |


### Fields

```wavejson
{"reg": [{"name": "EN", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"bits": 31}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name   | Description                                                                                                                    |
|:------:|:------:|:-------:|:-------|:-------------------------------------------------------------------------------------------------------------------------------|
|  31:1  |        |         |        | Reserved                                                                                                                       |
|   0    |  rw0c  |   0x1   | EN     | Register write enable bit. If this is cleared to 0, the corresponding [`MIO_PAD_ATTR`](#mio_pad_attr) is not writable anymore. |

## MIO_PAD_ATTR
Muxed pad attributes.
This register has WARL behavior since not each pad type may support
all attributes.
The muxed pad that is used for TAP strap 0 has a different reset value, with `pull_en` set to 1.
- Reset default: `0x0`
- Reset mask: `0xf300ff`
- Register enable: [`MIO_PAD_ATTR_REGWEN`](#mio_pad_attr_regwen)

### Instances

| Name            | Offset   |
|:----------------|:---------|
| MIO_PAD_ATTR_0  | 0xb4     |
| MIO_PAD_ATTR_1  | 0xb8     |
| MIO_PAD_ATTR_2  | 0xbc     |
| MIO_PAD_ATTR_3  | 0xc0     |
| MIO_PAD_ATTR_4  | 0xc4     |
| MIO_PAD_ATTR_5  | 0xc8     |
| MIO_PAD_ATTR_6  | 0xcc     |
| MIO_PAD_ATTR_7  | 0xd0     |
| MIO_PAD_ATTR_8  | 0xd4     |
| MIO_PAD_ATTR_9  | 0xd8     |
| MIO_PAD_ATTR_10 | 0xdc     |
| MIO_PAD_ATTR_11 | 0xe0     |


### Fields

```wavejson
{"reg": [{"name": "invert", "bits": 1, "attr": ["rw"], "rotate": -90}, {"name": "virtual_od_en", "bits": 1, "attr": ["rw"], "rotate": -90}, {"name": "pull_en", "bits": 1, "attr": ["rw"], "rotate": -90}, {"name": "pull_select", "bits": 1, "attr": ["rw"], "rotate": -90}, {"name": "keeper_en", "bits": 1, "attr": ["rw"], "rotate": -90}, {"name": "schmitt_en", "bits": 1, "attr": ["rw"], "rotate": -90}, {"name": "od_en", "bits": 1, "attr": ["rw"], "rotate": -90}, {"name": "input_disable", "bits": 1, "attr": ["rw"], "rotate": -90}, {"bits": 8}, {"name": "slew_rate", "bits": 2, "attr": ["rw"], "rotate": -90}, {"bits": 2}, {"name": "drive_strength", "bits": 4, "attr": ["rw"], "rotate": -90}, {"bits": 8}], "config": {"lanes": 1, "fontsize": 10, "vspace": 160}}
```

|  Bits  |  Type  |  Reset  | Name                                            |
|:------:|:------:|:-------:|:------------------------------------------------|
| 31:24  |        |         | Reserved                                        |
| 23:20  |   rw   |   0x0   | [drive_strength](#mio_pad_attr--drive_strength) |
| 19:18  |        |         | Reserved                                        |
| 17:16  |   rw   |   0x0   | [slew_rate](#mio_pad_attr--slew_rate)           |
|  15:8  |        |         | Reserved                                        |
|   7    |   rw   |   0x0   | [input_disable](#mio_pad_attr--input_disable)   |
|   6    |   rw   |   0x0   | [od_en](#mio_pad_attr--od_en)                   |
|   5    |   rw   |   0x0   | [schmitt_en](#mio_pad_attr--schmitt_en)         |
|   4    |   rw   |   0x0   | [keeper_en](#mio_pad_attr--keeper_en)           |
|   3    |   rw   |   0x0   | [pull_select](#mio_pad_attr--pull_select)       |
|   2    |   rw   |   0x0   | [pull_en](#mio_pad_attr--pull_en)               |
|   1    |   rw   |   0x0   | [virtual_od_en](#mio_pad_attr--virtual_od_en)   |
|   0    |   rw   |   0x0   | [invert](#mio_pad_attr--invert)                 |

### MIO_PAD_ATTR . drive_strength
Drive strength (0x0: weakest, 0xf: strongest)

### MIO_PAD_ATTR . slew_rate
Slew rate (0x0: slowest, 0x3: fastest).

### MIO_PAD_ATTR . input_disable
Disable input drivers.
Setting this to 1 for pads that are not used as input can reduce their leakage current.

### MIO_PAD_ATTR . od_en
Enable open drain.

### MIO_PAD_ATTR . schmitt_en
Enable the schmitt trigger.

### MIO_PAD_ATTR . keeper_en
Enable keeper termination. This weakly drives the previous pad output value when output is disabled, similar to a verilog `trireg`.

### MIO_PAD_ATTR . pull_select
Pull select (0: pull-down, 1: pull-up).

| Value   | Name      | Description                    |
|:--------|:----------|:-------------------------------|
| 0x0     | pull_down | Select the pull-down resistor. |
| 0x1     | pull_up   | Select the pull-up resistor.   |


### MIO_PAD_ATTR . pull_en
Enable pull-up or pull-down resistor.

### MIO_PAD_ATTR . virtual_od_en
Enable virtual open drain.

### MIO_PAD_ATTR . invert
Invert input and output levels.

## DIO_PAD_ATTR_REGWEN
Register write enable for DIO PAD attributes.
- Reset default: `0x1`
- Reset mask: `0x1`

### Instances

| Name                   | Offset   |
|:-----------------------|:---------|
| DIO_PAD_ATTR_REGWEN_0  | 0xe4     |
| DIO_PAD_ATTR_REGWEN_1  | 0xe8     |
| DIO_PAD_ATTR_REGWEN_2  | 0xec     |
| DIO_PAD_ATTR_REGWEN_3  | 0xf0     |
| DIO_PAD_ATTR_REGWEN_4  | 0xf4     |
| DIO_PAD_ATTR_REGWEN_5  | 0xf8     |
| DIO_PAD_ATTR_REGWEN_6  | 0xfc     |
| DIO_PAD_ATTR_REGWEN_7  | 0x100    |
| DIO_PAD_ATTR_REGWEN_8  | 0x104    |
| DIO_PAD_ATTR_REGWEN_9  | 0x108    |
| DIO_PAD_ATTR_REGWEN_10 | 0x10c    |
| DIO_PAD_ATTR_REGWEN_11 | 0x110    |
| DIO_PAD_ATTR_REGWEN_12 | 0x114    |
| DIO_PAD_ATTR_REGWEN_13 | 0x118    |
| DIO_PAD_ATTR_REGWEN_14 | 0x11c    |
| DIO_PAD_ATTR_REGWEN_15 | 0x120    |
| DIO_PAD_ATTR_REGWEN_16 | 0x124    |
| DIO_PAD_ATTR_REGWEN_17 | 0x128    |
| DIO_PAD_ATTR_REGWEN_18 | 0x12c    |
| DIO_PAD_ATTR_REGWEN_19 | 0x130    |
| DIO_PAD_ATTR_REGWEN_20 | 0x134    |
| DIO_PAD_ATTR_REGWEN_21 | 0x138    |
| DIO_PAD_ATTR_REGWEN_22 | 0x13c    |
| DIO_PAD_ATTR_REGWEN_23 | 0x140    |
| DIO_PAD_ATTR_REGWEN_24 | 0x144    |
| DIO_PAD_ATTR_REGWEN_25 | 0x148    |
| DIO_PAD_ATTR_REGWEN_26 | 0x14c    |
| DIO_PAD_ATTR_REGWEN_27 | 0x150    |
| DIO_PAD_ATTR_REGWEN_28 | 0x154    |
| DIO_PAD_ATTR_REGWEN_29 | 0x158    |
| DIO_PAD_ATTR_REGWEN_30 | 0x15c    |
| DIO_PAD_ATTR_REGWEN_31 | 0x160    |
| DIO_PAD_ATTR_REGWEN_32 | 0x164    |
| DIO_PAD_ATTR_REGWEN_33 | 0x168    |
| DIO_PAD_ATTR_REGWEN_34 | 0x16c    |
| DIO_PAD_ATTR_REGWEN_35 | 0x170    |
| DIO_PAD_ATTR_REGWEN_36 | 0x174    |
| DIO_PAD_ATTR_REGWEN_37 | 0x178    |
| DIO_PAD_ATTR_REGWEN_38 | 0x17c    |
| DIO_PAD_ATTR_REGWEN_39 | 0x180    |
| DIO_PAD_ATTR_REGWEN_40 | 0x184    |
| DIO_PAD_ATTR_REGWEN_41 | 0x188    |
| DIO_PAD_ATTR_REGWEN_42 | 0x18c    |
| DIO_PAD_ATTR_REGWEN_43 | 0x190    |
| DIO_PAD_ATTR_REGWEN_44 | 0x194    |
| DIO_PAD_ATTR_REGWEN_45 | 0x198    |
| DIO_PAD_ATTR_REGWEN_46 | 0x19c    |
| DIO_PAD_ATTR_REGWEN_47 | 0x1a0    |
| DIO_PAD_ATTR_REGWEN_48 | 0x1a4    |
| DIO_PAD_ATTR_REGWEN_49 | 0x1a8    |
| DIO_PAD_ATTR_REGWEN_50 | 0x1ac    |
| DIO_PAD_ATTR_REGWEN_51 | 0x1b0    |
| DIO_PAD_ATTR_REGWEN_52 | 0x1b4    |
| DIO_PAD_ATTR_REGWEN_53 | 0x1b8    |
| DIO_PAD_ATTR_REGWEN_54 | 0x1bc    |
| DIO_PAD_ATTR_REGWEN_55 | 0x1c0    |
| DIO_PAD_ATTR_REGWEN_56 | 0x1c4    |
| DIO_PAD_ATTR_REGWEN_57 | 0x1c8    |


### Fields

```wavejson
{"reg": [{"name": "EN", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"bits": 31}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name   | Description                                                                                                                    |
|:------:|:------:|:-------:|:-------|:-------------------------------------------------------------------------------------------------------------------------------|
|  31:1  |        |         |        | Reserved                                                                                                                       |
|   0    |  rw0c  |   0x1   | EN     | Register write enable bit. If this is cleared to 0, the corresponding [`DIO_PAD_ATTR`](#dio_pad_attr) is not writable anymore. |

## DIO_PAD_ATTR
Dedicated pad attributes.
This register has WARL behavior since not each pad type may support
all attributes.
- Reset default: `0x0`
- Reset mask: `0xf300ff`
- Register enable: [`DIO_PAD_ATTR_REGWEN`](#dio_pad_attr_regwen)

### Instances

| Name            | Offset   |
|:----------------|:---------|
| DIO_PAD_ATTR_0  | 0x1cc    |
| DIO_PAD_ATTR_1  | 0x1d0    |
| DIO_PAD_ATTR_2  | 0x1d4    |
| DIO_PAD_ATTR_3  | 0x1d8    |
| DIO_PAD_ATTR_4  | 0x1dc    |
| DIO_PAD_ATTR_5  | 0x1e0    |
| DIO_PAD_ATTR_6  | 0x1e4    |
| DIO_PAD_ATTR_7  | 0x1e8    |
| DIO_PAD_ATTR_8  | 0x1ec    |
| DIO_PAD_ATTR_9  | 0x1f0    |
| DIO_PAD_ATTR_10 | 0x1f4    |
| DIO_PAD_ATTR_11 | 0x1f8    |
| DIO_PAD_ATTR_12 | 0x1fc    |
| DIO_PAD_ATTR_13 | 0x200    |
| DIO_PAD_ATTR_14 | 0x204    |
| DIO_PAD_ATTR_15 | 0x208    |
| DIO_PAD_ATTR_16 | 0x20c    |
| DIO_PAD_ATTR_17 | 0x210    |
| DIO_PAD_ATTR_18 | 0x214    |
| DIO_PAD_ATTR_19 | 0x218    |
| DIO_PAD_ATTR_20 | 0x21c    |
| DIO_PAD_ATTR_21 | 0x220    |
| DIO_PAD_ATTR_22 | 0x224    |
| DIO_PAD_ATTR_23 | 0x228    |
| DIO_PAD_ATTR_24 | 0x22c    |
| DIO_PAD_ATTR_25 | 0x230    |
| DIO_PAD_ATTR_26 | 0x234    |
| DIO_PAD_ATTR_27 | 0x238    |
| DIO_PAD_ATTR_28 | 0x23c    |
| DIO_PAD_ATTR_29 | 0x240    |
| DIO_PAD_ATTR_30 | 0x244    |
| DIO_PAD_ATTR_31 | 0x248    |
| DIO_PAD_ATTR_32 | 0x24c    |
| DIO_PAD_ATTR_33 | 0x250    |
| DIO_PAD_ATTR_34 | 0x254    |
| DIO_PAD_ATTR_35 | 0x258    |
| DIO_PAD_ATTR_36 | 0x25c    |
| DIO_PAD_ATTR_37 | 0x260    |
| DIO_PAD_ATTR_38 | 0x264    |
| DIO_PAD_ATTR_39 | 0x268    |
| DIO_PAD_ATTR_40 | 0x26c    |
| DIO_PAD_ATTR_41 | 0x270    |
| DIO_PAD_ATTR_42 | 0x274    |
| DIO_PAD_ATTR_43 | 0x278    |
| DIO_PAD_ATTR_44 | 0x27c    |
| DIO_PAD_ATTR_45 | 0x280    |
| DIO_PAD_ATTR_46 | 0x284    |
| DIO_PAD_ATTR_47 | 0x288    |
| DIO_PAD_ATTR_48 | 0x28c    |
| DIO_PAD_ATTR_49 | 0x290    |
| DIO_PAD_ATTR_50 | 0x294    |
| DIO_PAD_ATTR_51 | 0x298    |
| DIO_PAD_ATTR_52 | 0x29c    |
| DIO_PAD_ATTR_53 | 0x2a0    |
| DIO_PAD_ATTR_54 | 0x2a4    |
| DIO_PAD_ATTR_55 | 0x2a8    |
| DIO_PAD_ATTR_56 | 0x2ac    |
| DIO_PAD_ATTR_57 | 0x2b0    |


### Fields

```wavejson
{"reg": [{"name": "invert", "bits": 1, "attr": ["rw"], "rotate": -90}, {"name": "virtual_od_en", "bits": 1, "attr": ["rw"], "rotate": -90}, {"name": "pull_en", "bits": 1, "attr": ["rw"], "rotate": -90}, {"name": "pull_select", "bits": 1, "attr": ["rw"], "rotate": -90}, {"name": "keeper_en", "bits": 1, "attr": ["rw"], "rotate": -90}, {"name": "schmitt_en", "bits": 1, "attr": ["rw"], "rotate": -90}, {"name": "od_en", "bits": 1, "attr": ["rw"], "rotate": -90}, {"name": "input_disable", "bits": 1, "attr": ["rw"], "rotate": -90}, {"bits": 8}, {"name": "slew_rate", "bits": 2, "attr": ["rw"], "rotate": -90}, {"bits": 2}, {"name": "drive_strength", "bits": 4, "attr": ["rw"], "rotate": -90}, {"bits": 8}], "config": {"lanes": 1, "fontsize": 10, "vspace": 160}}
```

|  Bits  |  Type  |  Reset  | Name                                            |
|:------:|:------:|:-------:|:------------------------------------------------|
| 31:24  |        |         | Reserved                                        |
| 23:20  |   rw   |   0x0   | [drive_strength](#dio_pad_attr--drive_strength) |
| 19:18  |        |         | Reserved                                        |
| 17:16  |   rw   |   0x0   | [slew_rate](#dio_pad_attr--slew_rate)           |
|  15:8  |        |         | Reserved                                        |
|   7    |   rw   |   0x0   | [input_disable](#dio_pad_attr--input_disable)   |
|   6    |   rw   |   0x0   | [od_en](#dio_pad_attr--od_en)                   |
|   5    |   rw   |   0x0   | [schmitt_en](#dio_pad_attr--schmitt_en)         |
|   4    |   rw   |   0x0   | [keeper_en](#dio_pad_attr--keeper_en)           |
|   3    |   rw   |   0x0   | [pull_select](#dio_pad_attr--pull_select)       |
|   2    |   rw   |   0x0   | [pull_en](#dio_pad_attr--pull_en)               |
|   1    |   rw   |   0x0   | [virtual_od_en](#dio_pad_attr--virtual_od_en)   |
|   0    |   rw   |   0x0   | [invert](#dio_pad_attr--invert)                 |

### DIO_PAD_ATTR . drive_strength
Drive strength (0x0: weakest, 0xf: strongest)

### DIO_PAD_ATTR . slew_rate
Slew rate (0x0: slowest, 0x3: fastest).

### DIO_PAD_ATTR . input_disable
Disable input drivers.
Setting this to 1 for pads that are not used as input can reduce their leakage current.

### DIO_PAD_ATTR . od_en
Enable open drain.

### DIO_PAD_ATTR . schmitt_en
Enable the schmitt trigger.

### DIO_PAD_ATTR . keeper_en
Enable keeper termination. This weakly drives the previous pad output value when output is disabled, similar to a verilog `trireg`.

### DIO_PAD_ATTR . pull_select
Pull select (0: pull-down, 1: pull-up).

| Value   | Name      | Description                    |
|:--------|:----------|:-------------------------------|
| 0x0     | pull_down | Select the pull-down resistor. |
| 0x1     | pull_up   | Select the pull-up resistor.   |


### DIO_PAD_ATTR . pull_en
Enable pull-up or pull-down resistor.

### DIO_PAD_ATTR . virtual_od_en
Enable virtual open drain.

### DIO_PAD_ATTR . invert
Invert input and output levels.

## MIO_PAD_SLEEP_STATUS
Register indicating whether the corresponding pad is in sleep mode.
- Offset: `0x2b4`
- Reset default: `0x0`
- Reset mask: `0xfff`

### Fields

```wavejson
{"reg": [{"name": "EN_0", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_1", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_2", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_3", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_4", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_5", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_6", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_7", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_8", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_9", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_10", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_11", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"bits": 20}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name   | Description                                                                                                                                                                                                                                      |
|:------:|:------:|:-------:|:-------|:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 31:12  |        |         |        | Reserved                                                                                                                                                                                                                                         |
|   11   |  rw0c  |   0x0   | EN_11  | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`MIO_PAD_SLEEP_EN`](#mio_pad_sleep_en)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   10   |  rw0c  |   0x0   | EN_10  | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`MIO_PAD_SLEEP_EN`](#mio_pad_sleep_en)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   9    |  rw0c  |   0x0   | EN_9   | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`MIO_PAD_SLEEP_EN`](#mio_pad_sleep_en)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   8    |  rw0c  |   0x0   | EN_8   | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`MIO_PAD_SLEEP_EN`](#mio_pad_sleep_en)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   7    |  rw0c  |   0x0   | EN_7   | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`MIO_PAD_SLEEP_EN`](#mio_pad_sleep_en)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   6    |  rw0c  |   0x0   | EN_6   | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`MIO_PAD_SLEEP_EN`](#mio_pad_sleep_en)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   5    |  rw0c  |   0x0   | EN_5   | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`MIO_PAD_SLEEP_EN`](#mio_pad_sleep_en)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   4    |  rw0c  |   0x0   | EN_4   | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`MIO_PAD_SLEEP_EN`](#mio_pad_sleep_en)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   3    |  rw0c  |   0x0   | EN_3   | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`MIO_PAD_SLEEP_EN`](#mio_pad_sleep_en)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   2    |  rw0c  |   0x0   | EN_2   | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`MIO_PAD_SLEEP_EN`](#mio_pad_sleep_en)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   1    |  rw0c  |   0x0   | EN_1   | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`MIO_PAD_SLEEP_EN`](#mio_pad_sleep_en)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   0    |  rw0c  |   0x0   | EN_0   | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`MIO_PAD_SLEEP_EN`](#mio_pad_sleep_en)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |

## MIO_PAD_SLEEP_REGWEN
Register write enable for MIO sleep value configuration.
- Reset default: `0x1`
- Reset mask: `0x1`

### Instances

| Name                    | Offset   |
|:------------------------|:---------|
| MIO_PAD_SLEEP_REGWEN_0  | 0x2b8    |
| MIO_PAD_SLEEP_REGWEN_1  | 0x2bc    |
| MIO_PAD_SLEEP_REGWEN_2  | 0x2c0    |
| MIO_PAD_SLEEP_REGWEN_3  | 0x2c4    |
| MIO_PAD_SLEEP_REGWEN_4  | 0x2c8    |
| MIO_PAD_SLEEP_REGWEN_5  | 0x2cc    |
| MIO_PAD_SLEEP_REGWEN_6  | 0x2d0    |
| MIO_PAD_SLEEP_REGWEN_7  | 0x2d4    |
| MIO_PAD_SLEEP_REGWEN_8  | 0x2d8    |
| MIO_PAD_SLEEP_REGWEN_9  | 0x2dc    |
| MIO_PAD_SLEEP_REGWEN_10 | 0x2e0    |
| MIO_PAD_SLEEP_REGWEN_11 | 0x2e4    |


### Fields

```wavejson
{"reg": [{"name": "EN", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"bits": 31}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name   | Description                                                                                                                                |
|:------:|:------:|:-------:|:-------|:-------------------------------------------------------------------------------------------------------------------------------------------|
|  31:1  |        |         |        | Reserved                                                                                                                                   |
|   0    |  rw0c  |   0x1   | EN     | Register write enable bit. If this is cleared to 0, the corresponding [`MIO_PAD_SLEEP_MODE`](#mio_pad_sleep_mode) is not writable anymore. |

## MIO_PAD_SLEEP_EN
Enables the sleep mode of the corresponding muxed pad.
- Reset default: `0x0`
- Reset mask: `0x1`
- Register enable: [`MIO_PAD_SLEEP_REGWEN`](#mio_pad_sleep_regwen)

### Instances

| Name                | Offset   |
|:--------------------|:---------|
| MIO_PAD_SLEEP_EN_0  | 0x2e8    |
| MIO_PAD_SLEEP_EN_1  | 0x2ec    |
| MIO_PAD_SLEEP_EN_2  | 0x2f0    |
| MIO_PAD_SLEEP_EN_3  | 0x2f4    |
| MIO_PAD_SLEEP_EN_4  | 0x2f8    |
| MIO_PAD_SLEEP_EN_5  | 0x2fc    |
| MIO_PAD_SLEEP_EN_6  | 0x300    |
| MIO_PAD_SLEEP_EN_7  | 0x304    |
| MIO_PAD_SLEEP_EN_8  | 0x308    |
| MIO_PAD_SLEEP_EN_9  | 0x30c    |
| MIO_PAD_SLEEP_EN_10 | 0x310    |
| MIO_PAD_SLEEP_EN_11 | 0x314    |


### Fields

```wavejson
{"reg": [{"name": "EN", "bits": 1, "attr": ["rw"], "rotate": -90}, {"bits": 31}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name                        |
|:------:|:------:|:-------:|:----------------------------|
|  31:1  |        |         | Reserved                    |
|   0    |   rw   |   0x0   | [EN](#mio_pad_sleep_en--en) |

### MIO_PAD_SLEEP_EN . EN
Deep sleep mode enable.
If this bit is set to 1 the corresponding pad will enable the sleep behavior
specified in [`MIO_PAD_SLEEP_MODE`](#mio_pad_sleep_mode) upon deep sleep entry, and the corresponding bit
in [`MIO_PAD_SLEEP_STATUS`](#mio_pad_sleep_status) will be set to 1.
The pad remains in deep sleep mode until the corresponding bit in
[`MIO_PAD_SLEEP_STATUS`](#mio_pad_sleep_status) is cleared by SW.
Note that if an always on peripheral is connected to a specific MIO pad,
the corresponding [`MIO_PAD_SLEEP_EN`](#mio_pad_sleep_en) bit should be set to 0.

## MIO_PAD_SLEEP_MODE
Defines sleep behavior of the corresponding muxed pad.
- Reset default: `0x2`
- Reset mask: `0x3`
- Register enable: [`MIO_PAD_SLEEP_REGWEN`](#mio_pad_sleep_regwen)

### Instances

| Name                  | Offset   |
|:----------------------|:---------|
| MIO_PAD_SLEEP_MODE_0  | 0x318    |
| MIO_PAD_SLEEP_MODE_1  | 0x31c    |
| MIO_PAD_SLEEP_MODE_2  | 0x320    |
| MIO_PAD_SLEEP_MODE_3  | 0x324    |
| MIO_PAD_SLEEP_MODE_4  | 0x328    |
| MIO_PAD_SLEEP_MODE_5  | 0x32c    |
| MIO_PAD_SLEEP_MODE_6  | 0x330    |
| MIO_PAD_SLEEP_MODE_7  | 0x334    |
| MIO_PAD_SLEEP_MODE_8  | 0x338    |
| MIO_PAD_SLEEP_MODE_9  | 0x33c    |
| MIO_PAD_SLEEP_MODE_10 | 0x340    |
| MIO_PAD_SLEEP_MODE_11 | 0x344    |


### Fields

```wavejson
{"reg": [{"name": "OUT", "bits": 2, "attr": ["rw"], "rotate": -90}, {"bits": 30}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name                            |
|:------:|:------:|:-------:|:--------------------------------|
|  31:2  |        |         | Reserved                        |
|  1:0   |   rw   |   0x2   | [OUT](#mio_pad_sleep_mode--out) |

### MIO_PAD_SLEEP_MODE . OUT
Value to drive in deep sleep.

| Value   | Name     | Description                                                                                                                                                                    |
|:--------|:---------|:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 0x0     | Tie-Low  | The pad is driven actively to zero in deep sleep mode.                                                                                                                         |
| 0x1     | Tie-High | The pad is driven actively to one in deep sleep mode.                                                                                                                          |
| 0x2     | High-Z   | The pad is left undriven in deep sleep mode. Note that the actual driving behavior during deep sleep will then depend on the pull-up/-down configuration of in !!MIO_PAD_ATTR. |
| 0x3     | Keep     | Keep last driven value (including high-Z).                                                                                                                                     |


## DIO_PAD_SLEEP_STATUS_0
Register indicating whether the corresponding pad is in sleep mode.
- Offset: `0x348`
- Reset default: `0x0`
- Reset mask: `0xffffffff`

### Fields

```wavejson
{"reg": [{"name": "EN_0", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_1", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_2", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_3", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_4", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_5", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_6", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_7", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_8", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_9", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_10", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_11", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_12", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_13", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_14", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_15", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_16", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_17", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_18", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_19", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_20", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_21", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_22", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_23", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_24", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_25", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_26", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_27", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_28", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_29", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_30", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_31", "bits": 1, "attr": ["rw0c"], "rotate": -90}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name   | Description                                                                                                                                                                                                                                          |
|:------:|:------:|:-------:|:-------|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|   31   |  rw0c  |   0x0   | EN_31  | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   30   |  rw0c  |   0x0   | EN_30  | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   29   |  rw0c  |   0x0   | EN_29  | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   28   |  rw0c  |   0x0   | EN_28  | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   27   |  rw0c  |   0x0   | EN_27  | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   26   |  rw0c  |   0x0   | EN_26  | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   25   |  rw0c  |   0x0   | EN_25  | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   24   |  rw0c  |   0x0   | EN_24  | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   23   |  rw0c  |   0x0   | EN_23  | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   22   |  rw0c  |   0x0   | EN_22  | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   21   |  rw0c  |   0x0   | EN_21  | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   20   |  rw0c  |   0x0   | EN_20  | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   19   |  rw0c  |   0x0   | EN_19  | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   18   |  rw0c  |   0x0   | EN_18  | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   17   |  rw0c  |   0x0   | EN_17  | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   16   |  rw0c  |   0x0   | EN_16  | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   15   |  rw0c  |   0x0   | EN_15  | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   14   |  rw0c  |   0x0   | EN_14  | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   13   |  rw0c  |   0x0   | EN_13  | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   12   |  rw0c  |   0x0   | EN_12  | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   11   |  rw0c  |   0x0   | EN_11  | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   10   |  rw0c  |   0x0   | EN_10  | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   9    |  rw0c  |   0x0   | EN_9   | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   8    |  rw0c  |   0x0   | EN_8   | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   7    |  rw0c  |   0x0   | EN_7   | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   6    |  rw0c  |   0x0   | EN_6   | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   5    |  rw0c  |   0x0   | EN_5   | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   4    |  rw0c  |   0x0   | EN_4   | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   3    |  rw0c  |   0x0   | EN_3   | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   2    |  rw0c  |   0x0   | EN_2   | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   1    |  rw0c  |   0x0   | EN_1   | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |
|   0    |  rw0c  |   0x0   | EN_0   | This register is set to 1 if the deep sleep mode of the corresponding pad has been enabled ([`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode)) upon deep sleep entry. The sleep mode of the corresponding pad will remain active until SW clears this bit. |

## DIO_PAD_SLEEP_STATUS_1
Register indicating whether the corresponding pad is in sleep mode.
- Offset: `0x34c`
- Reset default: `0x0`
- Reset mask: `0x3ffffff`

### Fields

```wavejson
{"reg": [{"name": "EN_32", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_33", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_34", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_35", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_36", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_37", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_38", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_39", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_40", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_41", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_42", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_43", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_44", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_45", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_46", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_47", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_48", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_49", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_50", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_51", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_52", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_53", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_54", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_55", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_56", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "EN_57", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"bits": 6}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name   | Description   |
|:------:|:------:|:-------:|:-------|:--------------|
| 31:26  |        |         |        | Reserved      |
|   25   |  rw0c  |   0x0   | EN_57  | For DIO_PAD1  |
|   24   |  rw0c  |   0x0   | EN_56  | For DIO_PAD1  |
|   23   |  rw0c  |   0x0   | EN_55  | For DIO_PAD1  |
|   22   |  rw0c  |   0x0   | EN_54  | For DIO_PAD1  |
|   21   |  rw0c  |   0x0   | EN_53  | For DIO_PAD1  |
|   20   |  rw0c  |   0x0   | EN_52  | For DIO_PAD1  |
|   19   |  rw0c  |   0x0   | EN_51  | For DIO_PAD1  |
|   18   |  rw0c  |   0x0   | EN_50  | For DIO_PAD1  |
|   17   |  rw0c  |   0x0   | EN_49  | For DIO_PAD1  |
|   16   |  rw0c  |   0x0   | EN_48  | For DIO_PAD1  |
|   15   |  rw0c  |   0x0   | EN_47  | For DIO_PAD1  |
|   14   |  rw0c  |   0x0   | EN_46  | For DIO_PAD1  |
|   13   |  rw0c  |   0x0   | EN_45  | For DIO_PAD1  |
|   12   |  rw0c  |   0x0   | EN_44  | For DIO_PAD1  |
|   11   |  rw0c  |   0x0   | EN_43  | For DIO_PAD1  |
|   10   |  rw0c  |   0x0   | EN_42  | For DIO_PAD1  |
|   9    |  rw0c  |   0x0   | EN_41  | For DIO_PAD1  |
|   8    |  rw0c  |   0x0   | EN_40  | For DIO_PAD1  |
|   7    |  rw0c  |   0x0   | EN_39  | For DIO_PAD1  |
|   6    |  rw0c  |   0x0   | EN_38  | For DIO_PAD1  |
|   5    |  rw0c  |   0x0   | EN_37  | For DIO_PAD1  |
|   4    |  rw0c  |   0x0   | EN_36  | For DIO_PAD1  |
|   3    |  rw0c  |   0x0   | EN_35  | For DIO_PAD1  |
|   2    |  rw0c  |   0x0   | EN_34  | For DIO_PAD1  |
|   1    |  rw0c  |   0x0   | EN_33  | For DIO_PAD1  |
|   0    |  rw0c  |   0x0   | EN_32  | For DIO_PAD1  |

## DIO_PAD_SLEEP_REGWEN
Register write enable for DIO sleep value configuration.
- Reset default: `0x1`
- Reset mask: `0x1`

### Instances

| Name                    | Offset   |
|:------------------------|:---------|
| DIO_PAD_SLEEP_REGWEN_0  | 0x350    |
| DIO_PAD_SLEEP_REGWEN_1  | 0x354    |
| DIO_PAD_SLEEP_REGWEN_2  | 0x358    |
| DIO_PAD_SLEEP_REGWEN_3  | 0x35c    |
| DIO_PAD_SLEEP_REGWEN_4  | 0x360    |
| DIO_PAD_SLEEP_REGWEN_5  | 0x364    |
| DIO_PAD_SLEEP_REGWEN_6  | 0x368    |
| DIO_PAD_SLEEP_REGWEN_7  | 0x36c    |
| DIO_PAD_SLEEP_REGWEN_8  | 0x370    |
| DIO_PAD_SLEEP_REGWEN_9  | 0x374    |
| DIO_PAD_SLEEP_REGWEN_10 | 0x378    |
| DIO_PAD_SLEEP_REGWEN_11 | 0x37c    |
| DIO_PAD_SLEEP_REGWEN_12 | 0x380    |
| DIO_PAD_SLEEP_REGWEN_13 | 0x384    |
| DIO_PAD_SLEEP_REGWEN_14 | 0x388    |
| DIO_PAD_SLEEP_REGWEN_15 | 0x38c    |
| DIO_PAD_SLEEP_REGWEN_16 | 0x390    |
| DIO_PAD_SLEEP_REGWEN_17 | 0x394    |
| DIO_PAD_SLEEP_REGWEN_18 | 0x398    |
| DIO_PAD_SLEEP_REGWEN_19 | 0x39c    |
| DIO_PAD_SLEEP_REGWEN_20 | 0x3a0    |
| DIO_PAD_SLEEP_REGWEN_21 | 0x3a4    |
| DIO_PAD_SLEEP_REGWEN_22 | 0x3a8    |
| DIO_PAD_SLEEP_REGWEN_23 | 0x3ac    |
| DIO_PAD_SLEEP_REGWEN_24 | 0x3b0    |
| DIO_PAD_SLEEP_REGWEN_25 | 0x3b4    |
| DIO_PAD_SLEEP_REGWEN_26 | 0x3b8    |
| DIO_PAD_SLEEP_REGWEN_27 | 0x3bc    |
| DIO_PAD_SLEEP_REGWEN_28 | 0x3c0    |
| DIO_PAD_SLEEP_REGWEN_29 | 0x3c4    |
| DIO_PAD_SLEEP_REGWEN_30 | 0x3c8    |
| DIO_PAD_SLEEP_REGWEN_31 | 0x3cc    |
| DIO_PAD_SLEEP_REGWEN_32 | 0x3d0    |
| DIO_PAD_SLEEP_REGWEN_33 | 0x3d4    |
| DIO_PAD_SLEEP_REGWEN_34 | 0x3d8    |
| DIO_PAD_SLEEP_REGWEN_35 | 0x3dc    |
| DIO_PAD_SLEEP_REGWEN_36 | 0x3e0    |
| DIO_PAD_SLEEP_REGWEN_37 | 0x3e4    |
| DIO_PAD_SLEEP_REGWEN_38 | 0x3e8    |
| DIO_PAD_SLEEP_REGWEN_39 | 0x3ec    |
| DIO_PAD_SLEEP_REGWEN_40 | 0x3f0    |
| DIO_PAD_SLEEP_REGWEN_41 | 0x3f4    |
| DIO_PAD_SLEEP_REGWEN_42 | 0x3f8    |
| DIO_PAD_SLEEP_REGWEN_43 | 0x3fc    |
| DIO_PAD_SLEEP_REGWEN_44 | 0x400    |
| DIO_PAD_SLEEP_REGWEN_45 | 0x404    |
| DIO_PAD_SLEEP_REGWEN_46 | 0x408    |
| DIO_PAD_SLEEP_REGWEN_47 | 0x40c    |
| DIO_PAD_SLEEP_REGWEN_48 | 0x410    |
| DIO_PAD_SLEEP_REGWEN_49 | 0x414    |
| DIO_PAD_SLEEP_REGWEN_50 | 0x418    |
| DIO_PAD_SLEEP_REGWEN_51 | 0x41c    |
| DIO_PAD_SLEEP_REGWEN_52 | 0x420    |
| DIO_PAD_SLEEP_REGWEN_53 | 0x424    |
| DIO_PAD_SLEEP_REGWEN_54 | 0x428    |
| DIO_PAD_SLEEP_REGWEN_55 | 0x42c    |
| DIO_PAD_SLEEP_REGWEN_56 | 0x430    |
| DIO_PAD_SLEEP_REGWEN_57 | 0x434    |


### Fields

```wavejson
{"reg": [{"name": "EN", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"bits": 31}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name   | Description                                                                                                                                |
|:------:|:------:|:-------:|:-------|:-------------------------------------------------------------------------------------------------------------------------------------------|
|  31:1  |        |         |        | Reserved                                                                                                                                   |
|   0    |  rw0c  |   0x1   | EN     | Register write enable bit. If this is cleared to 0, the corresponding [`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode) is not writable anymore. |

## DIO_PAD_SLEEP_EN
Enables the sleep mode of the corresponding dedicated pad.
- Reset default: `0x0`
- Reset mask: `0x1`
- Register enable: [`DIO_PAD_SLEEP_REGWEN`](#dio_pad_sleep_regwen)

### Instances

| Name                | Offset   |
|:--------------------|:---------|
| DIO_PAD_SLEEP_EN_0  | 0x438    |
| DIO_PAD_SLEEP_EN_1  | 0x43c    |
| DIO_PAD_SLEEP_EN_2  | 0x440    |
| DIO_PAD_SLEEP_EN_3  | 0x444    |
| DIO_PAD_SLEEP_EN_4  | 0x448    |
| DIO_PAD_SLEEP_EN_5  | 0x44c    |
| DIO_PAD_SLEEP_EN_6  | 0x450    |
| DIO_PAD_SLEEP_EN_7  | 0x454    |
| DIO_PAD_SLEEP_EN_8  | 0x458    |
| DIO_PAD_SLEEP_EN_9  | 0x45c    |
| DIO_PAD_SLEEP_EN_10 | 0x460    |
| DIO_PAD_SLEEP_EN_11 | 0x464    |
| DIO_PAD_SLEEP_EN_12 | 0x468    |
| DIO_PAD_SLEEP_EN_13 | 0x46c    |
| DIO_PAD_SLEEP_EN_14 | 0x470    |
| DIO_PAD_SLEEP_EN_15 | 0x474    |
| DIO_PAD_SLEEP_EN_16 | 0x478    |
| DIO_PAD_SLEEP_EN_17 | 0x47c    |
| DIO_PAD_SLEEP_EN_18 | 0x480    |
| DIO_PAD_SLEEP_EN_19 | 0x484    |
| DIO_PAD_SLEEP_EN_20 | 0x488    |
| DIO_PAD_SLEEP_EN_21 | 0x48c    |
| DIO_PAD_SLEEP_EN_22 | 0x490    |
| DIO_PAD_SLEEP_EN_23 | 0x494    |
| DIO_PAD_SLEEP_EN_24 | 0x498    |
| DIO_PAD_SLEEP_EN_25 | 0x49c    |
| DIO_PAD_SLEEP_EN_26 | 0x4a0    |
| DIO_PAD_SLEEP_EN_27 | 0x4a4    |
| DIO_PAD_SLEEP_EN_28 | 0x4a8    |
| DIO_PAD_SLEEP_EN_29 | 0x4ac    |
| DIO_PAD_SLEEP_EN_30 | 0x4b0    |
| DIO_PAD_SLEEP_EN_31 | 0x4b4    |
| DIO_PAD_SLEEP_EN_32 | 0x4b8    |
| DIO_PAD_SLEEP_EN_33 | 0x4bc    |
| DIO_PAD_SLEEP_EN_34 | 0x4c0    |
| DIO_PAD_SLEEP_EN_35 | 0x4c4    |
| DIO_PAD_SLEEP_EN_36 | 0x4c8    |
| DIO_PAD_SLEEP_EN_37 | 0x4cc    |
| DIO_PAD_SLEEP_EN_38 | 0x4d0    |
| DIO_PAD_SLEEP_EN_39 | 0x4d4    |
| DIO_PAD_SLEEP_EN_40 | 0x4d8    |
| DIO_PAD_SLEEP_EN_41 | 0x4dc    |
| DIO_PAD_SLEEP_EN_42 | 0x4e0    |
| DIO_PAD_SLEEP_EN_43 | 0x4e4    |
| DIO_PAD_SLEEP_EN_44 | 0x4e8    |
| DIO_PAD_SLEEP_EN_45 | 0x4ec    |
| DIO_PAD_SLEEP_EN_46 | 0x4f0    |
| DIO_PAD_SLEEP_EN_47 | 0x4f4    |
| DIO_PAD_SLEEP_EN_48 | 0x4f8    |
| DIO_PAD_SLEEP_EN_49 | 0x4fc    |
| DIO_PAD_SLEEP_EN_50 | 0x500    |
| DIO_PAD_SLEEP_EN_51 | 0x504    |
| DIO_PAD_SLEEP_EN_52 | 0x508    |
| DIO_PAD_SLEEP_EN_53 | 0x50c    |
| DIO_PAD_SLEEP_EN_54 | 0x510    |
| DIO_PAD_SLEEP_EN_55 | 0x514    |
| DIO_PAD_SLEEP_EN_56 | 0x518    |
| DIO_PAD_SLEEP_EN_57 | 0x51c    |


### Fields

```wavejson
{"reg": [{"name": "EN", "bits": 1, "attr": ["rw"], "rotate": -90}, {"bits": 31}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name                        |
|:------:|:------:|:-------:|:----------------------------|
|  31:1  |        |         | Reserved                    |
|   0    |   rw   |   0x0   | [EN](#dio_pad_sleep_en--en) |

### DIO_PAD_SLEEP_EN . EN
Deep sleep mode enable.
If this bit is set to 1 the corresponding pad will enable the sleep behavior
specified in [`DIO_PAD_SLEEP_MODE`](#dio_pad_sleep_mode) upon deep sleep entry, and the corresponding bit
in [`DIO_PAD_SLEEP_STATUS`](#dio_pad_sleep_status) will be set to 1.
The pad remains in deep sleep mode until the corresponding bit in
[`DIO_PAD_SLEEP_STATUS`](#dio_pad_sleep_status) is cleared by SW.
Note that if an always on peripheral is connected to a specific DIO pad,
the corresponding [`DIO_PAD_SLEEP_EN`](#dio_pad_sleep_en) bit should be set to 0.

## DIO_PAD_SLEEP_MODE
Defines sleep behavior of the corresponding dedicated pad.
- Reset default: `0x2`
- Reset mask: `0x3`
- Register enable: [`DIO_PAD_SLEEP_REGWEN`](#dio_pad_sleep_regwen)

### Instances

| Name                  | Offset   |
|:----------------------|:---------|
| DIO_PAD_SLEEP_MODE_0  | 0x520    |
| DIO_PAD_SLEEP_MODE_1  | 0x524    |
| DIO_PAD_SLEEP_MODE_2  | 0x528    |
| DIO_PAD_SLEEP_MODE_3  | 0x52c    |
| DIO_PAD_SLEEP_MODE_4  | 0x530    |
| DIO_PAD_SLEEP_MODE_5  | 0x534    |
| DIO_PAD_SLEEP_MODE_6  | 0x538    |
| DIO_PAD_SLEEP_MODE_7  | 0x53c    |
| DIO_PAD_SLEEP_MODE_8  | 0x540    |
| DIO_PAD_SLEEP_MODE_9  | 0x544    |
| DIO_PAD_SLEEP_MODE_10 | 0x548    |
| DIO_PAD_SLEEP_MODE_11 | 0x54c    |
| DIO_PAD_SLEEP_MODE_12 | 0x550    |
| DIO_PAD_SLEEP_MODE_13 | 0x554    |
| DIO_PAD_SLEEP_MODE_14 | 0x558    |
| DIO_PAD_SLEEP_MODE_15 | 0x55c    |
| DIO_PAD_SLEEP_MODE_16 | 0x560    |
| DIO_PAD_SLEEP_MODE_17 | 0x564    |
| DIO_PAD_SLEEP_MODE_18 | 0x568    |
| DIO_PAD_SLEEP_MODE_19 | 0x56c    |
| DIO_PAD_SLEEP_MODE_20 | 0x570    |
| DIO_PAD_SLEEP_MODE_21 | 0x574    |
| DIO_PAD_SLEEP_MODE_22 | 0x578    |
| DIO_PAD_SLEEP_MODE_23 | 0x57c    |
| DIO_PAD_SLEEP_MODE_24 | 0x580    |
| DIO_PAD_SLEEP_MODE_25 | 0x584    |
| DIO_PAD_SLEEP_MODE_26 | 0x588    |
| DIO_PAD_SLEEP_MODE_27 | 0x58c    |
| DIO_PAD_SLEEP_MODE_28 | 0x590    |
| DIO_PAD_SLEEP_MODE_29 | 0x594    |
| DIO_PAD_SLEEP_MODE_30 | 0x598    |
| DIO_PAD_SLEEP_MODE_31 | 0x59c    |
| DIO_PAD_SLEEP_MODE_32 | 0x5a0    |
| DIO_PAD_SLEEP_MODE_33 | 0x5a4    |
| DIO_PAD_SLEEP_MODE_34 | 0x5a8    |
| DIO_PAD_SLEEP_MODE_35 | 0x5ac    |
| DIO_PAD_SLEEP_MODE_36 | 0x5b0    |
| DIO_PAD_SLEEP_MODE_37 | 0x5b4    |
| DIO_PAD_SLEEP_MODE_38 | 0x5b8    |
| DIO_PAD_SLEEP_MODE_39 | 0x5bc    |
| DIO_PAD_SLEEP_MODE_40 | 0x5c0    |
| DIO_PAD_SLEEP_MODE_41 | 0x5c4    |
| DIO_PAD_SLEEP_MODE_42 | 0x5c8    |
| DIO_PAD_SLEEP_MODE_43 | 0x5cc    |
| DIO_PAD_SLEEP_MODE_44 | 0x5d0    |
| DIO_PAD_SLEEP_MODE_45 | 0x5d4    |
| DIO_PAD_SLEEP_MODE_46 | 0x5d8    |
| DIO_PAD_SLEEP_MODE_47 | 0x5dc    |
| DIO_PAD_SLEEP_MODE_48 | 0x5e0    |
| DIO_PAD_SLEEP_MODE_49 | 0x5e4    |
| DIO_PAD_SLEEP_MODE_50 | 0x5e8    |
| DIO_PAD_SLEEP_MODE_51 | 0x5ec    |
| DIO_PAD_SLEEP_MODE_52 | 0x5f0    |
| DIO_PAD_SLEEP_MODE_53 | 0x5f4    |
| DIO_PAD_SLEEP_MODE_54 | 0x5f8    |
| DIO_PAD_SLEEP_MODE_55 | 0x5fc    |
| DIO_PAD_SLEEP_MODE_56 | 0x600    |
| DIO_PAD_SLEEP_MODE_57 | 0x604    |


### Fields

```wavejson
{"reg": [{"name": "OUT", "bits": 2, "attr": ["rw"], "rotate": -90}, {"bits": 30}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name                            |
|:------:|:------:|:-------:|:--------------------------------|
|  31:2  |        |         | Reserved                        |
|  1:0   |   rw   |   0x2   | [OUT](#dio_pad_sleep_mode--out) |

### DIO_PAD_SLEEP_MODE . OUT
Value to drive in deep sleep.

| Value   | Name     | Description                                                                                                                                                                    |
|:--------|:---------|:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 0x0     | Tie-Low  | The pad is driven actively to zero in deep sleep mode.                                                                                                                         |
| 0x1     | Tie-High | The pad is driven actively to one in deep sleep mode.                                                                                                                          |
| 0x2     | High-Z   | The pad is left undriven in deep sleep mode. Note that the actual driving behavior during deep sleep will then depend on the pull-up/-down configuration of in !!DIO_PAD_ATTR. |
| 0x3     | Keep     | Keep last driven value (including high-Z).                                                                                                                                     |


## WKUP_DETECTOR_REGWEN
Register write enable for wakeup detectors.
- Reset default: `0x1`
- Reset mask: `0x1`

### Instances

| Name                   | Offset   |
|:-----------------------|:---------|
| WKUP_DETECTOR_REGWEN_0 | 0x608    |
| WKUP_DETECTOR_REGWEN_1 | 0x60c    |
| WKUP_DETECTOR_REGWEN_2 | 0x610    |
| WKUP_DETECTOR_REGWEN_3 | 0x614    |
| WKUP_DETECTOR_REGWEN_4 | 0x618    |
| WKUP_DETECTOR_REGWEN_5 | 0x61c    |
| WKUP_DETECTOR_REGWEN_6 | 0x620    |
| WKUP_DETECTOR_REGWEN_7 | 0x624    |


### Fields

```wavejson
{"reg": [{"name": "EN", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"bits": 31}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name   | Description                                                                                                                |
|:------:|:------:|:-------:|:-------|:---------------------------------------------------------------------------------------------------------------------------|
|  31:1  |        |         |        | Reserved                                                                                                                   |
|   0    |  rw0c  |   0x1   | EN     | Register write enable bit. If this is cleared to 0, the corresponding WKUP_DETECTOR configuration is not writable anymore. |

## WKUP_DETECTOR_EN
Enables for the wakeup detectors.
Note that these registers are synced to the always-on clock.
The first write access always completes immediately.
However, read/write accesses following a write will block until that write has completed.
- Reset default: `0x0`
- Reset mask: `0x1`
- Register enable: [`WKUP_DETECTOR_REGWEN`](#wkup_detector_regwen)

### Instances

| Name               | Offset   |
|:-------------------|:---------|
| WKUP_DETECTOR_EN_0 | 0x628    |
| WKUP_DETECTOR_EN_1 | 0x62c    |
| WKUP_DETECTOR_EN_2 | 0x630    |
| WKUP_DETECTOR_EN_3 | 0x634    |
| WKUP_DETECTOR_EN_4 | 0x638    |
| WKUP_DETECTOR_EN_5 | 0x63c    |
| WKUP_DETECTOR_EN_6 | 0x640    |
| WKUP_DETECTOR_EN_7 | 0x644    |


### Fields

```wavejson
{"reg": [{"name": "EN", "bits": 1, "attr": ["rw"], "rotate": -90}, {"bits": 31}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name   | Description                                                                                                                                                                                                                           |
|:------:|:------:|:-------:|:-------|:--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|  31:1  |        |         |        | Reserved                                                                                                                                                                                                                              |
|   0    |   rw   |   0x0   | EN     | Setting this bit activates the corresponding wakeup detector. The behavior is as specified in [`WKUP_DETECTOR`](#wkup_detector), [`WKUP_DETECTOR_CNT_TH`](#wkup_detector_cnt_th) and [`WKUP_DETECTOR_PADSEL.`](#wkup_detector_padsel) |

## WKUP_DETECTOR
Configuration of wakeup condition detectors.
Note that these registers are synced to the always-on clock.
The first write access always completes immediately.
However, read/write accesses following a write will block until that write has completed.

Note that the wkup detector should be disabled by setting [`WKUP_DETECTOR_EN_0`](#wkup_detector_en_0) before changing the detection mode.
The reason for that is that the pulse width counter is NOT cleared upon a mode change while the detector is enabled.
- Reset default: `0x0`
- Reset mask: `0x1f`
- Register enable: [`WKUP_DETECTOR_REGWEN`](#wkup_detector_regwen)

### Instances

| Name            | Offset   |
|:----------------|:---------|
| WKUP_DETECTOR_0 | 0x648    |
| WKUP_DETECTOR_1 | 0x64c    |
| WKUP_DETECTOR_2 | 0x650    |
| WKUP_DETECTOR_3 | 0x654    |
| WKUP_DETECTOR_4 | 0x658    |
| WKUP_DETECTOR_5 | 0x65c    |
| WKUP_DETECTOR_6 | 0x660    |
| WKUP_DETECTOR_7 | 0x664    |


### Fields

```wavejson
{"reg": [{"name": "MODE", "bits": 3, "attr": ["rw"], "rotate": 0}, {"name": "FILTER", "bits": 1, "attr": ["rw"], "rotate": -90}, {"name": "MIODIO", "bits": 1, "attr": ["rw"], "rotate": -90}, {"bits": 27}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name                             |
|:------:|:------:|:-------:|:---------------------------------|
|  31:5  |        |         | Reserved                         |
|   4    |   rw   |   0x0   | [MIODIO](#wkup_detector--miodio) |
|   3    |   rw   |   0x0   | [FILTER](#wkup_detector--filter) |
|  2:0   |   rw   |   0x0   | [MODE](#wkup_detector--mode)     |

### WKUP_DETECTOR . MIODIO
0: select index [`WKUP_DETECTOR_PADSEL`](#wkup_detector_padsel) from MIO pads,
1: select index [`WKUP_DETECTOR_PADSEL`](#wkup_detector_padsel) from DIO pads.

### WKUP_DETECTOR . FILTER
0: signal filter disabled, 1: signal filter enabled. the signal must
be stable for 4 always-on clock cycles before the value is being forwarded.
can be used for debouncing.

### WKUP_DETECTOR . MODE
Wakeup detection mode. Out of range values default to Posedge.

| Value   | Name      | Description                                                                                                                              |
|:--------|:----------|:-----------------------------------------------------------------------------------------------------------------------------------------|
| 0x0     | Posedge   | Trigger a wakeup request when observing a positive edge.                                                                                 |
| 0x1     | Negedge   | Trigger a wakeup request when observing a negative edge.                                                                                 |
| 0x2     | Edge      | Trigger a wakeup request when observing an edge in any direction.                                                                        |
| 0x3     | TimedHigh | Trigger a wakeup request when pin is driven HIGH for a certain amount of always-on clock cycles as configured in !!WKUP_DETECTOR_CNT_TH. |
| 0x4     | TimedLow  | Trigger a wakeup request when pin is driven LOW for a certain amount of always-on clock cycles as configured in !!WKUP_DETECTOR_CNT_TH.  |

Other values are reserved.

## WKUP_DETECTOR_CNT_TH
Counter thresholds for wakeup condition detectors.
Note that these registers are synced to the always-on clock.
The first write access always completes immediately.
However, read/write accesses following a write will block until that write has completed.
- Reset default: `0x0`
- Reset mask: `0xff`
- Register enable: [`WKUP_DETECTOR_REGWEN`](#wkup_detector_regwen)

### Instances

| Name                   | Offset   |
|:-----------------------|:---------|
| WKUP_DETECTOR_CNT_TH_0 | 0x668    |
| WKUP_DETECTOR_CNT_TH_1 | 0x66c    |
| WKUP_DETECTOR_CNT_TH_2 | 0x670    |
| WKUP_DETECTOR_CNT_TH_3 | 0x674    |
| WKUP_DETECTOR_CNT_TH_4 | 0x678    |
| WKUP_DETECTOR_CNT_TH_5 | 0x67c    |
| WKUP_DETECTOR_CNT_TH_6 | 0x680    |
| WKUP_DETECTOR_CNT_TH_7 | 0x684    |


### Fields

```wavejson
{"reg": [{"name": "TH", "bits": 8, "attr": ["rw"], "rotate": 0}, {"bits": 24}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name   | Description                                                                                                                                                      |
|:------:|:------:|:-------:|:-------|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------|
|  31:8  |        |         |        | Reserved                                                                                                                                                         |
|  7:0   |   rw   |   0x0   | TH     | Counter threshold for TimedLow and TimedHigh wakeup detector modes (see [`WKUP_DETECTOR`](#wkup_detector)). The threshold is in terms of always-on clock cycles. |

## WKUP_DETECTOR_PADSEL
Pad selects for pad wakeup condition detectors.
This register is NOT synced to the AON domain since the muxing mechanism is implemented in the same way as the pinmux muxing matrix.
- Reset default: `0x0`
- Reset mask: `0x3f`
- Register enable: [`WKUP_DETECTOR_REGWEN`](#wkup_detector_regwen)

### Instances

| Name                   | Offset   |
|:-----------------------|:---------|
| WKUP_DETECTOR_PADSEL_0 | 0x688    |
| WKUP_DETECTOR_PADSEL_1 | 0x68c    |
| WKUP_DETECTOR_PADSEL_2 | 0x690    |
| WKUP_DETECTOR_PADSEL_3 | 0x694    |
| WKUP_DETECTOR_PADSEL_4 | 0x698    |
| WKUP_DETECTOR_PADSEL_5 | 0x69c    |
| WKUP_DETECTOR_PADSEL_6 | 0x6a0    |
| WKUP_DETECTOR_PADSEL_7 | 0x6a4    |


### Fields

```wavejson
{"reg": [{"name": "SEL", "bits": 6, "attr": ["rw"], "rotate": 0}, {"bits": 26}], "config": {"lanes": 1, "fontsize": 10, "vspace": 80}}
```

|  Bits  |  Type  |  Reset  | Name                              |
|:------:|:------:|:-------:|:----------------------------------|
|  31:6  |        |         | Reserved                          |
|  5:0   |   rw   |   0x0   | [SEL](#wkup_detector_padsel--sel) |

### WKUP_DETECTOR_PADSEL . SEL
Selects a specific MIO or DIO pad (depending on [`WKUP_DETECTOR`](#wkup_detector) configuration).
In case of MIO, the pad select index is the same as used for [`MIO_PERIPH_INSEL`](#mio_periph_insel), meaning that index
0 and 1 just select constants 0 and 1, and the MIO pads live at indices >= 2. In case of DIO pads,
the pad select index corresponds 1:1 to the DIO pad to be selected.

## WKUP_CAUSE
Cause registers for wakeup detectors.
Note that these registers are synced to the always-on clock.
The first write access always completes immediately.
However, read/write accesses following a write will block until that write has completed.
- Offset: `0x6a8`
- Reset default: `0x0`
- Reset mask: `0xff`

### Fields

```wavejson
{"reg": [{"name": "CAUSE_0", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "CAUSE_1", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "CAUSE_2", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "CAUSE_3", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "CAUSE_4", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "CAUSE_5", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "CAUSE_6", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"name": "CAUSE_7", "bits": 1, "attr": ["rw0c"], "rotate": -90}, {"bits": 24}], "config": {"lanes": 1, "fontsize": 10, "vspace": 90}}
```

|  Bits  |  Type  |  Reset  | Name    | Description                                                                             |
|:------:|:------:|:-------:|:--------|:----------------------------------------------------------------------------------------|
|  31:8  |        |         |         | Reserved                                                                                |
|   7    |  rw0c  |   0x0   | CAUSE_7 | Set to 1 if the corresponding detector has detected a wakeup pattern. Write 0 to clear. |
|   6    |  rw0c  |   0x0   | CAUSE_6 | Set to 1 if the corresponding detector has detected a wakeup pattern. Write 0 to clear. |
|   5    |  rw0c  |   0x0   | CAUSE_5 | Set to 1 if the corresponding detector has detected a wakeup pattern. Write 0 to clear. |
|   4    |  rw0c  |   0x0   | CAUSE_4 | Set to 1 if the corresponding detector has detected a wakeup pattern. Write 0 to clear. |
|   3    |  rw0c  |   0x0   | CAUSE_3 | Set to 1 if the corresponding detector has detected a wakeup pattern. Write 0 to clear. |
|   2    |  rw0c  |   0x0   | CAUSE_2 | Set to 1 if the corresponding detector has detected a wakeup pattern. Write 0 to clear. |
|   1    |  rw0c  |   0x0   | CAUSE_1 | Set to 1 if the corresponding detector has detected a wakeup pattern. Write 0 to clear. |
|   0    |  rw0c  |   0x0   | CAUSE_0 | Set to 1 if the corresponding detector has detected a wakeup pattern. Write 0 to clear. |


<!-- END CMDGEN -->
