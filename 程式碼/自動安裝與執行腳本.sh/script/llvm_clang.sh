#!/bin/sh
sudo apt install clang llvm
mkdir --parent ~/Desktop/Compiler/llvm_clang
cd ~/Desktop/Compiler/llvm_clang
read -p "請輸入檔案路徑:" filepath
clang -emit-llvm ${filepath} -S -o test.ll
opt -globalopt -loop-simplify -mem2reg  test.ll -o /dev/null
llc test.ll
as test.s -o test.o
ld -o test_exec -dynamic-linker /lib64/ld-linux-x86-64.so.2 /usr/lib/x86_64-linux-gnu/crt1.o /usr/lib/x86_64-linux-gnu/crti.o test.o -lc /usr/lib/x86_64-linux-gnu/crtn.o
./test_exec
echo "------------------"
ls -l ~/Desktop/Compiler/llvm_clang
