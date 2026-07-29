#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C
s = "abpcplea"
d = ["ale", "apple", "monkey", "plea"]

def check(w):
    i = 0
    j = 0
    while i < len(s) and j < len(w):
        if s[i] == w[j]:
            j += 1
        i += 1
    return j == len(w)

ans = ""

for w in d:
    if check(w):
        if len(w) > len(ans) or (len(w) == len(ans) and w < ans):
            ans = w

print(ans)
