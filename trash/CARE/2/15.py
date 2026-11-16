def find_occurrences(arr, x):
    def get_first(arr, x):
        l, r = 0, len(arr) - 1
        res = -1
        while l <= r:
            m = (l + r) // 2
            if arr[m] == x:
                res = m
                r = m - 1
            elif arr[m] < x:
                l = m + 1
            else:
                r = m - 1
        return res

    def get_last(arr, x):
        l, r = 0, len(arr) - 1
        res = -1
        while l <= r:
            m = (l + r) // 2
            if arr[m] == x:
                res = m
                l = m + 1
            elif arr[m] < x:
                l = m + 1
            else:
                r = m - 1
        return res

    return [get_first(arr, x), get_last(arr, x)]

arr = list(map(int, input().split()))
x = int(input())
result = find_occurrences(arr, x)
print(f"[{result[0]}, {result[1]}]")