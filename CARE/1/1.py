#Roll No: CH.SC.U4AIE24084
def custum(num1, num2):
    if (str(num1)+str(num2)) > (str(num2)+str(num1)):
        return True
    else:
        return False

nums = [3, 30, 34, 5, 9]


#code up some NlogN sorting algos

for i in range(len(nums)):
    for j in range(len(nums)):
        if custum(nums[i],nums[j]):
            nums[i],nums[j] = nums[j],nums[i]

print(str(int("".join(list(map(str,nums))))))

    
    