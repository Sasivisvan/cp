#Name: SASI VISVAN C
#Roll No: CH.SC.U4AIE24084

n = 6
nums = [-5, 10, 55, 1000, 1100, 1300]
x, y = 20, 200

found = False
for i in range(n - 1):
    d = abs(nums[i + 1] - nums[i])
    if d <= x or d > y:
        print(str(nums[i]) + ":" + str(nums[i + 1]))
        found = True

if not found:
    print(-1)
