#!/bin/sh
sudo apt install build-essential
mkdir --parent ~/Desktop/Compiler/gcc
read -p "請輸入檔案路徑: " filepath    # 提示使用者輸入
cd ~/Desktop/Compiler/gcc
gcc -S -masm=intel ${filepath} -o test 
as -o test.o test 
ld -o test_exec -dynamic-linker /lib64/ld-linux-x86-64.so.2  /usr/lib/x86_64-linux-gnu/crt1.o  /usr/lib/x86_64-linux-gnu/crti.o /usr/lib/x86_64-linux-gnu/crtn.o test.o -lc
./test_exec
echo "------------------"
ls -l ~/Desktop/Compiler/gcc
