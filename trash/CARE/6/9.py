#Name: SASI VISVAN C
#Roll No: CH.SC.U4AIE24084

n = 7
nums = [20, 72, 204, 727, 1073, 153, 207]

ans = []
for i in range(n):
    if i == 0:
        prev = nums[n - 1]
    else:
        prev = nums[i - 1]
    t1 = (nums[i] // 10) % 10
    t2 = (prev // 10) % 10
    if t1 > t2:
        ans.append(nums[i])

print(" ".join(map(str, ans)))
