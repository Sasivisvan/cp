#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C

# s1 = input("Enter the first string: ")
# s2 = input("Enter the second string: ")

def transform(s1,s2):

    total = 0
    j = len(s2)-1
    for i in range(len(s1)-1, -1, -1):
        if j<0:
            break
        if s1[i] == s2[j]:
            j-=1
        else:
            total+=1
    return total


s1 = "GeeksForGeeks";
s2 = "ForGeeksGeeks";

print(transform(s1,s2))
