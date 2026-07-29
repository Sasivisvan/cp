#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C

words = ["baa", "abcd", "abca", "cab", "cad"]

from collections import defaultdict, deque

adj = defaultdict(set)
indegree = {}

for w in words:
    for ch in w:
        if ch not in indegree:
            indegree[ch] = 0

for i in range(len(words)-1):
    w1 = words[i]
    w2 = words[i+1]
    found = False
    for j in range(min(len(w1), len(w2))):
        if w1[j] != w2[j]:
            if w2[j] not in adj[w1[j]]:
                adj[w1[j]].add(w2[j])
                indegree[w2[j]] += 1
            found = True
            break
    if not found and len(w1) > len(w2):
        print("")
        exit()

q = deque()
for ch in indegree:
    if indegree[ch] == 0:
        q.append(ch)

res = []
while q:
    ch = q.popleft()
    res.append(ch)
    for nb in adj[ch]:
        indegree[nb] -= 1
        if indegree[nb] == 0:
            q.append(nb)

if len(res) != len(indegree):
    print("")
else:
    print("".join(res))
