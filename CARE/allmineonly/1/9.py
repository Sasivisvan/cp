arr = list(map(int, input().split()))

arr1 = [arr[0]]
arr2 = []
highest = arr[0]
hi = 0
for i in range(1,len(arr)):
    if arr[i] > highest:
        highest = arr[i]


    arr1.append(highest)
least = arr[-1]
li = len(arr)-1
for i in range(len(arr)-1, -1, -1):

    if arr[i] < least:
        least = arr[i]

    arr2.append(least)

arr2 = arr2[::-1]

done = False
for i in range(1,len(arr)-1):
    if arr1[i-1] <= arr[i] <= arr2[i+1]:
        print(arr[i])
        done = True
        break

if not done:
    print(-1)

