#!/bin/bash

set -x

LCC="/auto/malakhov/.work/toolchains/latest/e2k-optimized/ecomp.rel-i-1/lcc_i -mptr128"

$LCC -g -fPIC -shared ./val.c -o ./libfoo.so
$LCC -g -fPIC -shared ./val.c -Dfoo=bar -o ./libbar.so
$LCC -g ./main.c ./libfoo.so ./libbar.so
