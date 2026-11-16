def LargeSmallSum(arr, length):
    if length <= 3:
        return 0
        
    even_max_index = 0
    odd_min_index = 1
    even_max = arr[0]
    odd_min = arr[1]

    for i in range(length):
        if i % 2 == 0 and arr[i] > even_max:
            even_max = arr[i]
            even_max_index = i
        if i % 2 == 1 and arr[i] < odd_min:
            odd_min = arr[i]
            odd_min_index = i
            
    arr[even_max_index] = float('-inf')
    arr[odd_min_index] = float('inf')

    even_max_index = 0
    odd_min_index = 0
    even_max = arr[0]
    odd_min = arr[1]

    for i in range(length):
        if i % 2 == 0 and arr[i] > even_max:
            even_max = arr[i]
            even_max_index = i
        if i % 2 == 1 and arr[i] < odd_min:
            odd_min = arr[i]
            odd_min_index = i
            
    return odd_min + even_max


print(LargeSmallSum([3, 2, 1, 7, 5, 4], 6))
print(LargeSmallSum([1, 8, 0, 2, 3, 5], 6))
print(LargeSmallSum([1, 2, 3], 3))