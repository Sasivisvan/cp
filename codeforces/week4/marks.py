n,m = tuple(map(int, input().split()))

marks = []
for i in range(n):
    marks.append(list(map(int, list(input()))))

# print(marks)

best_students = set()

for i in range(m):
    ma = 0

    for j in range(n):
        # print(ma)
        # print(marks[i])
        if marks[j][i] > ma:
            ma = marks[j][i]
    for j in range(n):
            if marks[j][i] == ma:
                best_students.add(j)
# print(best_students)
print(len(best_students))
#152A
