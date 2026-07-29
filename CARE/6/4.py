#Name: SASI VISVAN C
#Roll No: CH.SC.U4AIE24084

n = 5
nums = [15, 260, -46, 117, -9]

s = 0
for i in nums:
    a = abs(i)
    if i % 2 != 0:
        s += i * (a % 10)
    else:
        while a >= 10:
            a //= 10
        s += i * a

print(s)
