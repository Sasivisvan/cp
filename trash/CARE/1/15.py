#Roll No: CH.SC.U4AIE24084

from collections import defaultdict

arr = [1, 0, 1, 1, 1, 0, 0]

counts = defaultdict(int)
sums = 0
maxlen = 0
for i in range(len(arr)):

    if arr[i] == 1  :

        sums+=1
    else:
        sums-=1

    if sums == 0:
        maxlen = max(maxlen, i+1)
    
    if sums in counts:
        maxlen = max(maxlen, i-counts[sums])
    
    if sums not in counts:
        counts[sums] = i
    
print(maxlen)



