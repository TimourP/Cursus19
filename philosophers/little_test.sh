#!/bin/bash

make fclean && make philo_one
for i in {1..500}
do
   ./philo_one 5 80 30 30 | grep "died" | wc -l | grep -v 1
done