/* Copyright (c) 2011, Code Aurora Forum. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#include <linux/kernel.h>
#include <linux/platform_device.h>
#include <mach/irqs.h>
#include <mach/msm_iomap.h>
#include <mach/board.h>

#include "clock.h"
#include "clock-dummy.h"
#include "clock-voter.h"
#include "devices.h"

static struct resource msm_dmov_resource[] = {
	{
		.start	= INT_ADM_AARM,
		.end	= (resource_size_t)MSM_DMOV_BASE,
		.flags	= IORESOURCE_IRQ,
	},
};

struct platform_device msm_device_dmov = {
	.name		= "msm_dmov",
	.id		= -1,
	.resource	= msm_dmov_resource,
	.num_resources	= ARRAY_SIZE(msm_dmov_resource),
};

static struct resource resources_uart1[] = {
	{
		.start	= INT_UART1,
		.end	= INT_UART1,
		.flags	= IORESOURCE_IRQ,
	},
	{
		.start	= MSM_UART1_PHYS,
		.end	= MSM_UART1_PHYS + MSM_UART1_SIZE - 1,
		.flags	= IORESOURCE_MEM,
	},
};

struct platform_device msm_device_uart1 = {
	.name	= "msm_serial",
	.id	= 0,
	.num_resources	= ARRAY_SIZE(resources_uart1),
	.resource	= resources_uart1,
};

struct clk_lookup msm_clocks_7x27a[] = {
	CLK_DUMMY("adm_clk",	ADM_CLK,	NULL, 0),
	CLK_DUMMY("adsp_clk",	ADSP_CLK,	NULL, 0),
	CLK_DUMMY("ebi1_clk",	EBI1_CLK,	NULL, CLK_MIN),
	CLK_DUMMY("ebi2_clk",	EBI2_CLK,	NULL, 0),
	CLK_DUMMY("ecodec_clk",	ECODEC_CLK,	NULL, 0),
	CLK_DUMMY("gp_clk",	GP_CLK,		NULL, 0),
	CLK_DUMMY("grp_clk",	GRP_3D_CLK,	NULL, 0),
	CLK_DUMMY("grp_pclk",	GRP_3D_P_CLK,	NULL, 0),
	CLK_DUMMY("i2c_clk",	I2C_CLK,	"msm_i2c.0", 0),
	CLK_DUMMY("icodec_rx_clk",	ICODEC_RX_CLK,	NULL, 0),
	CLK_DUMMY("icodec_tx_clk",	ICODEC_TX_CLK,	NULL, 0),
	CLK_DUMMY("imem_clk",	IMEM_CLK,	NULL, OFF),
	CLK_DUMMY("mdc_clk",	MDC_CLK,	NULL, 0),
	CLK_DUMMY("mddi_clk",	PMDH_CLK,	NULL, OFF | CLK_MINMAX),
	CLK_DUMMY("mdp_clk",	MDP_CLK,	NULL, OFF),
	CLK_DUMMY("mdp_lcdc_pclk_clk", MDP_LCDC_PCLK_CLK, NULL, 0),
	CLK_DUMMY("mdp_lcdc_pad_pclk_clk", MDP_LCDC_PAD_PCLK_CLK, NULL, 0),
	CLK_DUMMY("mdp_vsync_clk",	MDP_VSYNC_CLK,	NULL, OFF),
	CLK_DUMMY("pbus_clk",	PBUS_CLK,	NULL, CLK_MIN),
	CLK_DUMMY("pcm_clk",	PCM_CLK,	NULL, 0),
	CLK_DUMMY("sdac_clk",	SDAC_CLK,	NULL, OFF),
	CLK_DUMMY("sdc_clk",	SDC1_CLK,	"msm_sdcc.1", OFF),
	CLK_DUMMY("sdc_pclk",	SDC1_P_CLK,	"msm_sdcc.1", OFF),
	CLK_DUMMY("sdc_clk",	SDC2_CLK,	"msm_sdcc.2", OFF),
	CLK_DUMMY("sdc_pclk",	SDC2_P_CLK,	"msm_sdcc.2", OFF),
	CLK_DUMMY("sdc_clk",	SDC3_CLK,	"msm_sdcc.3", OFF),
	CLK_DUMMY("sdc_pclk",	SDC3_P_CLK,	"msm_sdcc.3", OFF),
	CLK_DUMMY("sdc_clk",	SDC4_CLK,	"msm_sdcc.4", OFF),
	CLK_DUMMY("sdc_pclk",	SDC4_P_CLK,	"msm_sdcc.4", OFF),
	CLK_DUMMY("tsif_clk",	TSIF_CLK,	NULL, 0),
	CLK_DUMMY("tsif_ref_clk", TSIF_REF_CLK,	NULL, 0),
	CLK_DUMMY("tsif_pclk",	TSIF_P_CLK,	NULL, 0),
	CLK_DUMMY("uart_clk",	UART1_CLK,	"msm_serial.0", OFF),
	CLK_DUMMY("uart_clk",	UART2_CLK,	"msm_serial.1", 0),
	CLK_DUMMY("uartdm_clk",	UART1DM_CLK,	"msm_serial_hs.0", OFF),
	CLK_DUMMY("uartdm_clk",	UART2DM_CLK,	"msm_serial_hs.1", 0),
	CLK_DUMMY("usb_hs_clk",	USB_HS_CLK,	NULL, OFF),
	CLK_DUMMY("usb_hs_pclk",	USB_HS_P_CLK,	NULL, OFF),
	CLK_DUMMY("usb_otg_clk",	USB_OTG_CLK,	NULL, 0),
	CLK_DUMMY("usb_phy_clk",	USB_PHY_CLK,	NULL, 0),
	CLK_DUMMY("vdc_clk",	VDC_CLK,	NULL, OFF | CLK_MIN),
	CLK_DUMMY("vfe_clk",	VFE_CLK,	NULL, OFF),
	CLK_DUMMY("vfe_mdc_clk",	VFE_MDC_CLK,	NULL, OFF),
	CLK_DUMMY("gsbi_qup_clk", GSBI1_QUP_CLK,		NULL, OFF),
	CLK_DUMMY("gsbi_qup_clk", GSBI2_QUP_CLK,		NULL, OFF),
	CLK_DUMMY("gsbi_qup_pclk", GSBI1_QUP_P_CLK,	NULL, OFF),
	CLK_DUMMY("gsbi_qup_pclk", GSBI2_QUP_P_CLK,	NULL, OFF),
	CLK_DUMMY("dsi_clk",	DSI_CLK,		NULL, OFF),
	CLK_DUMMY("dsi_esc_clk",	DSI_ESC_CLK,		NULL, OFF),
	CLK_DUMMY("dsi_pixel_clk", DSI_PIXEL_CLK,	NULL, OFF),
	CLK_DUMMY("dsi_byte_clk",  DSI_BYTE_CLK,		NULL, OFF),

	CLK_VOTER("ebi1_acpu_clk",	EBI_ACPU_CLK,	"ebi1_clk", NULL, 0),
	CLK_VOTER("ebi1_kgsl_clk",	EBI_KGSL_CLK,	"ebi1_clk", NULL, 0),
	CLK_VOTER("ebi1_lcdc_clk",	EBI_LCDC_CLK,	"ebi1_clk", NULL, 0),
	CLK_VOTER("ebi1_mddi_clk",	EBI_MDDI_CLK,	"ebi1_clk", NULL, 0),
	CLK_VOTER("ebi1_usb_clk",	EBI_USB_CLK,	"ebi1_clk", NULL, 0),
	CLK_VOTER("ebi1_vfe_clk",	EBI_VFE_CLK,	"ebi1_clk", NULL, 0),
};

unsigned msm_num_clocks_7x27a = ARRAY_SIZE(msm_clocks_7x27a);