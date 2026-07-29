#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C

s = "i.like.this.program........very.much"


arr = s.split(".")

while("" in arr):
    arr.remove("")

arr = reversed(arr)
print(".".join(arr))
