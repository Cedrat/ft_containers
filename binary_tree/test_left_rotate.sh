#!/bin/sh

test2(){

echo A11
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

test4() 
{
    echo A4
    echo A5
    echo D4
    echo A4
}

test5() 
{
    echo A34
    echo A35
    echo A56
    echo A36
    echo D56
}

test6() 
{
    echo A1
    echo A2
    echo A3
    echo A4
    echo A5
    echo A6
    echo A7
    echo A8 
    echo A9
    echo A10
    echo D2
}

test7()
{
    echo A1
    echo A2
    echo A3
    echo A4
    echo A5
    echo A6
    echo D1
}

test8()
{
    echo A1
    echo A2
    echo A3
    echo A4
    echo A5
    echo A6
    echo D2
    echo D3
    echo D5
    echo D6
}

test(){
    test6| valgrind ./a.out
}

test