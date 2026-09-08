#!/bin/sh

program=$1
test_dir=$2

red="\033[0;31m"
green="\033[0;32m"
yellow="\033[0;33m"
blue="\033[0;34m"
purple="\033[0;35m"
cyan="\033[0;36m"
nc="\033[0m"

for test in $(ls $test_dir); do
    if [ ! -d $test_dir/$test ]; then
        continue
    fi

    input_file="$test_dir/$test/input.txt"
    expected_output_file="$test_dir/$test/output.txt"
    student_output="output.txt"

    timeout 5s ./$program $input_file $student_output > /dev/null 2>&1
    exit_code=$?

    if [ $exit_code -eq 124 ]; then
        echo -e "$yellow[!TIMEOUT]$nc $test"
        continue
    elif [ $exit_code -eq 139 ]; then
        echo -e "$red[SEGFAULT]$nc $test"
        echo "$program $test: SEGMENTATION FAULT"
        continue
    elif [ $exit_code -ne 0 ]; then
        echo -e "$yellow[ UERROR ]$nc $test (exit code $exit_code)"
        continue
    fi

    diff -b $student_output $expected_output_file > /dev/null 2>&1

    if [ $? -ne 0 ]; then
        echo -e "$red[ FAILED ]$nc $test"
    else
        echo -e "$green[ PASSED ]$nc $test"
    fi

    rm -rf $student_output
done
