! Use -fno-verbose-asm option to omit extra line information
! -----------------------------------------------------------------------------
	.file	"foo.c"
	.ignore	ld_st_style
	.ignore	strict_delay
! -----------------------------------------------------------------------------
.text
! file: ./foo.c, line: 3
	.global	$foo
	.type	$foo, @function
	.align	8
$foo:
	! <0000>
	{
	  setwd	wsz = 0x6, nfx = 0x1		! op=5
	}
	! <0001>
	{
	  nop 5
	  disp	%ctpr1, 0x1f7
	}
	! <0007>
	{
	  wait	ma_c = 0x0, fl_c = 0x0, ld_c = 0x0, st_c = 0x0, all_e = 0x1, all_c = 0x0	! op=4
	  ct	%ctpr1					! op=3
	}
	.size	$foo, .- $foo
! -----------------------------------------------------------------------------
	.weak	$elbrus_compiler_v1.A.XX_May_14_2016
	.set	$elbrus_compiler_v1.A.XX_May_14_2016, 0x0
