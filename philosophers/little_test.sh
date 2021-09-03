#!/bin/bash

make fclean && make
./philo $1 400 100 100 3 > test.txt
START=1
for (( i=$START; i<=$1; i++ ))
do
   echo "$i:"
   cat test.txt | grep "$i is eating" | wc -l
done
cat test.txt | grep "died"
make fclean