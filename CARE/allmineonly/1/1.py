#remember the imports and shit

from functools import cmp_to_key

nums = list(input().split())

def custum(a,b):

    if a+b > b+a :
        return -1
    elif a + b < b + a:
        return 1
    
    return 0

print("".join(sorted(nums, key=cmp_to_key(custum))))

