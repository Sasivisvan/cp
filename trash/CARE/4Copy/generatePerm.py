
arr =[1,2,3,4,5,6,7]

perms = []

def generateperm(arr,n):

    global perms

    if len(arr) == n:
        perms.append(arr)
        return


    for i in range(1,n+1):

        if len(arr) == 0:
            generateperm([i], n)

        elif i not in arr:
            for j in range(len(arr)):
                arr2 = arr[::]
                arr2.insert(j,i)
                generateperm(arr2, n)


generateperm([], 4)

print(len(perms))
