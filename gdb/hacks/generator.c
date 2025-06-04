#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int e2k_linux_ptrace_offsets[] =
  {
    0x0,		/* "sizeof_struct" */

    /* %r0 . . . %r63 are not directly available via ptrace
       interface. */
    -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1,

    /* 65 */

    /* %b[0] . . . %b[127] are not directly available via
       ptrace interface. */
    -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1,

    /* 193 */

    /* %pred0 . . . %pred31 are not directly available
       via ptrace interface. */
    -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1,

    /* 225 */

    /* %g0 . . . %g31 as well as their extensions and
       tags (see below) are directly available via
       ptrace. */

    0x8,		/* "g0" */
    0x10,		/* "g1" */
    0x18,		/* "g2" */
    0x20,		/* "g3" */
    0x28,		/* "g4" */
    0x30,		/* "g5" */
    0x38,		/* "g6" */
    0x40,		/* "g7" */
    0x48,		/* "g8" */
    0x50,		/* "g9" */
    0x58,		/* "g10" */
    0x60,		/* "g11" */
    0x68,		/* "g12" */
    0x70,		/* "g13" */
    0x78,		/* "g14" */
    0x80,		/* "g15" */
    0x88,		/* "g16" */
    0x90,		/* "g17" */
    0x98,		/* "g18" */
    0xa0,		/* "g19" */
    0xa8,		/* "g20" */
    0xb0,		/* "g21" */
    0xb8,		/* "g22" */
    0xc0,		/* "g23" */
    0xc8,		/* "g24" */
    0xd0,		/* "g25" */
    0xd8,		/* "g26" */
    0xe0,		/* "g27" */
    0xe8,		/* "g28" */
    0xf0,		/* "g29" */
    0xf8,		/* "g30" */
    0x100,		/* "g31" */
    0x108,		/* "psr" */
    0x110,		/* "upsr" */
    0x118,		/* "oscud_lo" */
    0x120,		/* "oscud_hi" */
    0x128,		/* "osgd_lo" */
    0x130,		/* "osgd_hi" */
    0x138,		/* "osem" */
    0x140,		/* "osr0" */
    0x148,		/* "pfpfr" */
    0x150,		/* "fpcr" */
    0x158,		/* "fpsr" */
    0x160,		/* "usbr" */
    0x168,		/* "usd_lo" */
    0x170,		/* "usd_hi" */
    0x178,		/* "psp_lo" */
    0x180,		/* "psp_hi" */
    0x188,		/* "pshtp" */
    0x190,		/* "cr0_lo" */
    0x198,		/* "cr0_hi" */
    0x1a0,		/* "cr1_lo" */
    0x1a8,		/* "cr1_hi" */
    0x1b0,		/* "cwd" */
    0x1b8,		/* "pcsp_lo" */
    0x1c0,		/* "pcsp_hi" */
    0x1c8,		/* "pcshtp" */
    0x1d0,		/* "cud_lo" */
    0x1d8,		/* "cud_hi" */
    0x1e0,		/* "gd_lo" */
    0x1e8,		/* "gd_hi" */
    0x1f0,		/* "cs_lo" */
    0x1f8,		/* "cs_hi" */
    0x200,		/* "ds_lo" */
    0x208,		/* "ds_hi" */
    0x210,		/* "es_lo" */
    0x218,		/* "es_hi" */
    0x220,		/* "fs_lo" */
    0x228,		/* "fs_hi" */
    0x230,		/* "gs_lo" */
    0x238,		/* "gs_hi" */
    0x240,		/* "ss_lo" */
    0x248,		/* "ss_hi" */
    0x250,		/* "aad0_lo" */
    0x258,		/* "aad0_hi" */
    0x260,		/* "aad1_lo" */
    0x268,		/* "aad1_hi" */
    0x270,		/* "aad2_lo" */
    0x278,		/* "aad2_hi" */
    0x280,		/* "aad3_lo" */
    0x288,		/* "aad3_hi" */
    0x290,		/* "aad4_lo" */
    0x298,		/* "aad4_hi" */
    0x2a0,		/* "aad5_lo" */
    0x2a8,		/* "aad5_hi" */
    0x2b0,		/* "aad6_lo" */
    0x2b8,		/* "aad6_hi" */
    0x2c0,		/* "aad7_lo" */
    0x2c8,		/* "aad7_hi" */
    0x2d0,		/* "aad8_lo" */
    0x2d8,		/* "aad8_hi" */
    0x2e0,		/* "aad9_lo" */
    0x2e8,		/* "aad9_hi" */
    0x2f0,		/* "aad10_lo" */
    0x2f8,		/* "aad10_hi" */
    0x300,		/* "aad11_lo" */
    0x308,		/* "aad11_hi" */
    0x310,		/* "aad12_lo" */
    0x318,		/* "aad12_hi" */
    0x320,		/* "aad13_lo" */
    0x328,		/* "aad13_hi" */
    0x330,		/* "aad14_lo" */
    0x338,		/* "aad14_hi" */
    0x340,		/* "aad15_lo" */
    0x348,		/* "aad15_hi" */
    0x350,		/* "aad16_lo" */
    0x358,		/* "aad16_hi" */
    0x360,		/* "aad17_lo" */
    0x368,		/* "aad17_hi" */
    0x370,		/* "aad18_lo" */
    0x378,		/* "aad18_hi" */
    0x380,		/* "aad19_lo" */
    0x388,		/* "aad19_hi" */
    0x390,		/* "aad20_lo" */
    0x398,		/* "aad20_hi" */
    0x3a0,		/* "aad21_lo" */
    0x3a8,		/* "aad21_hi" */
    0x3b0,		/* "aad22_lo" */
    0x3b8,		/* "aad22_hi" */
    0x3c0,		/* "aad23_lo" */
    0x3c8,		/* "aad23_hi" */
    0x3d0,		/* "aad24_lo" */
    0x3d8,		/* "aad24_hi" */
    0x3e0,		/* "aad25_lo" */
    0x3e8,		/* "aad25_hi" */
    0x3f0,		/* "aad26_lo" */
    0x3f8,		/* "aad26_hi" */
    0x400,		/* "aad27_lo" */
    0x408,		/* "aad27_hi" */
    0x410,		/* "aad28_lo" */
    0x418,		/* "aad28_hi" */
    0x420,		/* "aad29_lo" */
    0x428,		/* "aad29_hi" */
    0x430,		/* "aad30_lo" */
    0x438,		/* "aad30_hi" */
    0x440,		/* "aad31_lo" */
    0x448,		/* "aad31_hi" */
    0x450,		/* "aaind0" */
    0x458,		/* "aaind1" */
    0x460,		/* "aaind2" */
    0x468,		/* "aaind3" */
    0x470,		/* "aaind4" */
    0x478,		/* "aaind5" */
    0x480,		/* "aaind6" */
    0x488,		/* "aaind7" */
    0x490,		/* "aaind8" */
    0x498,		/* "aaind9" */
    0x4a0,		/* "aaind10" */
    0x4a8,		/* "aaind11" */
    0x4b0,		/* "aaind12" */
    0x4b8,		/* "aaind13" */
    0x4c0,		/* "aaind14" */
    0x4c8,		/* "aaind15" */
    0x4d0,		/* "aaincr0" */
    0x4d8,		/* "aaincr1" */
    0x4e0,		/* "aaincr2" */
    0x4e8,		/* "aaincr3" */
    0x4f0,		/* "aaincr4" */
    0x4f8,		/* "aaincr5" */
    0x500,		/* "aaincr6" */
    0x508,		/* "aaincr7" */
    0x510,		/* "aaldi0" */
    0x518,		/* "aaldi1" */
    0x520,		/* "aaldi2" */
    0x528,		/* "aaldi3" */
    0x530,		/* "aaldi4" */
    0x538,		/* "aaldi5" */
    0x540,		/* "aaldi6" */
    0x548,		/* "aaldi7" */
    0x550,		/* "aaldi8" */
    0x558,		/* "aaldi9" */
    0x560,		/* "aaldi10" */
    0x568,		/* "aaldi11" */
    0x570,		/* "aaldi12" */
    0x578,		/* "aaldi13" */
    0x580,		/* "aaldi14" */
    0x588,		/* "aaldi15" */
    0x590,		/* "aaldi16" */
    0x598,		/* "aaldi17" */
    0x5a0,		/* "aaldi18" */
    0x5a8,		/* "aaldi19" */
    0x5b0,		/* "aaldi20" */
    0x5b8,		/* "aaldi21" */
    0x5c0,		/* "aaldi22" */
    0x5c8,		/* "aaldi23" */
    0x5d0,		/* "aaldi24" */
    0x5d8,		/* "aaldi25" */
    0x5e0,		/* "aaldi26" */
    0x5e8,		/* "aaldi27" */
    0x5f0,		/* "aaldi28" */
    0x5f8,		/* "aaldi29" */
    0x600,		/* "aaldi30" */
    0x608,		/* "aaldi31" */
    0x610,		/* "aaldi32" */
    0x618,		/* "aaldi33" */
    0x620,		/* "aaldi34" */
    0x628,		/* "aaldi35" */
    0x630,		/* "aaldi36" */
    0x638,		/* "aaldi37" */
    0x640,		/* "aaldi38" */
    0x648,		/* "aaldi39" */
    0x650,		/* "aaldi40" */
    0x658,		/* "aaldi41" */
    0x660,		/* "aaldi42" */
    0x668,		/* "aaldi43" */
    0x670,		/* "aaldi44" */
    0x678,		/* "aaldi45" */
    0x680,		/* "aaldi46" */
    0x688,		/* "aaldi47" */
    0x690,		/* "aaldi48" */
    0x698,		/* "aaldi49" */
    0x6a0,		/* "aaldi50" */
    0x6a8,		/* "aaldi51" */
    0x6b0,		/* "aaldi52" */
    0x6b8,		/* "aaldi53" */
    0x6c0,		/* "aaldi54" */
    0x6c8,		/* "aaldi55" */
    0x6d0,		/* "aaldi56" */
    0x6d8,		/* "aaldi57" */
    0x6e0,		/* "aaldi58" */
    0x6e8,		/* "aaldi59" */
    0x6f0,		/* "aaldi60" */
    0x6f8,		/* "aaldi61" */
    0x700,		/* "aaldi62" */
    0x708,		/* "aaldi63" */
    0x710,		/* "aaldv" */
    0x718,		/* "aalda0" */
    0x720,		/* "aalda1" */
    0x728,		/* "aalda2" */
    0x730,		/* "aalda3" */
    0x738,		/* "aalda4" */
    0x740,		/* "aalda5" */
    0x748,		/* "aalda6" */
    0x750,		/* "aalda7" */
    0x758,		/* "aalda8" */
    0x760,		/* "aalda9" */
    0x768,		/* "aalda10" */
    0x770,		/* "aalda11" */
    0x778,		/* "aalda12" */
    0x780,		/* "aalda13" */
    0x788,		/* "aalda14" */
    0x790,		/* "aalda15" */
    0x798,		/* "aalda16" */
    0x7a0,		/* "aalda17" */
    0x7a8,		/* "aalda18" */
    0x7b0,		/* "aalda19" */
    0x7b8,		/* "aalda20" */
    0x7c0,		/* "aalda21" */
    0x7c8,		/* "aalda22" */
    0x7d0,		/* "aalda23" */
    0x7d8,		/* "aalda24" */
    0x7e0,		/* "aalda25" */
    0x7e8,		/* "aalda26" */
    0x7f0,		/* "aalda27" */
    0x7f8,		/* "aalda28" */
    0x800,		/* "aalda29" */
    0x808,		/* "aalda30" */
    0x810,		/* "aalda31" */
    0x818,		/* "aalda32" */
    0x820,		/* "aalda33" */
    0x828,		/* "aalda34" */
    0x830,		/* "aalda35" */
    0x838,		/* "aalda36" */
    0x840,		/* "aalda37" */
    0x848,		/* "aalda38" */
    0x850,		/* "aalda39" */
    0x858,		/* "aalda40" */
    0x860,		/* "aalda41" */
    0x868,		/* "aalda42" */
    0x870,		/* "aalda43" */
    0x878,		/* "aalda44" */
    0x880,		/* "aalda45" */
    0x888,		/* "aalda46" */
    0x890,		/* "aalda47" */
    0x898,		/* "aalda48" */
    0x8a0,		/* "aalda49" */
    0x8a8,		/* "aalda50" */
    0x8b0,		/* "aalda51" */
    0x8b8,		/* "aalda52" */
    0x8c0,		/* "aalda53" */
    0x8c8,		/* "aalda54" */
    0x8d0,		/* "aalda55" */
    0x8d8,		/* "aalda56" */
    0x8e0,		/* "aalda57" */
    0x8e8,		/* "aalda58" */
    0x8f0,		/* "aalda59" */
    0x8f8,		/* "aalda60" */
    0x900,		/* "aalda61" */
    0x908,		/* "aalda62" */
    0x910,		/* "aalda63" */
    0x918,		/* "aaldm" */
    0x920,		/* "aasr" */
    0x928,		/* "aafstr" */
    0x930,		/* "aasti0" */
    0x938,		/* "aasti1" */
    0x940,		/* "aasti2" */
    0x948,		/* "aasti3" */
    0x950,		/* "aasti4" */
    0x958,		/* "aasti5" */
    0x960,		/* "aasti6" */
    0x968,		/* "aasti7" */
    0x970,		/* "aasti8" */
    0x978,		/* "aasti9" */
    0x980,		/* "aasti10" */
    0x988,		/* "aasti11" */
    0x990,		/* "aasti12" */
    0x998,		/* "aasti13" */
    0x9a0,		/* "aasti14" */
    0x9a8,		/* "aasti15" */
    0x9b0,		/* "clkr" */
    0x9b8,		/* "dibcr" */
    0x9c0,		/* "ddbcr" */
    0x9c8,		/* "dibar0" */
    0x9d0,		/* "dibar1" */
    0x9d8,		/* "dibar2" */
    0x9e0,		/* "dibar3" */
    0x9e8,		/* "ddbar0" */
    0x9f0,		/* "ddbar1" */
    0x9f8,		/* "ddbar2" */
    0xa00,		/* "ddbar3" */
    0xa08,		/* "dimcr" */
    0xa10,		/* "ddmcr" */
    0xa18,		/* "dimar0" */
    0xa20,		/* "dimar1" */
    0xa28,		/* "ddmar0" */
    0xa30,		/* "ddmar1" */
    0xa38,		/* "dibsr" */
    0xa40,		/* "ddbsr" */
    0xa48,		/* "dtcr" */
    0xa50,		/* "dtarf" */
    0xa58,		/* "dtart" */
    0xa60,		/* "wd" */
    0xa68,		/* "br" */
    0xa70,		/* "bgr" */
    0xa78,		/* "ip" */
    0xa80,		/* "nip" */
    0xa88,		/* "ctpr1" */
    0xa90,		/* "ctpr2" */
    0xa98,		/* "ctpr3" */
    0xaa0,		/* "eir" */
    0xaa8,		/* "tr" */
    0xab0,		/* "cutd" */
    0xab8,		/* "cuir" */
    0xac0,		/* "tsd" */
    0xac8,		/* "lsr" */
    0xad0,		/* "ilcr" */
    0xad8,		/* "sys_rval" */
    0xae0,		/* "sys_num" */
    0xae8,		/* "arg1" */
    0xaf0,		/* "arg2" */
    0xaf8,		/* "arg3" */
    0xb00,		/* "arg4" */
    0xb08,		/* "arg5" */
    0xb10,		/* "arg6" */
    0xb18,		/* "gtag0" */
    0xb19,		/* "gtag1" */
    0xb1a,		/* "gtag2" */
    0xb1b,		/* "gtag3" */
    0xb1c,		/* "gtag4" */
    0xb1d,		/* "gtag5" */
    0xb1e,		/* "gtag6" */
    0xb1f,		/* "gtag7" */
    0xb20,		/* "gtag8" */
    0xb21,		/* "gtag9" */
    0xb22,		/* "gtag10" */
    0xb23,		/* "gtag11" */
    0xb24,		/* "gtag12" */
    0xb25,		/* "gtag13" */
    0xb26,		/* "gtag14" */
    0xb27,		/* "gtag15" */
    0xb28,		/* "gtag16" */
    0xb29,		/* "gtag17" */
    0xb2a,		/* "gtag18" */
    0xb2b,		/* "gtag19" */
    0xb2c,		/* "gtag20" */
    0xb2d,		/* "gtag21" */
    0xb2e,		/* "gtag22" */
    0xb2f,		/* "gtag23" */
    0xb30,		/* "gtag24" */
    0xb31,		/* "gtag25" */
    0xb32,		/* "gtag26" */
    0xb33,		/* "gtag27" */
    0xb34,		/* "gtag28" */
    0xb35,		/* "gtag29" */
    0xb36,		/* "gtag30" */
    0xb37,		/* "gtag31" */
    0xb38,		/* "gext0" */
    0xb3a,		/* "gext1" */
    0xb3c,		/* "gext2" */
    0xb3e,		/* "gext3" */
    0xb40,		/* "gext4" */
    0xb42,		/* "gext5" */
    0xb44,		/* "gext6" */
    0xb46,		/* "gext7" */
    0xb48,		/* "gext8" */
    0xb4a,		/* "gext9" */
    0xb4c,		/* "gext10" */
    0xb4e,		/* "gext11" */
    0xb50,		/* "gext12" */
    0xb52,		/* "gext13" */
    0xb54,		/* "gext14" */
    0xb56,		/* "gext15" */
    0xb58,		/* "gext16" */
    0xb5a,		/* "gext17" */
    0xb5c,		/* "gext18" */
    0xb5e,		/* "gext19" */
    0xb60,		/* "gext20" */
    0xb62,		/* "gext21" */
    0xb64,		/* "gext22" */
    0xb66,		/* "gext23" */
    0xb68,		/* "gext24" */
    0xb6a,		/* "gext25" */
    0xb6c,		/* "gext26" */
    0xb6e,		/* "gext27" */
    0xb70,		/* "gext28" */
    0xb72,		/* "gext29" */
    0xb74,		/* "gext30" */
    0xb76,		/* "gext31" */
    0xb78,		/* "rpr_hi" */
    0xb80,		/* "rpr_lo" */
    0xb88,		/* "tir_lo0" */
    0xb90,		/* "tir_lo1" */
    0xb98,		/* "tir_lo2" */
    0xba0,		/* "tir_lo3" */
    0xba8,		/* "tir_lo4" */
    0xbb0,		/* "tir_lo5" */
    0xbb8,		/* "tir_lo6" */
    0xbc0,		/* "tir_lo7" */
    0xbc8,		/* "tir_lo8" */
    0xbd0,		/* "tir_lo9" */
    0xbd8,		/* "tir_lo10" */
    0xbe0,		/* "tir_lo11" */
    0xbe8,		/* "tir_lo12" */
    0xbf0,		/* "tir_lo13" */
    0xbf8,		/* "tir_lo14" */
    0xc00,		/* "tir_lo15" */
    0xc08,		/* "tir_lo16" */
    0xc10,		/* "tir_lo17" */
    0xc18,		/* "tir_lo18" */
    0xc20,		/* "tir_0_hi" */
    0xc28,		/* "tir_1_hi" */
    0xc30,		/* "tir_2_hi" */
    0xc38,		/* "tir_3_hi" */
    0xc40,		/* "tir_4_hi" */
    0xc48,		/* "tir_5_hi" */
    0xc50,		/* "tir_6_hi" */
    0xc58,		/* "tir_7_hi" */
    0xc60,		/* "tir_8_hi" */
    0xc68,		/* "tir_9_hi" */
    0xc70,		/* "tir_10_hi" */
    0xc78,		/* "tir_11_hi" */
    0xc80,		/* "tir_12_hi" */
    0xc88,		/* "tir_13_hi" */
    0xc90,		/* "tir_14_hi" */
    0xc98,		/* "tir_15_hi" */
    0xca0,		/* "tir_16_hi" */
    0xca8,		/* "tir_17_hi" */
    0xcb0,		/* "tir_18_hi" */
    0xcb8,		/* "trap_cell_addr_0" */
    0xcc0,		/* "trap_cell_addr_1" */
    0xcc8,		/* "trap_cell_addr_2" */
    0xcd0,		/* "trap_cell_addr_3" */
    0xcd8,		/* "trap_cell_addr_4" */
    0xce0,		/* "trap_cell_addr_5" */
    0xce8,		/* "trap_cell_addr_6" */
    0xcf0,		/* "trap_cell_addr_7" */
    0xcf8,		/* "trap_cell_addr_8" */
    0xd00,		/* "trap_cell_addr_9" */
    0xd08,		/* "trap_cell_val_0" */
    0xd10,		/* "trap_cell_val_1" */
    0xd18,		/* "trap_cell_val_2" */
    0xd20,		/* "trap_cell_val_3" */
    0xd28,		/* "trap_cell_val_4" */
    0xd30,		/* "trap_cell_val_5" */
    0xd38,		/* "trap_cell_val_6" */
    0xd40,		/* "trap_cell_val_7" */
    0xd48,		/* "trap_cell_val_8" */
    0xd50,		/* "trap_cell_val_9" */
    0xd58,		/* "trap_cell_tag_0" */
    0xd59,		/* "trap_cell_tag_1" */
    0xd5a,		/* "trap_cell_tag_2" */
    0xd5b,		/* "trap_cell_tag_3" */
    0xd5c,		/* "trap_cell_tag_4" */
    0xd5d,		/* "trap_cell_tag_5" */
    0xd5e,		/* "trap_cell_tag_6" */
    0xd5f,		/* "trap_cell_tag_7" */
    0xd60,		/* "trap_cell_tag_8" */
    0xd61,		/* "trap_cell_tag_9" */
    0xd62,              /* "dummy_1" */
    0xd63,              /* "dummy_2" */
    0xd64,              /* "dummy_3" */
    0xd65,              /* "dummy_4" */
    0xd66,              /* "dummy_5" */
    0xd67,              /* "dummy_6" */
    0xd68,		/* "trap_cell_info_0" */
    0xd70,		/* "trap_cell_info_1" */
    0xd78,		/* "trap_cell_info_2" */
    0xd80,		/* "trap_cell_info_3" */
    0xd88,		/* "trap_cell_info_4" */
    0xd90,		/* "trap_cell_info_5" */
    0xd98,		/* "trap_cell_info_6" */
    0xda0,		/* "trap_cell_info_7" */
    0xda8,		/* "trap_cell_info_8" */
    0xdb0,		/* "trap_cell_info_9" */
    0xdb8,		/* "dam_0" */
    0xdc0,		/* "dam_1" */
    0xdc8,		/* "dam_2" */
    0xdd0,		/* "dam_3" */
    0xdd8,		/* "dam_4" */
    0xde0,		/* "dam_5" */
    0xde8,		/* "dam_6" */
    0xdf0,		/* "dam_7" */
    0xdf8,		/* "dam_8" */
    0xe00,		/* "dam_9" */
    0xe08,		/* "dam_10" */
    0xe10,		/* "dam_11" */
    0xe18,		/* "dam_12" */
    0xe20,		/* "dam_13" */
    0xe28,		/* "dam_14" */
    0xe30,		/* "dam_15" */
    0xe38,		/* "dam_16" */
    0xe40,		/* "dam_17" */
    0xe48,		/* "dam_18" */
    0xe50,		/* "dam_19" */
    0xe58,		/* "dam_20" */
    0xe60,		/* "dam_21" */
    0xe68,		/* "dam_22" */
    0xe70,		/* "dam_23" */
    0xe78,		/* "dam_24" */
    0xe80,		/* "dam_25" */
    0xe88,		/* "dam_26" */
    0xe90,		/* "dam_27" */
    0xe98,		/* "dam_28" */
    0xea0,		/* "dam_29" */
    0xea8,		/* "dam_30" */
    0xeb0,		/* "dam_31" */
    0xeb8,		/* "sbbp_0" */
    0xec0,		/* "sbbp_1" */
    0xec8,		/* "sbbp_2" */
    0xed0,		/* "sbbp_3" */
    0xed8,		/* "sbbp_4" */
    0xee0,		/* "sbbp_5" */
    0xee8,		/* "sbbp_6" */
    0xef0,		/* "sbbp_7" */
    0xef8,		/* "sbbp_8" */
    0xf00,		/* "sbbp_9" */
    0xf08,		/* "sbbp_10" */
    0xf10,		/* "sbbp_11" */
    0xf18,		/* "sbbp_12" */
    0xf20,		/* "sbbp_13" */
    0xf28,		/* "sbbp_14" */
    0xf30,		/* "sbbp_15" */
    0xf38,		/* "sbbp_16" */
    0xf40,		/* "sbbp_17" */
    0xf48,		/* "sbbp_18" */
    0xf50,		/* "sbbp_19" */
    0xf58,		/* "sbbp_20" */
    0xf60,		/* "sbbp_21" */
    0xf68,		/* "sbbp_22" */
    0xf70,		/* "sbbp_23" */
    0xf78,		/* "sbbp_24" */
    0xf80,		/* "sbbp_25" */
    0xf88,		/* "sbbp_26" */
    0xf90,		/* "sbbp_27" */
    0xf98,		/* "sbbp_28" */
    0xfa0,		/* "sbbp_29" */
    0xfa8,		/* "sbbp_30" */
    0xfb0,		/* "sbbp_31" */
    0xfb8,		/* "mlt_0" */
    0xfd0,		/* "mlt_1" */
    0xfe8,		/* "mlt_2" */
    0x1000,		/* "mlt_3" */
    0x1018,		/* "mlt_4" */
    0x1030,		/* "mlt_5" */
    0x1048,		/* "mlt_6" */
    0x1060,		/* "mlt_7" */
    0x1078,		/* "mlt_8" */
    0x1090,		/* "mlt_9" */
    0x10a8,		/* "mlt_10" */
    0x10c0,		/* "mlt_11" */
    0x10d8,		/* "mlt_12" */
    0x10f0,		/* "mlt_13" */
    0x1108,		/* "mlt_14" */
    0x1120,		/* "mlt_15" */

    /* 809 - 821 inclusively: these are 13 fake registers required because of
       their types.  */
    -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1,

    /* 822 - 823  */
    0x168,              /* "pusd_lo"  */
    0x170,              /* "pusd_hi"  */

    /* 824 - 825: `_signed_tagged{32,64}' registers are needed because of their
       types.  */
    -1, -1,

    /* 826: `E2K_PCSP_BASE' register is put at the end of the buffer just after
       its GREGS part managed via `ptrace ()'. Taking into account that
       currently `sizeof (gregs) == 8 * 551 == 0x1138' (see `sys/ucontext.h'),
       one obtains . . .  */
    0x1138,


    /* 827: E2K_PCSP_OFFSET  */
    0x1140,

    /* 828 - 955: E2K_PARAM_{0, . . ., 127}  */
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,

    /* 956: `_fake_pf' register is needed because of its type.  */
    -1,

    /* 957: `_tagged128' register is needed because of its type.  */
    -1,
  };


static char *e2k_register_names[] =
  {

    /* Because of our bogus interface with ptrace place
       for "sizeof_struct" register should be reserved.
       Otherwise the sizeof `g'-packet received from
       gdbserver may appear to be too large in comparence
       with what we expect. */

    /* 0: SIZEOF_REGNUM  */
    "_sizeof",


    /* Raw registers */

    /* 1 */

    /* Here we used to have %r0 - %r63. */
    "_r0", "_r1", "_r2", "_r3", "_r4", "_r5", "_r6", "_r7",
    "_r8", "_r9", "_r10", "_r11", "_r12", "_r13", "_r14", "_r15",
    "_r16", "_r17", "_r18", "_r19", "_r20", "_r21", "_r22", "_r23",
    "_r24", "_r25", "_r26", "_r27", "_r28", "_r29", "_r30", "_r31",
    "_r32", "_r33", "_r34", "_r35", "_r36", "_r37", "_r38", "_r39",
    "_r40", "_r41", "_r42", "_r43", "_r44", "_r45", "_r46", "_r47",
    "_r48", "_r49", "_r50", "_r51", "_r52", "_r53", "_r54", "_r55",
    "_r56", "_r57", "_r58", "_r59", "_r60", "_r61", "_r62", "_r63",

    /* 65 */

    /* Here we used to have %b0 - %b127 */
    "_b0", "_b1", "_b2", "_b3", "_b4", "_b5", "_b6", "_b7",
    "_b8", "_b9", "_b10", "_b11", "_b12", "_b13", "_b14", "_b15",
    "_b16", "_b17", "_b18", "_b19", "_b20", "_b21", "_b22", "_b23",
    "_b24", "_b25", "_b26", "_b27", "_b28", "_b29", "_b30", "_b31",
    "_b32", "_b33", "_b34", "_b35", "_b36", "_b37", "_b38", "_b39",
    "_b40", "_b41", "_b42", "_b43", "_b44", "_b45", "_b46", "_b47",
    "_b48", "_b49", "_b50", "_b51", "_b52", "_b53", "_b54", "_b55",
    "_b56", "_b57", "_b58", "_b59", "_b60", "_b61", "_b62", "_b63",
    "_b64", "_b65", "_b66", "_b67", "_b68", "_b69", "_b70", "_b71",
    "_b72", "_b73", "_b74", "_b75", "_b76", "_b77", "_b78", "_b79",
    "_b80", "_b81", "_b82", "_b83", "_b84", "_b85", "_b86", "_b87",
    "_b88", "_b89", "_b90", "_b91", "_b92", "_b93", "_b94", "_b95",
    "_b96", "_b97", "_b98", "_b99", "_b100", "_b101", "_b102", "_b103",
    "_b104", "_b105", "_b106", "_b107", "_b108", "_b109", "_b110", "_b111",
    "_b112", "_b113", "_b114", "_b115", "_b116", "_b117", "_b118", "_b119",
    "_b120", "_b121", "_b122", "_b123", "_b124", "_b125", "_b126", "_b127",



    /* 193 */

    /* Here we used to have %pred0 - %pred31 */
    "_pred0", "_pred1", "_pred2", "_pred3",
    "_pred4", "_pred5", "_pred6", "_pred7",
    "_pred8", "_pred9", "_pred10", "_pred11",
    "_pred12", "_pred13", "_pred14", "_pred15",
    "_pred16", "_pred17", "_pred18", "_pred19",
    "_pred20", "_pred21", "_pred22", "_pred23",
    "_pred24", "_pred25", "_pred26", "_pred27",
    "_pred28", "_pred29", "_pred30", "_pred31",

    /* 225 */

    /* Use cooked `VG*_REGNUM's to fetch the values
       of %g registers since they have the appropriate
       (tagged) type. Raw `E2K_G*_REGNUM's are not tagged. */
    "_g0", "_g1", "_g2", "_g3",
    "_g4", "_g5", "_g6", "_g7",
    "_g8", "_g9", "_g10", "_g11",
    "_g12", "_g13", "_g14", "_g15",
    "_g16", "_g17", "_g18", "_g19",
    "_g20", "_g21", "_g22", "_g23",
    "_g24", "_g25", "_g26", "_g27",
    "_g28", "_g29", "_g30", "_g31",


    /* 257 */

    "psr",
    "upsr",
    "oscud_lo",
    "oscud_hi",
    "osgd_lo",
    "osgd_hi",
    "osem",
    "osr0",
    "pfpfr",
    "fpcr",
    "fpsr",
    "usbr",
    "usd_lo",
    "usd_hi",

    /*271 */


    /* psp_lo and psp_hi are considered to be frame-
       specific (and therefore pseudo registers) now
       though probably only psp_hi should be. */
    "_psp_lo", "_psp_hi",

    /* 273 */

    "pshtp",

    /* 274 */

    /* cr0_{lo,hi} and cr1_{lo,hi} used to come here */
    "_cr0_lo", "_cr0_hi", "_cr1_lo", "_cr1_hi",

    /* 278 */

    "cwd",

    /* 279 */

    /* pcsp_{lo,hi} are treated in the same way as
       psp_{lo,hi}. */
    "_pcsp_lo", "_pcsp_hi",

    /* 281 */

    "pcshtp",
    "cud_lo",
    "cud_hi",

    /* 284 */

    "gd_lo",
    "gd_hi",
    "cs_lo",
    "cs_hi",
    "ds_lo",
    "ds_hi",
    "es_lo",
    "es_hi",
    "fs_lo",
    "fs_hi",
    "gs_lo",
    "gs_hi",
    "ss_lo",
    "ss_hi",
    "aad0_lo",
    "aad0_hi",
    "aad1_lo",
    "aad1_hi",
    "aad2_lo",
    "aad2_hi",
    "aad3_lo",
    "aad3_hi",
    "aad4_lo",
    "aad4_hi",
    "aad5_lo",
    "aad5_hi",
    "aad6_lo",
    "aad6_hi",
    "aad7_lo",
    "aad7_hi",
    "aad8_lo",
    "aad8_hi",
    "aad9_lo",
    "aad9_hi",
    "aad10_lo",
    "aad10_hi",
    "aad11_lo",
    "aad11_hi",
    "aad12_lo",
    "aad12_hi",
    "aad13_lo",
    "aad13_hi",
    "aad14_lo",
    "aad14_hi",
    "aad15_lo",
    "aad15_hi",
    "aad16_lo",
    "aad16_hi",
    "aad17_lo",
    "aad17_hi",
    "aad18_lo",
    "aad18_hi",
    "aad19_lo",
    "aad19_hi",
    "aad20_lo",
    "aad20_hi",
    "aad21_lo",
    "aad21_hi",
    "aad22_lo",
    "aad22_hi",
    "aad23_lo",
    "aad23_hi",
    "aad24_lo",
    "aad24_hi",
    "aad25_lo",
    "aad25_hi",
    "aad26_lo",
    "aad26_hi",
    "aad27_lo",
    "aad27_hi",
    "aad28_lo",
    "aad28_hi",
    "aad29_lo",
    "aad29_hi",
    "aad30_lo",
    "aad30_hi",
    "aad31_lo",
    "aad31_hi",
    "aaind0",
    "aaind1",
    "aaind2",
    "aaind3",
    "aaind4",
    "aaind5",
    "aaind6",
    "aaind7",
    "aaind8",
    "aaind9",
    "aaind10",
    "aaind11",
    "aaind12",
    "aaind13",
    "aaind14",
    "aaind15",
    "aaincr0",
    "aaincr1",
    "aaincr2",
    "aaincr3",
    "aaincr4",
    "aaincr5",
    "aaincr6",
    "aaincr7",
    "aaldi0",
    "aaldi1",
    "aaldi2",
    "aaldi3",
    "aaldi4",
    "aaldi5",
    "aaldi6",
    "aaldi7",
    "aaldi8",
    "aaldi9",
    "aaldi10",
    "aaldi11",
    "aaldi12",
    "aaldi13",
    "aaldi14",
    "aaldi15",
    "aaldi16",
    "aaldi17",
    "aaldi18",
    "aaldi19",
    "aaldi20",
    "aaldi21",
    "aaldi22",
    "aaldi23",
    "aaldi24",
    "aaldi25",
    "aaldi26",
    "aaldi27",
    "aaldi28",
    "aaldi29",
    "aaldi30",
    "aaldi31",
    "aaldi32",
    "aaldi33",
    "aaldi34",
    "aaldi35",
    "aaldi36",
    "aaldi37",
    "aaldi38",
    "aaldi39",
    "aaldi40",
    "aaldi41",
    "aaldi42",
    "aaldi43",
    "aaldi44",
    "aaldi45",
    "aaldi46",
    "aaldi47",
    "aaldi48",
    "aaldi49",
    "aaldi50",
    "aaldi51",
    "aaldi52",
    "aaldi53",
    "aaldi54",
    "aaldi55",
    "aaldi56",
    "aaldi57",
    "aaldi58",
    "aaldi59",
    "aaldi60",
    "aaldi61",
    "aaldi62",
    "aaldi63",
    "aaldv",
    "aalda0",
    "aalda1",
    "aalda2",
    "aalda3",
    "aalda4",
    "aalda5",
    "aalda6",
    "aalda7",
    "aalda8",
    "aalda9",
    "aalda10",
    "aalda11",
    "aalda12",
    "aalda13",
    "aalda14",
    "aalda15",
    "aalda16",
    "aalda17",
    "aalda18",
    "aalda19",
    "aalda20",
    "aalda21",
    "aalda22",
    "aalda23",
    "aalda24",
    "aalda25",
    "aalda26",
    "aalda27",
    "aalda28",
    "aalda29",
    "aalda30",
    "aalda31",
    "aalda32",
    "aalda33",
    "aalda34",
    "aalda35",
    "aalda36",
    "aalda37",
    "aalda38",
    "aalda39",
    "aalda40",
    "aalda41",
    "aalda42",
    "aalda43",
    "aalda44",
    "aalda45",
    "aalda46",
    "aalda47",
    "aalda48",
    "aalda49",
    "aalda50",
    "aalda51",
    "aalda52",
    "aalda53",
    "aalda54",
    "aalda55",
    "aalda56",
    "aalda57",
    "aalda58",
    "aalda59",
    "aalda60",
    "aalda61",
    "aalda62",
    "aalda63",
    "aaldm",
    "aasr",
    "aafstr",
    "aasti0",
    "aasti1",
    "aasti2",
    "aasti3",
    "aasti4",
    "aasti5",
    "aasti6",
    "aasti7",
    "aasti8",
    "aasti9",
    "aasti10",
    "aasti11",
    "aasti12",
    "aasti13",
    "aasti14",
    "aasti15",
    "clkr",
    "dibcr",
    "ddbcr",
    "dibar0",
    "dibar1",
    "dibar2",
    "dibar3",
    "ddbar0",
    "ddbar1",
    "ddbar2",
    "ddbar3",
    "dimcr",
    "ddmcr",
    "dimar0",
    "dimar1",
    "ddmar0",
    "ddmar1",
    "dibsr",
    "ddbsr",
    "dtcr",
    "dtarf",
    "dtart",

    /* 556 */

    /* WD and BR are also pseudo registers now. */
    "_wd", "_br",

    /* 558 */

    "bgr",
    /* I don't know what E2K_IP_REGNUM (as well as
       E2K_NIP_REGNUM) is needed for not only in GDB
       but in hardware as well. A user usually believes
       that IP is an alias of PC (see Bug #23612). */
    "_ip",
    "nip",

    /* 561 */

    "ctpr1", "ctpr2", "ctpr3",

    /* 564 */

    "eir",
    "tr",
    "cutd",
    "cuir",
    "tsd",
    "lsr",
    "ilcr",

    /* 571 */

    /* These 8 positions are reserved for a syscall return
       value, its number and params. */
    "_sys_rval", "_sys_rnum", "_arg1", "_arg2",
    "_arg3", "_arg4", "_arg5", "_arg6",

    /* 579 */

    /* E2K_GTAG0_REGNUM . . . E2K_GTAG31_REGNUM */
    "_gtag0", "_gtag1", "_gtag2", "_gtag3",
    "_gtag4", "_gtag5", "_gtag6", "_gtag7",
    "_gtag8", "_gtag9", "_gtag10", "_gtag11",
    "_gtag12", "_gtag13", "_gtag14", "_gtag15",
    "_gtag16", "_gtag17", "_gtag18", "_gtag19",
    "_gtag20", "_gtag21", "_gtag22", "_gtag23",
    "_gtag24", "_gtag25", "_gtag26", "_gtag27",
    "_gtag28", "_gtag29", "_gtag30", "_gtag31",


    /* 611 */

    /* E2K_GEXT0_REGNUM . . . E2K_GEXT31_REGNUM */
    "_gext0", "_gext1", "_gext2", "_gext3",
    "_gext4", "_gext5", "_gext6", "_gext7",
    "_gext8", "_gext9", "_gext10", "_gext11",
    "_gext12", "_gext13", "_gext14", "_gext15",
    "_gext16", "_gext17", "_gext18", "_gext19",
    "_gext20", "_gext21", "_gext22", "_gext23",
    "_gext24", "_gext25", "_gext26", "_gext27",
    "_gext28", "_gext29", "_gext30", "_gext31",


    /* 643 */

    "rpr_hi",
    "rpr_lo",
    "tir_0_lo",
    "tir_1_lo",
    "tir_2_lo",
    "tir_3_lo",
    "tir_4_lo",
    "tir_5_lo",
    "tir_6_lo",
    "tir_7_lo",
    "tir_8_lo",
    "tir_9_lo",
    "tir_10_lo",
    "tir_11_lo",
    "tir_12_lo",
    "tir_13_lo",
    "tir_14_lo",
    "tir_15_lo",
    "tir_16_lo",
    "tir_17_lo",
    "tir_18_lo",
    "tir_0_hi",
    "tir_1_hi",
    "tir_2_hi",
    "tir_3_hi",
    "tir_4_hi",
    "tir_5_hi",
    "tir_6_hi",
    "tir_7_hi",
    "tir_8_hi",
    "tir_9_hi",
    "tir_10_hi",
    "tir_11_hi",
    "tir_12_hi",
    "tir_13_hi",
    "tir_14_hi",
    "tir_15_hi",
    "tir_16_hi",
    "tir_17_hi",
    "tir_18_hi",
    "trap_cell_addr_0",
    "trap_cell_addr_1",
    "trap_cell_addr_2",
    "trap_cell_addr_3",
    "trap_cell_addr_4",
    "trap_cell_addr_5",
    "trap_cell_addr_6",
    "trap_cell_addr_7",
    "trap_cell_addr_8",
    "trap_cell_addr_9",
    "trap_cell_val_0",
    "trap_cell_val_1",
    "trap_cell_val_2",
    "trap_cell_val_3",
    "trap_cell_val_4",
    "trap_cell_val_5",
    "trap_cell_val_6",
    "trap_cell_val_7",
    "trap_cell_val_8",
    "trap_cell_val_9",

    /* 703 */

    "trap_cell_tag_0",
    "trap_cell_tag_1",
    "trap_cell_tag_2",
    "trap_cell_tag_3",
    "trap_cell_tag_4",
    "trap_cell_tag_5",
    "trap_cell_tag_6",
    "trap_cell_tag_7",
    "trap_cell_tag_8",
    "trap_cell_tag_9",

    /* 713 */
    /* %dummy_1 - %dummy_6  required for proper alignment. */
    "_dummy_1",
    "_dummy_2",
    "_dummy_3",
    "_dummy_4",
    "_dummy_5",
    "_dummy_6",

    /* 719 */

    "trap_cell_info_0",
    "trap_cell_info_1",
    "trap_cell_info_2",
    "trap_cell_info_3",
    "trap_cell_info_4",
    "trap_cell_info_5",
    "trap_cell_info_6",
    "trap_cell_info_7",
    "trap_cell_info_8",
    "trap_cell_info_9",
    "dam_0",
    "dam_1",
    "dam_2",
    "dam_3",
    "dam_4",
    "dam_5",
    "dam_6",
    "dam_7",
    "dam_8",
    "dam_9",
    "dam_10",
    "dam_11",
    "dam_12",
    "dam_13",
    "dam_14",
    "dam_15",
    "dam_16",
    "dam_17",
    "dam_18",
    "dam_19",
    "dam_20",
    "dam_21",
    "dam_22",
    "dam_23",
    "dam_24",
    "dam_25",
    "dam_26",
    "dam_27",
    "dam_28",
    "dam_29",
    "dam_30",
    "dam_31",
    "sbbp_0",
    "sbbp_1",
    "sbbp_2",
    "sbbp_3",
    "sbbp_4",
    "sbbp_5",
    "sbbp_6",
    "sbbp_7",
    "sbbp_8",
    "sbbp_9",
    "sbbp_10",
    "sbbp_11",
    "sbbp_12",
    "sbbp_13",
    "sbbp_14",
    "sbbp_15",
    "sbbp_16",
    "sbbp_17",
    "sbbp_18",
    "sbbp_19",
    "sbbp_20",
    "sbbp_21",
    "sbbp_22",
    "sbbp_23",
    "sbbp_24",
    "sbbp_25",
    "sbbp_26",
    "sbbp_27",
    "sbbp_28",
    "sbbp_29",
    "sbbp_30",
    "sbbp_31",
    "mlt_0",
    "mlt_1",
    "mlt_2",
    "mlt_3",
    "mlt_4",
    "mlt_5",
    "mlt_6",
    "mlt_7",
    "mlt_8",
    "mlt_9",
    "mlt_10",
    "mlt_11",
    "mlt_12",
    "mlt_13",
    "mlt_14",
    "mlt_15",

    /* Fake registers required because of their types  */
    /* 809  */

    "_hs", "_alf2", "_c1f1", "_cs0_dummy", "_cs1_setwd", "_cs1_call",
    "_lts0_setwd", "_ss", "_ctpr_rwp", "_tagged32", "_tagged80",
    "_cut_zero", "_cut_two",

    /* 822  */
    "pusd_lo", "pusd_hi",

    /* 824  */
    "_signed_tagged32", "_signed_tagged64",

    /* 826  */
    "pcsp_base",


    /* 827  */
    "_pcsp_offset",

    /* 828 - 955  */
    "_param_000", "_param_001", "_param_002", "_param_003",
    "_param_004", "_param_005", "_param_006", "_param_007",
    "_param_008", "_param_009", "_param_010", "_param_011",
    "_param_012", "_param_013", "_param_014", "_param_015",
    "_param_016", "_param_017", "_param_018", "_param_019",
    "_param_020", "_param_021", "_param_022", "_param_023",
    "_param_024", "_param_025", "_param_026", "_param_027",
    "_param_028", "_param_029", "_param_030", "_param_031",
    "_param_032", "_param_033", "_param_034", "_param_035",
    "_param_036", "_param_037", "_param_038", "_param_039",
    "_param_040", "_param_041", "_param_042", "_param_043",
    "_param_044", "_param_045", "_param_046", "_param_047",
    "_param_048", "_param_049", "_param_050", "_param_051",
    "_param_052", "_param_053", "_param_054", "_param_055",
    "_param_056", "_param_057", "_param_058", "_param_059",
    "_param_060", "_param_061", "_param_062", "_param_063",
    "_param_064", "_param_065", "_param_066", "_param_067",
    "_param_068", "_param_069", "_param_070", "_param_071",
    "_param_072", "_param_073", "_param_074", "_param_075",
    "_param_076", "_param_077", "_param_078", "_param_079",
    "_param_080", "_param_081", "_param_082", "_param_083",
    "_param_084", "_param_085", "_param_086", "_param_087",
    "_param_088", "_param_089", "_param_090", "_param_091",
    "_param_092", "_param_093", "_param_094", "_param_095",
    "_param_096", "_param_097", "_param_098", "_param_099",
    "_param_100", "_param_101", "_param_102", "_param_103",
    "_param_104", "_param_105", "_param_106", "_param_107",
    "_param_108", "_param_109", "_param_110", "_param_111",
    "_param_112", "_param_113", "_param_114", "_param_115",
    "_param_116", "_param_117", "_param_118", "_param_119",
    "_param_120", "_param_121", "_param_122", "_param_123",
    "_param_124", "_param_125", "_param_126", "_param_127",


    /* 956  */
    "_fake_pf",

    /* 957  */
    "_tagged128",


    /* Cooked ones */

    /* 958  */

    /* These ones may be explicitly specified by the
       user. */

    "r0",  "r1",  "r2",  "r3",  "r4",  "r5",  "r6",  "r7",
    "r8",  "r9",  "r10", "r11", "r12", "r13", "r14", "r15",
    "r16", "r17", "r18", "r19", "r20", "r21", "r22", "r23",
    "r24", "r25", "r26", "r27", "r28", "r29", "r30", "r31",
    "r32", "r33", "r34", "r35", "r36", "r37", "r38", "r39",
    "r40", "r41", "r42", "r43", "r44", "r45", "r46", "r47",
    "r48", "r49", "r50", "r51", "r52", "r53", "r54", "r55",
    "r56", "r57", "r58", "r59", "r60", "r61", "r62", "r63",

    /* while %r64 - %r223 may not. */

    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",

    /* 1182  */

    "b0",   "b1",   "b2",   "b3",
    "b4",   "b5",   "b6",   "b7",
    "b8",   "b9",   "b10",  "b11",
    "b12",  "b13",  "b14",  "b15",
    "b16",  "b17",  "b18",  "b19",
    "b20",  "b21",  "b22",  "b23",
    "b24",  "b25",  "b26",  "b27",
    "b28",  "b29",  "b30",  "b31",
    "b32",  "b33",  "b34",  "b35",
    "b36",  "b37",  "b38",  "b39",
    "b40",  "b41",  "b42",  "b43",
    "b44",  "b45",  "b46",  "b47",
    "b48",  "b49",  "b50",  "b51",
    "b52",  "b53",  "b54",  "b55",
    "b56",  "b57",  "b58",  "b59",
    "b60",  "b61",  "b62",  "b63",
    "b64",  "b65",  "b66",  "b67",
    "b68",  "b69",  "b70",  "b71",
    "b72",  "b73",  "b74",  "b75",
    "b76",  "b77",  "b78",  "b79",
    "b80",  "b81",  "b82",  "b83",
    "b84",  "b85",  "b86",  "b87",
    "b88",  "b89",  "b90",  "b91",
    "b92",  "b93",  "b94",  "b95",
    "b96",  "b97",  "b98",  "b99",
    "b100", "b101", "b102", "b103",
    "b104", "b105", "b106", "b107",
    "b108", "b109", "b110", "b111",
    "b112", "b113", "b114", "b115",
    "b116", "b117", "b118", "b119",
    "b120", "b121", "b122", "b123",
    "b124", "b125", "b126", "b127",

    /* 1310  */

    "pred0",  "pred1",  "pred2",  "pred3",
    "pred4",  "pred5",  "pred6",  "pred7",
    "pred8",  "pred9",  "pred10", "pred11",
    "pred12", "pred13", "pred14", "pred15",
    "pred16", "pred17", "pred18", "pred19",
    "pred20", "pred21", "pred22", "pred23",
    "pred24", "pred25", "pred26", "pred27",
    "pred28", "pred29", "pred30", "pred31",

    /* 1342  */

    "psp_lo", "psp_hi",

    /* 1344  */

    "cr0_lo", "cr0_hi", "cr1_lo", "cr1_hi",

    /* 1348  */

    "pcsp_lo", "pcsp_hi",

    /* 1350  */

    "wd", "br",

    /* 1352  */

    "psp",
    "pcsp",
    "pc",

    /* 1355  */

    "g0",  "g1",  "g2",  "g3",
    "g4",  "g5",  "g6",  "g7",
    "g8",  "g9",  "g10", "g11",
    "g12", "g13", "g14", "g15",
    "g16", "g17", "g18", "g19",
    "g20", "g21", "g22", "g23",
    "g24", "g25", "g26", "g27",
    "g28", "g29", "g30", "g31",

    /* 1387  */
    /* %cr0_lo for the NEXT frame, used when accessing
       predicate values for the CURRENT frame. User
       shouldn't access it directly. */
    "",

    /* 1388 - 1390  */
    /* VCR0_HI_NEXT_REGNUM - VCR1_HI_NEXT_REGNUM as well as
       VCR0_LO_NEXT_REGNUM are used when saving (restoring)
       %cr{0,1}.{lo,hi} for the prior-to-sentinel frame
       before (after) the `call' command. FIXME: are they
       actually needed? Probably in this case it makes sense
       to modify E2K_CR{0,1}_{LO,HI}_REGNUM's directly. */
    "", "", "",

    /* 1391  */

    /* A stack pointer for the current frame */
    "sp",

    /* 1392  */

    /* A frame pointer for the current frame */
    "fp",

    /* 1393  */

    /* Alias of `%pc' called `%ip' (see Bug #23612) */
    "ip",

    /* 1394 - 1617  */

    /* These ones may be explicitly specified by the
       user. */

    "xr0",  "xr1",  "xr2",  "xr3",  "xr4",  "xr5",  "xr6",  "xr7",
    "xr8",  "xr9",  "xr10", "xr11", "xr12", "xr13", "xr14", "xr15",
    "xr16", "xr17", "xr18", "xr19", "xr20", "xr21", "xr22", "xr23",
    "xr24", "xr25", "xr26", "xr27", "xr28", "xr29", "xr30", "xr31",
    "xr32", "xr33", "xr34", "xr35", "xr36", "xr37", "xr38", "xr39",
    "xr40", "xr41", "xr42", "xr43", "xr44", "xr45", "xr46", "xr47",
    "xr48", "xr49", "xr50", "xr51", "xr52", "xr53", "xr54", "xr55",
    "xr56", "xr57", "xr58", "xr59", "xr60", "xr61", "xr62", "xr63",

    /* while %xr64 - %xr223 may not. */

    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",

    /* 1618 - 1745  */

    "xb0",   "xb1",   "xb2",   "xb3",
    "xb4",   "xb5",   "xb6",   "xb7",
    "xb8",   "xb9",   "xb10",  "xb11",
    "xb12",  "xb13",  "xb14",  "xb15",
    "xb16",  "xb17",  "xb18",  "xb19",
    "xb20",  "xb21",  "xb22",  "xb23",
    "xb24",  "xb25",  "xb26",  "xb27",
    "xb28",  "xb29",  "xb30",  "xb31",
    "xb32",  "xb33",  "xb34",  "xb35",
    "xb36",  "xb37",  "xb38",  "xb39",
    "xb40",  "xb41",  "xb42",  "xb43",
    "xb44",  "xb45",  "xb46",  "xb47",
    "xb48",  "xb49",  "xb50",  "xb51",
    "xb52",  "xb53",  "xb54",  "xb55",
    "xb56",  "xb57",  "xb58",  "xb59",
    "xb60",  "xb61",  "xb62",  "xb63",
    "xb64",  "xb65",  "xb66",  "xb67",
    "xb68",  "xb69",  "xb70",  "xb71",
    "xb72",  "xb73",  "xb74",  "xb75",
    "xb76",  "xb77",  "xb78",  "xb79",
    "xb80",  "xb81",  "xb82",  "xb83",
    "xb84",  "xb85",  "xb86",  "xb87",
    "xb88",  "xb89",  "xb90",  "xb91",
    "xb92",  "xb93",  "xb94",  "xb95",
    "xb96",  "xb97",  "xb98",  "xb99",
    "xb100", "xb101", "xb102", "xb103",
    "xb104", "xb105", "xb106", "xb107",
    "xb108", "xb109", "xb110", "xb111",
    "xb112", "xb113", "xb114", "xb115",
    "xb116", "xb117", "xb118", "xb119",
    "xb120", "xb121", "xb122", "xb123",
    "xb124", "xb125", "xb126", "xb127",

    /* 1746 - 1777  */

    "xg0",  "xg1",  "xg2",  "xg3",
    "xg4",  "xg5",  "xg6",  "xg7",
    "xg8",  "xg9",  "xg10", "xg11",
    "xg12", "xg13", "xg14", "xg15",
    "xg16", "xg17", "xg18", "xg19",
    "xg20", "xg21", "xg22", "xg23",
    "xg24", "xg25", "xg26", "xg27",
    "xg28", "xg29", "xg30", "xg31",

    /* 1778 - 1793  */
    /* "Dwarf" registers, may be get rid of them . . .  */
    "", "", "", "", "", "", "", "",
    "", "", "", "", "", "", "", "",

    /* 1794 - 2017  */

    /* These ones may be explicitly specified by the
       user. */

    "qpr0",  "qpr1",  "qpr2",  "qpr3",  "qpr4",  "qpr5",  "qpr6",  "qpr7",
    "qpr8",  "qpr9",  "qpr10", "qpr11", "qpr12", "qpr13", "qpr14", "qpr15",
    "qpr16", "qpr17", "qpr18", "qpr19", "qpr20", "qpr21", "qpr22", "qpr23",
    "qpr24", "qpr25", "qpr26", "qpr27", "qpr28", "qpr29", "qpr30", "qpr31",
    "qpr32", "qpr33", "qpr34", "qpr35", "qpr36", "qpr37", "qpr38", "qpr39",
    "qpr40", "qpr41", "qpr42", "qpr43", "qpr44", "qpr45", "qpr46", "qpr47",
    "qpr48", "qpr49", "qpr50", "qpr51", "qpr52", "qpr53", "qpr54", "qpr55",
    "qpr56", "qpr57", "qpr58", "qpr59", "qpr60", "qpr61", "qpr62", "qpr63",

    /* while %qpr64 - %qpr223 may not. */

    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",
    "",    "",    "",    "",    "",    "",    "",    "",

    /* 2018 - 2145  */

    "qpb0",   "qpb1",   "qpb2",   "qpb3",
    "qpb4",   "qpb5",   "qpb6",   "qpb7",
    "qpb8",   "qpb9",   "qpb10",  "qpb11",
    "qpb12",  "qpb13",  "qpb14",  "qpb15",
    "qpb16",  "qpb17",  "qpb18",  "qpb19",
    "qpb20",  "qpb21",  "qpb22",  "qpb23",
    "qpb24",  "qpb25",  "qpb26",  "qpb27",
    "qpb28",  "qpb29",  "qpb30",  "qpb31",
    "qpb32",  "qpb33",  "qpb34",  "qpb35",
    "qpb36",  "qpb37",  "qpb38",  "qpb39",
    "qpb40",  "qpb41",  "qpb42",  "qpb43",
    "qpb44",  "qpb45",  "qpb46",  "qpb47",
    "qpb48",  "qpb49",  "qpb50",  "qpb51",
    "qpb52",  "qpb53",  "qpb54",  "qpb55",
    "qpb56",  "qpb57",  "qpb58",  "qpb59",
    "qpb60",  "qpb61",  "qpb62",  "qpb63",
    "qpb64",  "qpb65",  "qpb66",  "qpb67",
    "qpb68",  "qpb69",  "qpb70",  "qpb71",
    "qpb72",  "qpb73",  "qpb74",  "qpb75",
    "qpb76",  "qpb77",  "qpb78",  "qpb79",
    "qpb80",  "qpb81",  "qpb82",  "qpb83",
    "qpb84",  "qpb85",  "qpb86",  "qpb87",
    "qpb88",  "qpb89",  "qpb90",  "qpb91",
    "qpb92",  "qpb93",  "qpb94",  "qpb95",
    "qpb96",  "qpb97",  "qpb98",  "qpb99",
    "qpb100", "qpb101", "qpb102", "qpb103",
    "qpb104", "qpb105", "qpb106", "qpb107",
    "qpb108", "qpb109", "qpb110", "qpb111",
    "qpb112", "qpb113", "qpb114", "qpb115",
    "qpb116", "qpb117", "qpb118", "qpb119",
    "qpb120", "qpb121", "qpb122", "qpb123",
    "qpb124", "qpb125", "qpb126", "qpb127",

    /* 2146 - 2177 */

    "qpg0",  "qpg1",  "qpg2",  "qpg3",
    "qpg4",  "qpg5",  "qpg6",  "qpg7",
    "qpg8",  "qpg9",  "qpg10", "qpg11",
    "qpg12", "qpg13", "qpg14", "qpg15",
    "qpg16", "qpg17", "qpg18", "qpg19",
    "qpg20", "qpg21", "qpg22", "qpg23",
    "qpg24", "qpg25", "qpg26", "qpg27",
    "qpg28", "qpg29", "qpg30", "qpg31",

  };


int main ()
{
  int i;
  size_t maxlen = 0;

  for (i = 0; i < 2178; i++)
    {
      int j;
      size_t len = strlen (e2k_register_names[i]);
      int met_figure = 0;

      printf ("E2K_%s_REG %s(\"%s\",", i < 958 ? "RAW" : "PSEUDO",
	      i < 958 ? "   " : "", e2k_register_names[i]);
      for (j = 0; j < 32 - len; j++)
	putchar (' ');

      if (i < 958)
	{
	  if (e2k_linux_ptrace_offsets[i] != -1)
	    printf ("0x%04x, ", e2k_linux_ptrace_offsets[i]);
	  else
	    printf ("-1,     ");
	}
      else
	printf ("        ");

      for (j = 0; j < len; j++)
	{
	  char c = e2k_register_names[i][j];
	  if (c >= '0' && c <= '9')
	    {
	      putchar (c);
	      met_figure = 1;
	    }
	  else if (met_figure)
	    break;
	}

      printf (")\n");

      if (maxlen < len)
	maxlen = len;
    }


  if (maxlen > 31)
    abort ();

  return 0;
}
