#!/bin/bash
#=====================================================================================================
##
## Copyright 2015 - 2021, Luccioni Jesus Emanuel "J.E.L"
## All rights reserved.
#
#=====================================================================================================
local pwd dir file
dir="$(dirname "${0}")" ; file="$(basename "${0}")"
pwd=$(pwd)
# printfontcolor "current directory $pwd\n" "green"
# printfontcolor "current directory ${BASH_SOURCE[0]}\n" "green"
# printfontcolor "dir $dir file $file\n" "green"
cd $dir
./ISO8583Parser
