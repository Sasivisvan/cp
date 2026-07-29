#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C

a = [2,4,7,10]
b = [2,3]

n,m = len(a),len(b)

total = sorted(a+b)

a = total[:n]
b = total[n:]

print(a)
print(b)
