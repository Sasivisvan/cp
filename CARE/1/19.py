#Roll No: CH.SC.U4AIE24084

from collections import defaultdict

n = 5
k = 4
arr = [5, 2, 1, 3, 2]

freq = defaultdict(int)

for i in range(len(arr)):

    freq[arr[i]] += 1

    s  = sorted(freq.keys(), key = lambda x: (-freq[x],x))

    print((s[-min(i+1,k):])[::-1])

