#Roll No: CH.SC.U4AIE24084

n = 6
arr = [2, 2, 1, 3, 3, 3]
m = 3

from collections import defaultdict
freq = defaultdict(int)
for i in arr:
    freq[i]+=1

sums = 0
solved = False

newarr = list(freq.items())
newarr = sorted(newarr, key = lambda x: x[1])
n = len(newarr)
print(newarr)

for i in range(len(newarr)):

    if( sums + newarr[i][1]) > m:
        print(n-i)
        solved = True
        break
    else:
        sums+= newarr[i][1]