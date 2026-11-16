#Name: SASI VISVAN C
#Roll No: CH.SC.U4AIE24084


s = "ilike"
d = ["i", "like", "gfg"]

dp = [False] * (len(s)+1)
dp[0] = True

for i in range(1, len(s)+1):
    for w in d:
        if i >= len(w) and s[i-len(w):i] == w and dp[i-len(w)]:
            dp[i] = True

print(dp)

print(dp[-1])
