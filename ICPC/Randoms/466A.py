n, m, a, b = tuple(map(int, input().split(" ")))

if b/m >= a :
	print(n*a)
else:

	cost = (n//m)*b 

	cost += min((n%m)*a, b)

	print(cost)