print("enter list 1 and list 2 ")
arr1 = list(map(int, input().split(" ")))
arr2 = list(map(int, input().split(" ")))
odd_sum_1 = 0
odd_sum_2 = 0
for i in range(len(arr1)):
    if arr1[i]%2==1:
        odd_sum_1+=arr1[i]
    if arr2[i]%2==1:
        odd_sum_2+=arr2[i]

    print(f"arr1[{i}] odd sum:",odd_sum_1)
    print(f"arr2[{i}] odd sum:",odd_sum_2)
    print("max odd sum:",max(odd_sum_1,odd_sum_2))

    