from decimal import *
import math

getcontext().prec = 102
low = 2
high = 99
result = 0

for n in range(low, high + 1):
    i = int(math.sqrt(n))
    if (i * i == n):
        continue
    decStr = (str(Decimal(n).sqrt()))[:101]
    for digit in decStr:
        if (digit != '.'):
            result += int(digit)

print result
