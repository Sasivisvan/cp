#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C

s = "timetopractice"
p = "toc"

need = {}
for ch in p:
    need[ch] = need.get(ch, 0) + 1

have = {}
l = 0
formed = 0
required = len(need)
best = ""

for r in range(len(s)):
    ch = s[r]
    have[ch] = have.get(ch, 0) + 1

    if ch in need and have[ch] == need[ch]:
        formed += 1

    while formed == required:
        window = s[l:r+1]
        if best == "" or len(window) < len(best):
            best = window

        lch = s[l]
        have[lch] -= 1
        if lch in need and have[lch] < need[lch]:
            formed -= 1
        l += 1

print(best)
