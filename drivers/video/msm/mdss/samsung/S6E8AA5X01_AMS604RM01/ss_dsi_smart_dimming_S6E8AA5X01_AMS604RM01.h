/*
 * =================================================================
 *
 *
 *	Description:  samsung display panel file
 *
 *	Author: jb09.kim
 *	Company:  Samsung Electronics
 *
 * ================================================================
 */
/*
<one line to give the program's name and a brief idea of what it does.>
Copyright (C) 2012, Samsung Electronics. All rights reserved.

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
 *
*/
#ifndef _SAMSUNG_DSI_SMART_DIMMING_S6E8AA5X01_AMS604RM01_H_
#define _SAMSUNG_DSI_SMART_DIMMING_S6E8AA5X01_AMS604RM01_H_

#include "../ss_dsi_panel_common.h"
#include "../ss_dsi_smart_dimming_common.h"

/*
*	From 4.8 inch model use AID function
*	CASE#1 is used for now.
*/
#define AID_OPERATION

enum {
	GAMMA_CURVE_1P9 = 0,
	GAMMA_CURVE_2P15,
	GAMMA_CURVE_2P2,
};

#define LUMINANCE_MAX 62
#define GAMMA_SET_MAX 35
#define BIT_SHIFT 22
/*
	it means BIT_SHIFT is 22.  pow(2,BIT_SHIFT) is 4194304.
	BIT_SHIFT is used for right bit shfit
*/
#define BIT_SHFIT_MUL 4194304

#define GRAY_SCALE_MAX 256

/*6.3 * 4194304 */
#define VREG0_REF_6P3 26424115
/*6.2 * 4194304 */
#define VREG0_REF_6P2 26004685
/*6.0 * 4194304 */
#define VREG0_REF_6P0 25165824

/*V0,V3,V11,V23,V35,V51,V87,V151,V203,V255*/
#define ARRAY_MAX 11

/* PANEL DEPENDENT THINGS */
#define MIN_CANDELA	2

#define HBM_INTERPOLATION_STEP 8

/*
*	ID 0x20
*/
#define V255_300CD_R_MSB_20 0x01
#define V255_300CD_R_LSB_20 0x00

#define V255_300CD_G_MSB_20 0x01
#define V255_300CD_G_LSB_20 0x00

#define V255_300CD_B_MSB_20 0x01
#define V255_300CD_B_LSB_20 0x00

#define V203_300CD_R_20 0x80
#define V203_300CD_G_20 0x80
#define V203_300CD_B_20 0x80

#define V151_300CD_R_20 0x80
#define V151_300CD_G_20 0x80
#define V151_300CD_B_20 0x80

#define V87_300CD_R_20 0x80
#define V87_300CD_G_20 0x80
#define V87_300CD_B_20 0x80

#define V51_300CD_R_20 0x80
#define V51_300CD_G_20 0x80
#define V51_300CD_B_20 0x80

#define V35_300CD_R_20 0x80
#define V35_300CD_G_20 0x80
#define V35_300CD_B_20 0x80

#define V23_300CD_R_20 0x80
#define V23_300CD_G_20 0x80
#define V23_300CD_B_20 0x80

#define V11_300CD_R_20 0x80
#define V11_300CD_G_20 0x80
#define V11_300CD_B_20 0x80

#define V3_300CD_R_20 0x80
#define V3_300CD_G_20 0x80
#define V3_300CD_B_20 0x80

#define V0_300CD_R_20 0x00
#define V0_300CD_G_20 0x00
#define V0_300CD_B_20 0x00

#define VT_300CD_R_20 0x00
#define VT_300CD_G_20 0x00
#define VT_300CD_B_20 0x00


/* PANEL DEPENDENT THINGS END*/

enum {
	V1_INDEX = 0,
	V3_INDEX = 1,
	V11_INDEX = 2,
	V23_INDEX = 3,
	V35_INDEX = 4,
	V51_INDEX = 5,
	V87_INDEX = 6,
	V151_INDEX = 7,
	V203_INDEX = 8,
	V255_INDEX = 9,
};

struct GAMMA_LEVEL {
	int level_0;
	int level_1;
	int level_3;
	int level_11;
	int level_23;
	int level_35;
	int level_51;
	int level_87;
	int level_151;
	int level_203;
	int level_255;
} __packed;

struct RGB_OUTPUT_VOLTARE {
	struct GAMMA_LEVEL R_VOLTAGE;
	struct GAMMA_LEVEL G_VOLTAGE;
	struct GAMMA_LEVEL B_VOLTAGE;
} __packed;

struct GRAY_VOLTAGE {
	/*
		This voltage value use 14bit right shit
		it means voltage is divied by 16384.
	*/
	int R_Gray;
	int G_Gray;
	int B_Gray;
} __packed;

struct GRAY_SCALE {
	struct GRAY_VOLTAGE TABLE[GRAY_SCALE_MAX];
	struct GRAY_VOLTAGE VT_TABLE;
} __packed;

/*V0,V1,V3,V11,V23,V35,V51,V87,V151,V203,V255*/

struct MTP_SET {
	char OFFSET_255_MSB;
	char OFFSET_255_LSB;
	char OFFSET_203;
	char OFFSET_151;
	char OFFSET_87;
	char OFFSET_51;
	char OFFSET_35;
	char OFFSET_23;
	char OFFSET_11;
	char OFFSET_3;
	char OFFSET_0;
	char OFFSET_T;
} __packed;
struct MTP_SET_R {
	char OFFSET_255_MSB;
	char OFFSET_255_LSB;
	char OFFSET_203;
	char OFFSET_151;
	char OFFSET_87;
	char OFFSET_51;
	char OFFSET_35;
	char OFFSET_23;
	char OFFSET_11;
	char OFFSET_3;
	char OFFSET_0;
} __packed;

struct MTP_OFFSET {
	struct MTP_SET_R R_OFFSET;
	struct MTP_SET G_OFFSET;
	struct MTP_SET B_OFFSET;
} __packed;

struct illuminance_table {
	int lux;
	char gamma_setting[GAMMA_SET_MAX];
} __packed;

struct SMART_DIM {
	struct MTP_OFFSET MTP_ORIGN;

	struct MTP_OFFSET MTP;
	struct RGB_OUTPUT_VOLTARE RGB_OUTPUT;
	struct GRAY_SCALE GRAY;

	/* Because of AID funtion, below members are added*/
	int lux_table_max;
	int *plux_table;
	struct illuminance_table gen_table[LUMINANCE_MAX];

	int brightness_level;
	int ldi_revision;
	int vregout_voltage;

	/* HBM interpolation */
	struct illuminance_table hbm_interpolation_table[HBM_INTERPOLATION_STEP];
	char *hbm_payload;
	int hbm_brightness_level;

	char panel_revision;
} __packed;

#define AOR_DIM_BASE_CD	120

#define CANDELA_MAX_TABLE 61
#define RGB_COMPENSATION 24

static int candela_table[][2] = {
	{5, 0},
	{6, 1},
	{7, 2},
	{8, 3},
	{9, 4},
	{10, 5},
	{11, 6},
	{12, 7},
	{13, 8},
	{14, 9},
	{15, 10},
	{16, 11},
	{17, 12},
	{19, 13},
	{20, 14},
	{21, 15},
	{22, 16},
	{24, 17},
	{25, 18},
	{27, 19},
	{29, 20},
	{30, 21},
	{32, 22},
	{34, 23},
	{37, 24},
	{39, 25},
	{41, 26},
	{44, 27},
	{47, 28},
	{50, 29},
	{53, 30},
	{56, 31},
	{60, 32},
	{64, 33},
	{68, 34},
	{72, 35},
	{77, 36},
	{82, 37},
	{87, 38},
	{93, 39},
	{98, 40},
	{105, 41},
	{111, 42},
	{119, 43},
	{126, 44},
	{134, 45},
	{143, 46},
	{152, 47},
	{162, 48},
	{172, 49},
	{183, 50},
	{195, 51},
	{207, 52},
	{220, 53},
	{234, 54},
	{249, 55},
	{265, 56},
	{282, 57},
	{300, 58},
	{316, 59},
	{333, 60},
	{360, 61},
};

static unsigned int base_luminance_revA[LUMINANCE_MAX][2] = {
	{5,		111},
	{6,		111},
	{7,		111},
	{8,		111},
	{9,		111},
	{10,	111},
	{11,	111},
	{12,	111},
	{13,	111},
	{14,	111},
	{15,	111},
	{16,	111},
	{17,	111},
	{19,	111},
	{20,	111},
	{21,	111},
	{22,	111},
	{24,	111},
	{25,	111},
	{27,	111},
	{29,	111},
	{30,	111},
	{32,	111},
	{34,	111},
	{37,	111},
	{39,	111},
	{41,	111},
	{44,	111},
	{47,	111},
	{50,	111},
	{53,	111},
	{56,	111},
	{60,	111},
	{64,	111},
	{68,	114},
	{72,	120},
	{77,	129},
	{82,	136},
	{87,	145},
	{93,	154},
	{98,	161},
	{105,	173},
	{111,	183},
	{119,	193},
	{126,	193},
	{134,	193},
	{143,	193},
	{152,	193},
	{162,	193},
	{172,	193},
	{183,	197},
	{195,	208},
	{207,	220},
	{220,	233},
	{234,	246},
	{249,	260},
	{265,	273},
	{282,	289},
	{300,	307},
	{316,	320},
	{333,	335},
	{360,	360},
};


static int gradation_offset_revA[][9] = {
/*	V255 V203 V151 V87 V51 V35 V23 V11 V3 */
	{0,	2,	2,	4,	5,	8,	9,	12,	12},
	{0,	2,	2,	4,	5,	8,	9,	12,	12},
	{0,	2,	2,	3,	4,	6,	7,	10,	10},
	{0,	2,	2,	3,	4,	6,	7,	10,	10},
	{0,	2,	2,	2,	3,	5,	7,	9,	9},
	{0,	2,	2,	2,	3,	5,	6,	8,	8},
	{0,	2,	1,	2,	3,	5,	6,	8,	8},
	{0,	1,	1,	2,	2,	4,	5,	7,	7},
	{0,	1,	1,	2,	2,	4,	5,	7,	7},
	{0,	1,	1,	2,	2,	3,	4,	6,	6},
	{0,	1,	1,	2,	2,	3,	4,	6,	6},
	{0,	1,	1,	2,	2,	3,	4,	5,	5},
	{0,	1,	1,	2,	2,	3,	4,	5,	5},
	{0,	1,	1,	2,	2,	3,	4,	5,	5},
	{0,	1,	1,	2,	2,	3,	4,	5,	5},
	{0,	1,	1,	2,	2,	3,	4,	6,	5},
	{0,	1,	1,	2,	2,	3,	4,	6,	5},
	{0,	1,	1,	2,	2,	3,	4,	6,	5},
	{0,	1,	1,	2,	3,	4,	5,	7,	6},
	{0,	2,	2,	3,	3,	5,	5,	7,	6},
	{0,	2,	2,	3,	3,	5,	6,	8,	6},
	{0,	2,	2,	3,	3,	5,	6,	8,	6},
	{0,	2,	2,	3,	3,	5,	6,	8,	6},
	{0,	2,	2,	3,	3,	5,	6,	7,	6},
	{0,	2,	2,	3,	3,	4,	5,	6,	6},
	{0,	2,	2,	3,	3,	4,	5,	6,	6},
	{0,	2,	2,	3,	3,	4,	5,	6,	6},
	{0,	2,	2,	3,	3,	4,	5,	5,	6},
	{0,	2,	2,	3,	2,	3,	4,	5,	6},
	{0,	2,	2,	3,	2,	3,	4,	5,	6},
	{0,	2,	2,	3,	2,	3,	4,	5,	6},
	{0,	2,	2,	3,	2,	3,	4,	4,	6},
	{0,	2,	2,	3,	2,	3,	4,	4,	6},
	{0,	2,	2,	3,	2,	2,	3,	4,	6},
	{0,	2,	2,	3,	2,	2,	3,	4,	6},
	{0,	2,	3,	3,	2,	2,	3,	4,	6},
	{0,	2,	3,	3,	2,	2,	3,	4,	6},
	{0,	2,	3,	3,	2,	2,	3,	4,	6},
	{0,	2,	3,	3,	2,	3,	3,	4,	6},
	{0,	1,	2,	3,	1,	2,	3,	4,	6},
	{0,	1,	3,	3,	2,	3,	3,	4,	6},
	{0,	1,	2,	3,	2,	2,	3,	4,	5},
	{0,	1,	3,	3,	2,	2,	2,	3,	5},
	{0,	0,	2,	2,	1,	1,	2,	3,	5},
	{0,	1,	3,	3,	2,	1,	2,	3,	5},
	{0,	0,	2,	2,	1,	1,	2,	3,	4},
	{0,	0,	2,	2,	1,	1,	2,	2,	4},
	{0,	0,	2,	2,	1,	1,	2,	2,	4},
	{0,	0,	2,	2,	1,	1,	2,	2,	3},
	{0,	0,	2,	2,	1,	1,	2,	2,	3},
	{0,	0,	2,	2,	1,	1,	2,	2,	2},
	{0,	1,	2,	2,	1,	1,	1,	1,	2},
	{0,	0,	2,	1,	1,	1,	2,	2,	2},
	{0,	0,	1,	2,	2,	1,	1,	1,	2},
	{0,	0,	1,	1,	0,	0,	1,	1,	2},
	{0,	0,	1,	0,	0,	0,	0,	1,	2},
	{0,	0,	1,	0,	0,	0,	0,	1,	1},
	{0,	0,	1,	0,	0,	0,	0,	0,	1},
	{0,	0,	0,	0,	0,	0,	0,	0,	1},
	{0,	1,	0,	0,	0,	0,	0,	0,	0},
	{0,	0,	0,	0,	0,	0,	-1,	0,	0},
	{0,	0,	0,	0,	0,	0,	0,	0,	0},
};

static int rgb_offset_revA[][RGB_COMPENSATION] = {
/*	R255 	G255	B255 	R203	G203	B203	R151	G151	B151	R87	G87	B87	R51	G51	B51	R35	G35	B35	R23	G23	B23	R11	G11	B11 */
	{-2,	0,	-2,	0,	0,	0,	-1,	0,	-1,	0,	0,	1,	-4,	0,	0,	-3,	0,	0,	1,	0,	1,	2,	0,	-3},
	{-2,	0,	-2,	0,	0,	0,	-1,	0,	-1,	0,	0,	1,	-4,	0,	0,	-1,	0,	0,	-1,	0,	1,	2,	0,	-3},
	{-2,	0,	-2,	0,	0,	0,	-1,	0,	-1,	-1,	0,	1,	-3,	0,	0,	0,	0,	-1,	-3,	0,	0,	2,	0,	-3},
	{-1,	0,	-2,	0,	0,	0,	-1,	0,	-1,	-1,	0,	1,	-3,	0,	0,	0,	0,	-1,	-3,	0,	0,	2,	0,	-3},
	{-1,	0,	-2,	0,	0,	0,	-1,	0,	-1,	0,	0,	1,	-3,	0,	0,	0,	0,	-1,	-3,	0,	-1,	2,	0,	-3},
	{-1,	0,	-2,	0,	0,	0,	-1,	0,	-1,	0,	0,	0,	-3,	0,	0,	0,	0,	-1,	-3,	0,	-1,	2,	0,	-4},
	{-1,	0,	-2,	0,	0,	0,	-1,	0,	-1,	0,	0,	0,	-3,	0,	0,	0,	0,	-1,	-3,	0,	-1,	2,	0,	-4},
	{-1,	0,	-2,	0,	0,	0,	-1,	0,	0,	0,	0,	0,	-3,	0,	0,	0,	0,	-1,	-3,	0,	0,	1,	0,	-5},
	{-1,	0,	-2,	0,	0,	0,	-1,	0,	0,	0,	0,	0,	-3,	0,	0,	0,	0,	-1,	-3,	0,	0,	0,	0,	-6},
	{-1,	0,	-2,	0,	0,	0,	-1,	0,	0,	0,	0,	0,	-3,	0,	0,	0,	0,	-1,	-3,	0,	-1,	0,	0,	-6},
	{-1,	0,	-2,	0,	0,	0,	-1,	0,	0,	0,	0,	0,	-3,	0,	1,	0,	0,	-2,	-2,	0,	-1,	0,	0,	-6},
	{-1,	0,	-2,	0,	0,	0,	-1,	0,	0,	1,	0,	1,	-3,	0,	0,	0,	0,	-2,	-2,	0,	-1,	0,	0,	-6},
	{-1,	0,	-2,	0,	0,	0,	-1,	0,	0,	1,	0,	1,	-3,	0,	0,	0,	0,	-2,	-2,	0,	-1,	0,	0,	-6},
	{-1,	0,	-2,	0,	0,	0,	-1,	0,	0,	1,	0,	1,	-3,	0,	0,	0,	0,	-2,	-2,	0,	-1,	-1,	0,	-5},
	{0,	0,	-1,	0,	0,	0,	-1,	0,	0,	0,	0,	0,	-3,	0,	0,	0,	0,	-2,	-2,	0,	-1,	-1,	0,	-3},
	{0,	0,	-1,	0,	0,	0,	-1,	0,	0,	1,	0,	1,	-2,	0,	0,	0,	0,	-2,	-3,	0,	-2,	-1,	0,	-3},
	{1,	0,	0,	0,	0,	0,	-1,	0,	0,	1,	0,	1,	-2,	0,	0,	0,	0,	-2,	-1,	0,	-3,	-1,	0,	-7},
	{2,	0,	2,	0,	0,	0,	-1,	0,	0,	1,	0,	1,	-2,	0,	0,	0,	0,	-3,	-1,	0,	-2,	-1,	0,	-7},
	{2,	0,	2,	1,	0,	1,	0,	0,	0,	1,	0,	1,	-2,	0,	0,	0,	0,	-3,	-2,	0,	-2,	-1,	0,	-6},
	{3,	0,	4,	1,	0,	0,	0,	0,	0,	1,	0,	2,	-2,	0,	0,	0,	0,	-3,	-2,	0,	-2,	-1,	0,	-6},
	{4,	0,	5,	1,	0,	0,	0,	0,	0,	1,	0,	2,	-2,	0,	0,	0,	0,	-3,	-2,	0,	-2,	-1,	0,	-4},
	{5,	0,	6,	1,	0,	0,	0,	0,	0,	1,	0,	2,	-1,	0,	1,	0,	0,	-3,	-2,	0,	-3,	-1,	0,	-4},
	{5,	0,	7,	1,	0,	0,	1,	0,	0,	1,	0,	2,	0,	0,	1,	0,	0,	-3,	-2,	0,	-3,	-1,	0,	-10},
	{6,	0,	8,	1,	0,	0,	1,	0,	1,	1,	0,	2,	0,	0,	1,	0,	0,	-3,	-1,	0,	-3,	-1,	0,	-10},
	{6,	0,	8,	1,	0,	1,	1,	0,	0,	1,	0,	2,	0,	0,	1,	0,	0,	-3,	-1,	0,	-3,	-2,	0,	-13},
	{6,	0,	8,	1,	0,	1,	1,	0,	0,	1,	0,	2,	0,	0,	1,	-1,	0,	-3,	0,	0,	-3,	-2,	0,	-12},
	{6,	0,	8,	1,	0,	1,	1,	0,	0,	1,	0,	2,	0,	0,	2,	-1,	0,	-3,	0,	0,	-3,	-2,	0,	-13},
	{7,	0,	9,	1,	0,	0,	1,	0,	1,	1,	0,	2,	2,	0,	1,	0,	0,	-3,	0,	0,	-1,	-4,	0,	-15},
	{7,	0,	9,	1,	0,	0,	1,	0,	1,	1,	0,	2,	2,	0,	1,	1,	0,	-3,	0,	0,	-3,	-2,	0,	-10},
	{7,	0,	9,	1,	0,	0,	1,	0,	1,	1,	0,	2,	2,	0,	1,	1,	0,	-3,	0,	0,	-2,	-2,	0,	-8},
	{7,	0,	9,	1,	0,	0,	1,	0,	1,	1,	0,	2,	2,	0,	2,	1,	0,	-3,	0,	0,	-2,	-2,	0,	-11},
	{7,	0,	9,	1,	0,	0,	1,	0,	1,	1,	0,	2,	2,	0,	2,	1,	0,	-3,	0,	0,	-2,	-1,	0,	-8},
	{7,	0,	9,	1,	0,	0,	1,	0,	1,	1,	0,	2,	2,	0,	2,	1,	0,	-3,	0,	0,	-2,	-1,	0,	-5},
	{7,	0,	9,	1,	0,	0,	1,	0,	1,	1,	0,	2,	2,	0,	2,	1,	0,	-3,	0,	0,	-2,	-1,	0,	-3},
	{6,	0,	9,	1,	0,	0,	1,	0,	1,	2,	0,	2,	2,	0,	2,	2,	0,	-2,	0,	0,	-2,	-1,	0,	-3},
	{7,	0,	9,	1,	0,	0,	1,	0,	1,	2,	0,	3,	2,	0,	2,	2,	0,	-2,	0,	0,	-1,	0,	0,	-3},
	{6,	0,	9,	1,	0,	0,	1,	0,	0,	1,	0,	2,	2,	0,	2,	2,	0,	-2,	0,	0,	-1,	0,	0,	-4},
	{6,	0,	9,	1,	0,	0,	1,	0,	0,	1,	0,	3,	2,	0,	2,	2,	0,	-1,	-1,	0,	-1,	0,	0,	-3},
	{6,	0,	9,	1,	0,	0,	1,	0,	0,	1,	0,	3,	2,	0,	2,	2,	0,	-1,	1,	0,	-1,	1,	0,	-2},
	{6,	0,	9,	1,	0,	0,	1,	0,	0,	1,	0,	3,	2,	0,	2,	2,	0,	-1,	1,	0,	0,	1,	0,	-2},
	{6,	0,	9,	1,	0,	1,	1,	0,	1,	1,	0,	1,	2,	0,	2,	2,	0,	-1,	0,	0,	0,	1,	0,	-2},
	{4,	0,	7,	1,	0,	1,	1,	0,	1,	1,	0,	2,	2,	0,	1,	2,	0,	-2,	0,	0,	1,	1,	0,	-1},
	{4,	0,	7,	1,	0,	1,	1,	0,	0,	1,	0,	2,	2,	0,	3,	2,	0,	-1,	0,	0,	0,	1,	0,	-1},
	{4,	0,	7,	1,	0,	1,	1,	0,	1,	1,	0,	1,	2,	0,	2,	2,	0,	-1,	0,	0,	-1,	1,	0,	-1},
	{4,	0,	7,	1,	0,	1,	1,	0,	1,	1,	0,	1,	2,	0,	2,	2,	0,	-1,	1,	0,	0,	1,	0,	0},
	{4,	0,	7,	1,	0,	1,	1,	0,	1,	1,	0,	1,	2,	0,	2,	2,	0,	-1,	2,	0,	0,	2,	0,	1},
	{3,	0,	6,	1,	0,	1,	1,	0,	1,	1,	0,	1,	2,	0,	2,	2,	0,	-1,	2,	0,	0,	2,	0,	1},
	{3,	0,	6,	1,	0,	1,	1,	0,	1,	1,	0,	1,	2,	0,	2,	2,	0,	-1,	2,	0,	0,	2,	0,	1},
	{3,	0,	6,	1,	0,	1,	1,	0,	1,	1,	0,	1,	2,	0,	2,	2,	0,	-1,	2,	0,	0,	2,	0,	1},
	{3,	0,	6,	1,	0,	1,	1,	0,	1,	1,	0,	1,	2,	0,	2,	1,	0,	-2,	1,	0,	0,	2,	0,	3},
	{3,	0,	6,	1,	0,	1,	1,	0,	1,	1,	0,	2,	2,	0,	2,	1,	0,	-2,	1,	0,	-1,	2,	0,	2},
	{2,	0,	6,	1,	0,	1,	2,	0,	1,	3,	0,	2,	0,	0,	2,	0,	0,	-2,	1,	0,	0,	2,	0,	4},
	{1,	0,	4,	1,	0,	1,	0,	0,	0,	3,	0,	2,	2,	0,	3,	1,	0,	-1,	2,	0,	0,	2,	0,	2},
	{2,	0,	5,	1,	0,	0,	-1,	0,	0,	2,	0,	2,	1,	0,	2,	1,	0,	0,	1,	0,	-1,	1,	0,	0},
	{2,	0,	4,	1,	0,	1,	0,	0,	0,	1,	0,	1,	0,	0,	1,	2,	0,	-1,	0,	0,	0,	1,	0,	2},
	{1,	0,	3,	0,	0,	0,	1,	0,	1,	3,	0,	2,	0,	0,	2,	1,	0,	-1,	0,	0,	0,	0,	0,	1},
	{0,	0,	3,	1,	0,	1,	1,	0,	0,	2,	0,	2,	1,	0,	2,	2,	0,	1,	2,	0,	-1,	0,	0,	-2},
	{0,	0,	2,	0,	0,	0,	1,	0,	0,	1,	0,	1,	3,	0,	2,	3,	0,	1,	2,	0,	1,	1,	0,	-2},
	{1,	0,	2,	0,	0,	0,	1,	0,	1,	1,	0,	1,	0,	0,	1,	0,	0,	-1,	1,	0,	0,	0,	0,	-3},
	{0,	0,	2,	0,	0,	0,	1,	0,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	-1,	0,	0,	0,	0,	-1},
	{0,	0,	1,	-1,	0,	0,	1,	0,	1,	-1,	0,	0,	1,	0,	1,	0,	0,	0,	1,	0,	1,	0,	0,	-1},
	{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
};

#endif
