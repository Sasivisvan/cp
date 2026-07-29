#Roll No: CH.SC.U4AIE24084

arr = [1, -2, 1, 0, 5]
t = 0

found = set()
solved = False
for i in arr:
    if t-i in found:
        print(True)
        solved = True
    
    found.add(i)
if not solved:
    print(False)