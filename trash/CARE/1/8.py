#Roll No: CH.SC.U4AIE24084

a = [2,4,6,8,9,10,12]
b = [2,4,6,8,10,12]

# a = [3,5,7,8,11,13]
# b = [3,5,7,11,13]

i =0 
solved = False
while(i<len(a) and i<len(b)):

    if a[i]!=b[i]:
        solved = True
        print(i)
        break
    i+=1

if not solved:

    if len(a)>len(b):
        print(len(a)-1)
    else:
        print(len(b)-1)