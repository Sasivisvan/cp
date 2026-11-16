#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C

arr = [2,3,1,1,4]

jumps = 0
farthest = 0
end = 0

for i in range(len(arr)-1):
    farthest = max(farthest, i + arr[i])
    if i == end:
        jumps += 1
        end = farthest
        if end >= len(arr)-1:
            break

if end < len(arr)-1:
    print(-1)
else:
    print(jumps)
