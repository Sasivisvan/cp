#Name: SASI VISVAN C
#Roll No: CH.SC.U4AIE24084

x, y = 2934, 735

import re

bx = bin(x)[2:]
by = bin(y)[2:]

def parts(b):
    return re.findall(r'(?<=0)(1+)(?=0)', b)

px = parts(bx)
py = parts(by)

common = []
for p in px:
    if p in py and p not in common:
        common.append(p)

if len(common) == 0:
    print(x + y)
else:
    best = max(common, key=len)
    pat = '0' + best + '0'

    def modify(b, pat, best):
        result = list(b)
        protected = set()
        i = 0
        while i <= len(b) - len(pat):
            if b[i:i+len(pat)] == pat:
                for j in range(i+1, i+1+len(best)):
                    protected.add(j)
                i += len(pat)
            else:
                i += 1
        for i in range(len(result)):
            if i not in protected and result[i] == '1':
                result[i] = '0'
        return ''.join(result)

    mx = modify(bx, pat, best)
    my = modify(by, pat, best)
    print(int(mx, 2) + int(my, 2))
