#Name: SASI VISVAN C
#Roll No: CH.SC.U4AIE24084

n = 5
houses = [12, 6, 8, 2, 4]
m = 3
targets = [2, 5, 4]

for t in targets:
    idx = t - 1
    if houses[idx] > 0:
        houses[idx] = max(0, houses[idx] - 2)
        if idx - 1 >= 0:
            houses[idx - 1] = max(0, houses[idx - 1] - 1)
        if idx + 1 < n:
            houses[idx + 1] = max(0, houses[idx + 1] - 1)

print(" ".join(map(str, houses)))
