arr = [5, 15, 1, 3, 2, 8]
out = []
temp = []

for i in range(len(arr)):
    temp.append(arr[i])
    
    for j in range(len(temp)):
        for k in range(j + 1, len(temp)):
            if temp[j] > temp[k]:
                temp[j], temp[k] = temp[k], temp[j]
                
    n = len(temp)
    
    if n % 2 != 0:
        mid = n // 2
        out.append(float(temp[mid]))
    else:
        mid1 = n // 2 - 1
        mid2 = n // 2
        out.append((temp[mid1] + temp[mid2]) / 2.0)

print(out)