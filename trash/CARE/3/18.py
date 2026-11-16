#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C
s = ")()())"

stack = [-1]
ans = 0

for i in range(len(s)):
    if s[i] == '(':
        stack.append(i)
    else:
        stack.pop()
        if len(stack) == 0:
            stack.append(i)
        else:
            ans = max(ans, i - stack[-1])

print(ans)
