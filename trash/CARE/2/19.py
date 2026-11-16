def get_max_area(arr):
    st = []
    ans = 0
    n = len(arr)

    for i in range(n):
        while st and arr[st[-1]] > arr[i]:
            h = arr[st.pop()]

            if st:
                w = i - st[-1] - 1
            else:
                w = i

            ans = max(ans, h * w)

        st.append(i)

    while st:
        h = arr[st.pop()]

        if st:
            w = n - st[-1] - 1
        else:
            w = n

        ans = max(ans, h * w)

    return ans


arr = [60, 20, 50, 40, 10, 50, 60]

print(get_max_area(arr))