arr = [1, 4, 45, 6, 0, 19]
x = 51

running_sum = 0
min_size = float('inf')

l = 0
r = 0

while(r < len(arr)):
    running_sum += arr[r]
    
    while running_sum > x:
        min_size = min(min_size, r - l + 1)
        
        running_sum -= arr[l]
        l += 1
        
    r += 1

if min_size == float('inf'):
    print(0)
else:
    print(min_size)