#!/bin/bash
curl https://raw.githubusercontent.com/Wakadaisho/alx-low_level_programming/main/0x18-dynamic_libraries/libputs.so -o /tmp/libputs.so
export LD_PRELOAD="/tmp/libputs.so"
