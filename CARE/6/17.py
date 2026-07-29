#Name: SASI VISVAN C
#Roll No: CH.SC.U4AIE24084

n = 10672

m = {2: 5, 5: 2, 6: 9, 9: 6}

s = str(n)
rot = ""
for ch in s:
    d = int(ch)
    if d in m:
        rot += str(m[d])
    else:
        rot += ch

print(n + int(rot))
