#!/bin/bash

lib_name='ft_containers.a'
TEST_STD='std_test'
TEST_FT='ft_test'


clang++  -DNAMESPACE=std -o $TEST_STD  -Wall -Werror -Wextra test.cpp
clang++ -DNAMESPACE=ft -o $TEST_FT  -Wall -Werror -Wextra test.cpp 


echo "  FT" > file1
echo "  STD" > file2

./$TEST_FT >> file1
./$TEST_STD >> file2

diff -y file1 file2
rm file1 file2