#!/bin/bash

FILE_NAME='test_map.cpp'
TEST_STD='std_test'
TEST_FT='ft_test'
FLAGS='-Wall -Wextra -Werror -std=c++98'


clang++ $FLAGS -DNAMESPACE=std -o $TEST_STD $FILE_NAME
clang++ $FLAGS -DNAMESPACE=ft -o $TEST_FT $FILE_NAME


echo "  FT" > file1
echo "  STD" > file2

./$TEST_FT >> file1
./$TEST_STD >> file2

diff -y file1 file2
rm file1 file2