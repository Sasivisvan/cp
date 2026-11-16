#Name: SASI VISVAN C
#Roll No: CH.SC.U4AIE24084

n = "5423"

def prime(x):
    if x < 2:
        return False
    for i in range(2, int(x**0.5) + 1):
        if x % i == 0:
            return False
    return True

ans = []
for i in range(len(n)):
    for j in range(i + 1, len(n) + 1):
        val = int(n[i:j])
        if prime(val):
            ans.append(val)

if len(ans) == 0:
    print(-1)
else:
    print(" ".join(map(str, ans)))
