#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C

arr1 = [5, 2, 8]
arr2 = [10, 7, 12]
arr3 = [9, 14, 6]

arr1 = sorted(arr1)
arr2 = sorted(arr2)
arr3 = sorted(arr3)

best_diff = 100000000
best_triplet = []

for i in range(len(arr1)):
    for j in range(len(arr2)):
        for k in range(len(arr3)):
            mx = max(arr1[i], arr2[j], arr3[k])
            mn = min(arr1[i], arr2[j], arr3[k])
            diff = mx - mn
            s = arr1[i] + arr2[j] + arr3[k]
            if diff < best_diff or (diff == best_diff and s < sum(best_triplet)):
                best_diff = diff
                best_triplet = sorted([arr1[i], arr2[j], arr3[k]])

print(best_triplet)
