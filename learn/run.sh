#! /bin/sh
echo ........................build
nasm -f elf64 -o $1.o $1.asm
echo ........................link
ld $1.o -o $1
echo ........................exec
./$1
echo ........................clean
rm $1.o $1
