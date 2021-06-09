#!/bin/bash
for i in {1..500}
do
   ./philo_one 5 125 60 60 | grep "died" | wc -l | grep -v 1
done