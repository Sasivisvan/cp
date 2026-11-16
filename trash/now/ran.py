import random


high = 10000
tri = 0
nontri =0

for i in range(1000000):
    a, b = random.randint(0,high), random.randint(0,high)
    arr = sorted([0, a, b ,high])
    s1,s2,s3 = arr[1], arr[2]-arr[1], arr[3] - arr[2]

    arr = sorted([s1,s2,s3])

    if arr[0] + arr[1] >= arr[2]:
        tri +=1
    else:
        nontri+=1



print(tri/(nontri+tri))