from collections import defaultdict

# B = ["red", "green", "blue", "red", "green", "blue", "yellow"]
B = ["red", "blue", "green", "red", "red", "blue"]

counts = defaultdict(int)

for i in B:
    counts[i]+=1

for i in B:
    if counts[i]%2==1:
        print(i)
        break
else:
    print("All Even")
