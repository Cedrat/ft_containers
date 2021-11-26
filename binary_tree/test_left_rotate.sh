#!/bin/sh

test(){

echo A10
echo A9
echo A8
echo A7
echo A6
echo A5
echo A4
echo A3
echo A2
echo A1
echo A0

}
test3()
{
    echo A50
    echo A49
    echo A51
    echo A48
    echo A40
    echo A43
    echo A42
    echo A45

}

test2(){
    test | valgrind ./a.out
}

test2