#Name: SASI VISVAN C
#Roll No: CH.SC.U4AIE24084

n = 6
nums = [15, 25, 387, 440, 48, 80]

def parity(x):
    return bin(x).count('1') % 2

nums.sort(key=lambda x: (parity(x), x))

print(" ".join(map(str, nums)))
