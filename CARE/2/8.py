arr = [4,5,0,1.9,0,5,0]
n = len(arr)
print(arr)
p1,p2 = 0,0

while( p2<n):

    if arr[p2] != 0:
        arr[p1] = arr[p2]

        p2+=1
        p1+=1
    else:
        p2+=1
p1+=1
while(p1<n):
    arr[p1]=0
    p1+=1
print(arr)
    
