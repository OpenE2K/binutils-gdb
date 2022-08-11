# Instructions stolen by r2000+ from foreign Sparc CPUs.

	fchksm16 %f54, %f56, %f58

	flcmps  %fcc0, %f1, %f3
	flcmps  %fcc1, %f3, %f5
	flcmps  %fcc2, %f5, %f7
	flcmps  %fcc3, %f7, %f9

	flcmpd  %fcc0, %f12, %f14
	flcmpd  %fcc1, %f14, %f16
	flcmpd  %fcc2, %f16, %f18
	flcmpd  %fcc3, %f18, %f20

	fmean16 %f50, %f52, %f54

	pdistn  %f48, %f50, %g1

	xmulx   %o1, %o2, %o3

	xmulxhi %o4, %o5, %o6

	fpadd64 %f52, %f54, %f56

	fpsub64 %f56, %f58, %f60

	fpadd8  %f2, %f4, %f8

	fpadds8 %f8, %f10, %f12

	fpaddus8 %f12, %f14, %f16

	fpaddus16 %f16, %f18, %f20

	fpsub8  %f2, %f4, %f6

	fpsubs8 %f6, %f8, %f10

	fpsubus8 %f10, %f12, %f14

	fpsubus16 %f14, %f16, %f18

	fpcmple8 %f2, %f4, %g1

	fpcmpgt8 %f4, %f6, %g2

	fpcmpule16 %f6, %f8, %g3

	fpcmpugt16 %f8, %f10, %g4

	fpcmpule32 %f10, %f12, %g5

	fpcmpugt32 %f12, %f14, %g6

	fpmax8  %f14, %f16, %f18

	fpmax16 %f18, %f20, %f22

	fpmax32 %f22, %f24, %f26

	fpmaxu8 %f26, %f28, %f30

	fpmaxu16 %f30, %f32, %f34

	fpmaxu32 %f34, %f36, %f38

	fpmin8  %f38, %f40, %f42

	fpmin16 %f42, %f44, %f46

	fpmin32  %f46, %f48, %f50

	fpminu8 %f50, %f52, %f54

	fpminu16 %f54, %f56, %f58

	fpminu32 %f58, %f60, %f62


# Original r2000+ instructions

	fpcsl32 %f0, %f2, %f4
	fpcsl64 %f6, %f8, %f10
	fpcsr32 %f12, %f14, %f16
	fpcsr64 %f18, %f20, %f22
