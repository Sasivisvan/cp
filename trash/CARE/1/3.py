#Roll No: CH.SC.U4AIE24084
arr =  [4, 2, 5, 7]


boolarr = [False for i in range(len(arr))]

currmax = arr[0]
for n,i in enumerate(arr):
    if i>currmax:
        currmax = i
        boolarr[n]=True


i = len(arr)-1
currmin = arr[-1]
solved = False
while(i>0):

    if arr[i]<currmin:
        if boolarr[i]:
            print(arr[i])
            solved = True

        currmin = arr[i]
    i-=1

if not solved:
    print(-1)
