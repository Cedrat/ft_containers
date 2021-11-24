#!/bin/sh

test(){

echo A0
echo A1
echo A2
echo A3
echo EOF

}

test2(){
    test | ./a.out
}

test2