#!/bin/bash

for i in {1..12}; do
 pids=$(top -bn1 | grep matho-primes | awk '$9 > 50 {print $1}')
 echo "$pids" >> /home/cron.log
 sleep 5
done
