#!/usr/bin/env python

with open('input.txt', 'r') as f:
    sum = 0
    for line in f:
        sum = sum + int(line)
print str(sum)[0:10]
