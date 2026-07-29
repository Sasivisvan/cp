#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C

import sys

a =  [1, 2, 2, 1]
b = [3, 3, 3, 4]
k = 5

a = sorted(a)
b = sorted(b)[::-1]

for i in range(len(a)):
    if a[i] + b[i] < k :
        print(False)
        sys.exit()

print(True)
k
