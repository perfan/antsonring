#!/bin/sh
export  LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:/home/b/bussmann/perfan/src/openBlas/lib
module load gcc rarray boost
make clean
make run
