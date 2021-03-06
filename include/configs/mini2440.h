/*
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
 * Gary Jennejohn <gj@denx.de>
 * David Mueller <d.mueller@elsoft.ch>
 *
 * (C) Copyright 2009
 * Michel Pollet <buserror@gmail.com>
 * 
 * Configuation settings for the MINI2440 board.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_H
#define __CONFIG_H

//#include <common.h>
//#include <s3c2440.h>

#if 0
/* If we want to start u-boot from usb bootloader in NOR flash */
#define CONFIG_SKIP_RELOCATE_UBOOT	1
#define	CONFIG_SKIP_LOWLEVEL_INIT	1
#else
/* If we want to start u-boot directly from within NAND flash
 * Also use this if loading the bootloader directly via JTAG */
#define CONFIG_LL_INIT_NAND_ONLY
#define CONFIG_S3C2410_NAND_BOOT	1
#define CONFIG_S3C2410_NAND_SKIP_BAD	1
#endif

#define CFG_UBOOT_SIZE		0x40000 /* size of u-boot, for NAND loading */

/*
 * High Level Configuration Options
 * (easy to change)
 */
#define CONFIG_ARM920T		1	/* This is an ARM920T Core	*/
#define	CONFIG_S3C2440		1	/* in a SAMSUNG S3C2440 SoC     */
#define CONFIG_MINI2440		1	/* on a MIN2440 Board  */

#define CONFIG_MINI2440_OVERCLOCK 1	/* use frequencies over 405Mhz */

/* input clock of PLL */
#define CONFIG_SYS_CLK_FREQ	12000000	/* MINI2440 has 12.0000MHz input clock */


#define USE_920T_MMU		1
//#define CONFIG_USE_IRQ		1
#undef CONFIG_USE_IRQ			/* we don't need IRQ/FIQ stuff */

/*
 * Size of malloc() pool
 */
#define CFG_MALLOC_LEN		(CFG_ENV_SIZE + 2048*1024)
#define CFG_GBL_DATA_SIZE	128	/* size in bytes reserved for initial data */

/*
 * Hardware drivers
 */
#define CONFIG_DRIVER_DM9000 1
#define CONFIG_DRIVER_DM9000_NO_EEPROM 1
#define CONFIG_DM9000_BASE 0x20000300
#define DM9000_IO CONFIG_DM9000_BASE
#define DM9000_DATA (CONFIG_DM9000_BASE+4)

#define CONFIG_DRIVER_S3C24X0_I2C	1
#if (CONFIG_DRIVER_S3C24X0_I2C)
#define CONFIG_HARD_I2C			1
#define CFG_I2C_SPEED			100000	/* 100kHz */
#define CFG_I2C_SLAVE			0x7f
#endif

/*
 * select serial console configuration
 */
#define CONFIG_SERIAL1          1	/* we use SERIAL 1 on MINI2440 */
//#define CONFIG_HWFLOW		1

/************************************************************
 * RTC
 ************************************************************/
#define	CONFIG_RTC_S3C24X0	1

/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE

#define CONFIG_BAUDRATE		115200

/***********************************************************
 * Command definition
 ***********************************************************/
#include <config_cmd_default.h>

#undef CONFIG_CMD_FPGA		/* FPGA configuration Support	*/

#undef CONFIG_CMD_CACHE
#undef CONFIG_CMD_DIAG
#undef CONFIG_CMD_ELF

#define CONFIG_CMD_DATE
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_EXT2
#define CONFIG_CMD_FAT
#define CONFIG_CMD_JFFS2
#define CONFIG_CMD_MMC
#define CONFIG_CMD_NAND
#define CONFIG_CMD_PING
#define CONFIG_CMD_PORTIO
#define CONFIG_CMD_REGINFO
#define CONFIG_CMD_SAVES

#if defined(CONFIG_DRIVER_S3C24X0_I2C)
#define CONFIG_CMD_I2C		/* I2C serial bus support	*/
#endif

#define CONFIG_BOOTDELAY	3
#define CONFIG_BOOTARGS    	"root=/dev/mtdblock3 rootfstype=jffs2 console=ttySAC0,115200"
#define CONFIG_ETHADDR	        08:08:11:18:12:27
#define CONFIG_NETMASK          255.255.255.0
#define CONFIG_IPADDR		10.0.0.111
#define CONFIG_SERVERIP		10.0.0.4

#define CONFIG_BOOTCOMMAND	""

#define CONFIG_DOS_PARTITION	1

#if defined(CONFIG_CMD_KGDB)
#define CONFIG_KGDB_BAUDRATE	115200		/* speed to run kgdb serial port */
/* what's this ? it's not used anywhere */
#define CONFIG_KGDB_SER_INDEX	1		/* which serial port to use */
#endif

/*
 * Miscellaneous configurable options
 */
#define	CFG_LONGHELP				/* undef to save memory		*/
#define	CFG_PROMPT		"MINI2440 # "	/* Monitor Command Prompt	*/
#define	CFG_CBSIZE		256		/* Console I/O Buffer Size	*/
#define	CFG_PBSIZE (CFG_CBSIZE+sizeof(CFG_PROMPT)+16) /* Print Buffer Size */
#define	CFG_MAXARGS		32		/* max number of command args	*/
#define CFG_BARGSIZE		CFG_CBSIZE	/* Boot Argument Buffer Size	*/

#define CFG_MEMTEST_START	0x30000000	/* memtest works on	*/
#define CFG_MEMTEST_END		0x33F00000	/* 63 MB in DRAM	*/

#undef  CFG_CLKS_IN_HZ		/* everything, incl board info, in Hz */

#define	CFG_LOAD_ADDR		0x32000000	/* default load address	*/

/* the PWM TImer 4 uses a counter of 15625 for 10 ms, so we need */
/* it to wrap 100 times (total 1562500) to get 1 sec. */
#define	CFG_HZ			1562500

/* valid baudrates */
#define CFG_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }

/*-----------------------------------------------------------------------
 * Stack sizes
 *
 * The stack sizes are set up in start.S using the settings below
 */
#define CONFIG_STACKSIZE	(512*1024)	/* regular stack */
#ifdef CONFIG_USE_IRQ
#define CONFIG_STACKSIZE_IRQ	(8*1024)	/* IRQ stack */
#define CONFIG_STACKSIZE_FIQ	(4*1024)	/* FIQ stack */
#endif

#if 1
#define CONFIG_USB_OHCI_NEW	1
#define CONFIG_CMD_USB		1

#define CFG_USB_OHCI_CPU_INIT	1
#define CFG_USB_OHCI_REGS_BASE	0x49000000 /* S3C24X0_USB_HOST_BASE */
#define CFG_USB_OHCI_SLOT_NAME	"s3c2440"
#define CFG_USB_OHCI_MAX_ROOT_PORTS 	2

#define CONFIG_USB_DEVICE	1
#define CONFIG_USB_TTY		1
#define CONFIG_USB_STORAGE	1
#define CFG_CONSOLE_IS_IN_ENV	1
#define CONFIG_USBD_VENDORID		0x1457	/* FIC */
#define CONFIG_USBD_PRODUCTID_GSERIAL	0x5120	/* gserial */
#define CONFIG_USBD_PRODUCTID_CDCACM	0x511b	/* SMDK2440 CDC ACM */
#define CONFIG_USBD_MANUFACTURER	"MINI2440"
#define CONFIG_USBD_PRODUCT_NAME	"S3C2440 Bootloader " U_BOOT_VERSION
#define CONFIG_USBD_DFU			1
#define CONFIG_USBD_DFU_XFER_SIZE	4096
#define CONFIG_USBD_DFU_INTERFACE	2
//#define CONFIG_USB_DFU_REVISION 0x0100
#endif

/*-----------------------------------------------------------------------
 * Physical Memory Map
 */
#define CONFIG_NR_DRAM_BANKS	1	   /* we have 1 bank of DRAM */
#define PHYS_SDRAM_1		0x30000000 /* SDRAM Bank #1 */
#define PHYS_SDRAM_1_SIZE	0x04000000 /* 64 MB */

#define PHYS_FLASH_1		0x00000000 /* Flash Bank #1 */

#define CFG_FLASH_BASE		PHYS_FLASH_1

/*-----------------------------------------------------------------------
 * FLASH and environment organization
 */

#define CONFIG_SST_VF1601	1	/* uncomment this if you have a Am29LV160DB flash */

#define CFG_MAX_FLASH_BANKS	1	/* max number of memory banks */

#ifdef CONFIG_SST_VF1601
#define PHYS_FLASH_SIZE		0x00200000 /* 2MB */
#define CFG_MAX_FLASH_SECT	(32)	/* max number of sectors on one chip */
#endif

/* timeout values are in ticks */
#define CFG_FLASH_ERASE_TOUT	(5*CFG_HZ) /* Timeout for Flash Erase */
#define CFG_FLASH_WRITE_TOUT	(5*CFG_HZ) /* Timeout for Flash Write */

/*
 * u-boot environmnet
 */
#if 1
#define	CFG_ENV_IS_IN_NAND	1
#define CFG_ENV_OFFSET_OOB	1	// dont define for CFG_ENV_IS_IN_FLASH
#define CFG_ENV_SIZE		0x10000		/* 64k Total Size of Environment Sector */
#else
#define CFG_ENV_IS_IN_FLASH 1
#define CFG_MY_ENV_OFFSET 0X40000
#define CFG_ENV_ADDR		(CFG_FLASH_BASE + CFG_MY_ENV_OFFSET) /* addr of environment */
#define CFG_ENV_SIZE		0x10000		/* 64k Total Size of Environment Sector */
#endif
#define CFG_PREBOOT_OVERRIDE	1

#define NAND_MAX_CHIPS		1
#define CFG_NAND_BASE		0x4E000000 /* S3C2440_NAND_BASE */
#define CFG_MAX_NAND_DEVICE	1

#define CONFIG_MMC		1
#define CONFIG_MMC_S3C	1	/* Enabling the MMC driver */
#define CFG_MMC_BASE		0xff000000

#define CONFIG_EXT2		1

#define CONFIG_FAT		1
#define CONFIG_SUPPORT_VFAT	1

#if 1
/* JFFS2 driver */
#define CONFIG_JFFS2_CMDLINE	1
#define CONFIG_JFFS2_NAND	1
#define CONFIG_JFFS2_NAND_DEV	0
//#define CONFIG_JFFS2_NAND_OFF		0x634000
//#define CONFIG_JFFS2_NAND_SIZE	0x39cc000
#endif

/* ATAG configuration */
#define CONFIG_INITRD_TAG		1
#define CONFIG_SETUP_MEMORY_TAGS	1
#define CONFIG_CMDLINE_TAG		1
#if 0
#define CONFIG_REVISION_TAG		1
#define CONFIG_SERIAL_TAG		1
#endif
#define CONFIG_CMDLINE_EDITING	1
#define CONFIG_AUTO_COMPLETE	1


#if 0
#define CONFIG_CMD_BMP 
#define CONFIG_VIDEO
#define CONFIG_VIDEO_S3C2410
#define CONFIG_VIDEO_LOGO
#define CONFIG_CFB_CONSOLE
//#define CFG_CONSOLE_IS_IN_ENV
//#define CONFIG_CONSOLE_EXTRA_INFO
#define CONFIG_VGA_AS_SINGLE_DEVICE

#define VIDEO_FB_16BPP_PIXEL_SWAP 
#define CONFIG_VIDEO_BMP_LOGO 
#define CONFIG_SPLASH_SCREEN 
#define CFG_VIDEO_LOGO_MAX_SIZE         (240*320+1024+100) /* 100 = slack */ 
#define CONFIG_VIDEO_BMP_GZIP 
#define CONFIG_CMD_UNZIP 

#define VIDEO_KBD_INIT_FCT	0
#define VIDEO_TSTC_FCT		serial_tstc
#define VIDEO_GETC_FCT		serial_getc

#define LCD_VIDEO_ADDR		0x33d00000
#endif

#define CONFIG_S3C2410_NAND_BBT		1	
//#define CONFIG_S3C2440_NAND_HWECC	1	/* this works for generation, not verification */

#define CFG_NAND_YAFFS_WRITE
#define CFG_NAND_YAFFS1_NEW_OOB_LAYOUT

#define MTDIDS_DEFAULT		"nand0=mini2440-nand"
#define MTPDARTS_DEFAULT		"mtdparts=mtdparts=mini2440-nand:256k@0(u-boot),128k(env),5m(kernel),-(root)"
#define CFG_NAND_DYNPART_MTD_KERNEL_NAME "mini2440-nand"
#define CONFIG_NAND_DYNPART	1

#define CONFIG_EXTRA_ENV_SETTINGS	\
	"usbtty=cdc_acm\0" \
	"mtdparts=mtdparts=mini2440-nand:256k@0(u-boot),128k(env),5m(kernel),-(root)\0" \
	"mini2440=mini2440=0tb\0" \
	"bootargs_base=console=ttySAC0,115200 noinitrd\0" \
	"bootargs_init=init=/sbin/init\0" \
	"root_nand=root=/dev/mtdblock3 rootfstype=jffs2\0" \
	"root_mmc=root=/dev/mmcblk0p2 rootdelay=2\0" \
	"root_nfs=/mnt/nfs\0" \
	"set_root_nfs=setenv root_nfs root=/dev/nfs rw nfsroot=${serverip}:${root_nfs}\0" \
	"ifconfig_static=run setenv ifconfig ip=${ipaddr}:${serverip}::${netmask}:mini2440:eth0\0" \
	"ifconfig_dhcp=run setenv ifconfig ip=dhcp\0" \
	"ifconfig=ip=dhcp\0" \
	"set_bootargs_mmc=setenv bootargs ${bootargs_base} ${bootargs_init} ${mini2440} ${root_mmc}\0" \
	"set_bootargs_nand=setenv bootargs ${bootargs_base} ${bootargs_init} ${mini2440} ${root_nand}\0" \
	"set_bootargs_nfs=run set_root_nfs\; setenv bootargs ${bootargs_base} ${bootargs_init} ${mini2440} ${root_nfs} ${ifconfig}\0" \
	""	

#endif	/* __CONFIG_H */
