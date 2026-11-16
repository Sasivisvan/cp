from collections import deque

n,m = tuple(map(int, input().split()))
ans = 10**10

stk = deque([(n, 0)])
c = 0
while(n!=m):
	# print(n,m)
	if n>m:
		c += n-m
		n=m
	elif n <= m and m%2==0:
		m = m//2
		c+=1
	elif n <= m and m%2==1:
		m = m+1
		m=m//2
		c+=2


print(c)
