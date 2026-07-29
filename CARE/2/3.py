length = int(input())
arr = list(map(int, input().split()))

if length <= 3:
    print(0)
else:
    even_arr = arr[0::2]
    odd_arr = arr[1::2]
    
    even_arr.sort()
    odd_arr.sort()
    
    print(even_arr[-2] + odd_arr[-2])