t = int(input(""))

for _ in range(t):
	x,y = tuple(map(int,input().split(" ")))

	if y<0:
		if (x - 4*(-y))%3==0 and ((x - 4*(-y)))>=0:
			print("YES")
		else:
			print("NO")
	if y==0:
		if x%3==0:
			print("YES")
		else:
			print("NO")
	if y>0:
		if (x - 2*(y))%3==0 and (x - 2*(y))>=0: 
			print("YES")
		else:
			print("NO")