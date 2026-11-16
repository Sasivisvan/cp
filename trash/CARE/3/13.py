#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C

s = "(())))("

L = [0]
R = [0]

for i in range(len(s)):
    if s[i] == '(':
        L.append(L[-1]+1)
    else:
        L.append(L[-1])

for i in range(len(s)-1,-1,-1):
    if s[i] == ')':
        R.append(R[-1]+1)
    else:
        R.append(R[-1])
        
L = L[1::]
R = R[1::]

R = list(reversed(R))

for i in range(len(R)):
    if L[i] == R[i]:
        print(i)
        break
