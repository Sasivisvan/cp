
num = input()

odo = ["0", "0", "0", "0", "0"]

i = len(num)-1
print("00000")
while(i>=0):
    if odo[i] == num[i]:
        i-=1
        continue
    else:
        odo[i] = str(int(odo[i])+1)
    print("".join(odo))
