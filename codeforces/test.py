def myfunc(x):
    return int(x)-5

y = list(tuple(map(myfunc,input().split(" "))))
print(y)