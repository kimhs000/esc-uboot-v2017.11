/*
 * (C) Copyright 2015 General Electric Company
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __PPD_GPIO_H_
#define __PPD_GPIO_H_

#include <asm/arch/iomux-mx53.h>
#include <asm/gpio.h>

#define PPD_UART_PAD_CTRL (PAD_CTL_HYS | PAD_CTL_DSE_HIGH |	\
			   PAD_CTL_PUS_100K_UP)

static const iomux_v3_cfg_t ppd_pads[] = {
	/* FEC */
	MX53_PAD_EIM_A22__GPIO2_16,
	/* UART */
	NEW_PAD_CTRL(MX53_PAD_PATA_DMACK__UART1_RXD_MUX, PPD_UART_PAD_CTRL),
	NEW_PAD_CTRL(MX53_PAD_PATA_DIOW__UART1_TXD_MUX, PPD_UART_PAD_CTRL),
	/* Video */
	MX53_PAD_CSI0_DATA_EN__GPIO5_20, /* LR_SCAN_CTRL */
	MX53_PAD_CSI0_VSYNC__GPIO5_21,	 /* UD_SCAN_CTRL */
	MX53_PAD_CSI0_DAT10__GPIO5_28,	 /* DATA_WIDTH_CTRL */
	MX53_PAD_CSI0_PIXCLK__GPIO5_18,	 /* HOST_CONTROLLED_RESET_TO_LCD_N */
	MX53_PAD_EIM_DA2__GPIO3_2,	 /* LVDS1_MUX_CTRL */
	MX53_PAD_EIM_DA3__GPIO3_3,	 /* LVDS0_MUX_CTRL */
	MX53_PAD_EIM_A21__GPIO2_17,	 /* ENABLE_PWR_TO_LCD_AND_UI_INTERFACE */
	MX53_PAD_CSI0_DAT11__GPIO5_29,	 /* BACKLIGHT_ENABLE */
	MX53_PAD_DISP0_DAT9__PWM2_PWMO,	 /* IMX535_PWM2_TO_LCD_CONNECTOR */
	/* I2C */
	MX53_PAD_EIM_A20__GPIO2_18,	 /* RESET_I2C1_BUS_SEGMENT_MUX_N */

	/* SPI */
	MX53_PAD_DISP0_DAT23__GPIO5_17,
	MX53_PAD_KEY_COL2__GPIO4_10,
	MX53_PAD_KEY_ROW2__GPIO4_11,
	MX53_PAD_KEY_COL3__GPIO4_12,
};

struct gpio_cfg {
	unsigned int gpio;
	int value;
};

#define RESET_IMX535_ETHERNET_PHY_N IMX_GPIO_NR(2, 16)
#define UD_SCAN_CTRL IMX_GPIO_NR(5, 21)
#define LR_SCAN_CTRL IMX_GPIO_NR(5, 20)
#define LVDS0_MUX_CTRL IMX_GPIO_NR(3, 3)
#define LVDS1_MUX_CTRL IMX_GPIO_NR(3, 2)
#define HOST_CONTROLLED_RESET_TO_LCD_N IMX_GPIO_NR(5, 18)
#define DATA_WIDTH_CTRL IMX_GPIO_NR(5, 28)
#define RESET_DP0_TRANSMITTER_N IMX_GPIO_NR(2, 28)
#define RESET_DP1_TRANSMITTER_N IMX_GPIO_NR(2, 29)
#define POWER_DOWN_LVDS0_DESERIALIZER_N IMX_GPIO_NR(2, 22)
#define POWER_DOWN_LVDS1_DESERIALIZER_N IMX_GPIO_NR(2, 27)
#define ENABLE_PWR_TO_LCD_AND_UI_INTERFACE IMX_GPIO_NR(2, 17)
#define BACKLIGHT_ENABLE IMX_GPIO_NR(5, 29)
#define RESET_I2C1_BUS_SEGMENT_MUX_N IMX_GPIO_NR(2, 18)
#define ECSPI1_CS0 IMX_GPIO_NR(5, 17)
#define ECSPI1_CS1 IMX_GPIO_NR(4, 10)
#define ECSPI1_CS2 IMX_GPIO_NR(4, 11)
#define ECSPI1_CS3 IMX_GPIO_NR(4, 12)

static const struct gpio_cfg ppd_gpios[] = {
	/* FEC */
	/* Drive Low as GPIO output for 25ms per Eth Phy IX spec */
	/* Then Drive High as GPIO output to bring Eth Phy IC out of reset */
	{ RESET_IMX535_ETHERNET_PHY_N, 0 },
	{ RESET_IMX535_ETHERNET_PHY_N, 1 },
	/* Video */
	{ UD_SCAN_CTRL, 0 },
	{ LR_SCAN_CTRL, 1 },
#ifdef PROPRIETARY_CHANGES
	{ LVDS0_MUX_CTRL, 1 },
#else
	{ LVDS0_MUX_CTRL, 0 },
#endif
	{ LVDS1_MUX_CTRL, 1 },
	{ HOST_CONTROLLED_RESET_TO_LCD_N, 1 },
	{ DATA_WIDTH_CTRL, 0 },
	{ RESET_DP0_TRANSMITTER_N, 1 },
	{ RESET_DP1_TRANSMITTER_N, 1 },
	{ POWER_DOWN_LVDS0_DESERIALIZER_N, 1 },
	{ POWER_DOWN_LVDS1_DESERIALIZER_N, 1 },
	{ ENABLE_PWR_TO_LCD_AND_UI_INTERFACE, 1 },
	{ BACKLIGHT_ENABLE, 0 },
	{ RESET_I2C1_BUS_SEGMENT_MUX_N, 1 },
	{ ECSPI1_CS0, 1 },
	{ ECSPI1_CS1, 1 },
	{ ECSPI1_CS2, 1 },
	{ ECSPI1_CS3, 1 },
};

#endif /* __PPD_GPIO_H_ */
