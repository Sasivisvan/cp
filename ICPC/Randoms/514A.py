import sys

n = input()
if n=="9":
	print(9)
	sys.exit()
ans = []
c = 0
for i in n:
	if int(i) >=5 :
		if c==0 and int(i)==9:
			ans.append(i)
		else:
			ans.append(str(9-int(i)))
	else:
		ans.append(i)
	c+=1
print("".join(ans))