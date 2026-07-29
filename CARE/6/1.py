#Name: SASI VISVAN C
#Roll No: CH.SC.U4AIE24084

n = "30151"
nums = list(n)

created = ["0" for _ in range(len(nums))]

i=len(n)-1
while(i>=0):
    if nums[i] == created[i]:
        i=i-1
    else:
        created[i] = str(int(created[i])+1)
        print("".join(created))
