
def findCount(arr, length, num, diff):
    count = 0
    for i in arr:
        if abs(i-num) <= diff:
            count+=1
    return count

print(findCount([2,4,7,5,8,4,1,44,76,12,32], 11, 5, 3))