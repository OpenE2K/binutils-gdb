#!/bin/bash

set -x

CC="/auto/malakhov/.work/toolchains/latest/e2k-optimized/ecomp.rel-i-1/lcc_i -mptr128"

# $CC ./foo.c -fPIC -S
$CC ./foo.s -shared -o ./libfoo.so
$CC -g -fPIC ./bar.c -shared -o ./libbar.so
$CC -g ./main.c ./libfoo.so ./libbar.so -Wl,--dynamic-linker=./ld.so
