! Use -fno-verbose-asm option to omit extra line information
! -----------------------------------------------------------------------------
	.file	"delme.c"
	.ignore	ld_st_style
	.ignore	strict_delay
! -----------------------------------------------------------------------------
.text
! file: ./delme.c, line: 3
	.global	$foo
	.type	$foo, @function
	.align	8
$foo:
	! <0000>
	{
	  setwd	wsz = 0x70, nfx = 0x1		! op=6, line=4
	  setbn rsz = 0x3f, rbs = 0x30, rcur = 0x0
	}

	{
	  getsp,0       _f16s,_lts0hi 0xfff0, %dr2      ! op=17
	}

#include "gen.S"

	! <0001>
	{
	  nop 5
	  return	%ctpr3; ipd 2			! op=3
	}
	! <0007>
	{
	  ct	%ctpr3					! op=4
	}
	.size	$foo, .- $foo
! -----------------------------------------------------------------------------
	.weak	$elbrus_compiler_v1.A.XX_May_24_2016
	.set	$elbrus_compiler_v1.A.XX_May_24_2016, 0x0
