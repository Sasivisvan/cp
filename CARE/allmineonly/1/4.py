
# arr = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110]

# for i in range(len(arr)):
#     m = arr[i]
#     index = i
#     for j in range(i+1, len(arr)):
#         if i%2==0:
#             if arr[j] > m:
#                 m = arr[j]
#                 index = j
#         elif arr[j]<m:
#             m = arr[j]
#             index = j

#     arr[i],arr[index] = arr[index], arr[i]




# print(arr)


def rearrange(arr):
    n = len(arr)
    if n <= 1:
        return
    arr.sort()                     # in-place sort, no second array
    max_idx, min_idx = n - 1, 0
    max_elem = 100000        # strictly bigger than any element

    for i in range(n):
        print(arr)
        if i % 2 == 0:              # even slot -> next largest
                    # 110
            arr[i] += (arr[max_idx] % max_elem) * max_elem
            max_idx -= 1
        else:                       # odd slot -> next smallest
            arr[i] += (arr[min_idx] % max_elem) * max_elem
            min_idx += 1
    print("Encoding over decoding: ")
    for i in range(n):
        arr[i] //= max_elem         # decode
        print(arr)
rearrange([10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110])
