def has_zero_sum_triplet(arr):
    arr.sort()
    n = len(arr)
    
    for i in range(n - 2):
        left = i + 1
        right = n - 1
        
        while left < right:
            current_sum = arr[i] + arr[left] + arr[right]
            
            if current_sum == 0:
                return True
            elif current_sum < 0:
                left += 1
            else:
                right -= 1
                
    return False

arr = list(map(int, input().split()))
if has_zero_sum_triplet(arr):
    print("true")
else:
    print("false")