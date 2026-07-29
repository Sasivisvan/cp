arr = [0,1,0,1,1]

i = len(arr)-1
running_sum = 0
total_sum = 0
while(i>=0):

    if arr[i] == 1:
        running_sum+=1
    else:
        total_sum+=running_sum
    i-=1
print(total_sum)
