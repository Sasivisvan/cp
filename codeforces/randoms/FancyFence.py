

t = int(input())
valid_angles = set()
i=3
while(True):
    if int((i-2)*180/i) == (i-2)*180/i:
        valid_angles.add((i-2)*180/i)
    if (i-2)*180/i >= 179:
        break
    i+=1
for _ in range(t):
    s = int(input())
    if s in valid_angles:
        print("YES")
    else:
        print("NO")


