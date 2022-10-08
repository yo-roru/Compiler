#!/bin/sh
mkdir --parent ~/Desktop/Compiler/src
cd ~/Desktop/Compiler
sudo apt-get update -y
sudo apt-get install flex bison git vim -y
#git clone https://github.com/gjlmotea/Compiler-sample.git
cd Compiler-sample
mv lex.* y* ../src/
cd ../src/
lex lex.l
yacc -d yacc.y
cc lex.yy.c y.tab.c -o cpl
export PATH=~/Desktop/Compiler/src:$PATH

