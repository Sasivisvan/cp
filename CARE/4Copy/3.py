#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C

import sys
arr = [1, 4, 45, 6, 10, 8]
t = 13

arr_dict = dict()

for i in range(len(arr)):
    for j in range(i+1, len(arr)):
        if t-(arr[i] + arr[j]) in arr_dict:
            if arr_dict[t-(arr[i] + arr[j])] != i and arr_dict[t-(arr[i] + arr[j])]!=j:
                print(True)
                sys.exit()

    arr_dict[arr[i]] = i

print(False)
