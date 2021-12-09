#!/bin/bash

lib_name='ft_containers.a'
TEST_STD='std_test'
TEST_FT='ft_test'


clang++  -DNAMESPACE=std -o $TEST_STD  -Wall -Werror -Wextra test_vector.cpp
clang++ -DNAMESPACE=ft -o $TEST_FT  -Wall -Werror -g -Wextra test_vector.cpp 


echo "  FT" > file1
echo "  STD" > file2

./$TEST_FT >> file1
./$TEST_STD >> file2

diff file1 file2 -y 
rm file1 file2