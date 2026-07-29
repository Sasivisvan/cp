#Name: SASI VISVAN C
#Roll No: CH.SC.U4AIE24084

t, x, y = 170, 50, 10

days = 0
total = x
sun = y

while total < t:
    for d in range(7):
        total += sun + d
        days += 1
        if total >= t:
            break
    sun += 1

print(days)
