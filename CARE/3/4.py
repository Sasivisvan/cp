#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C

exp = "(A)*((B+(C)))"

stack = []

for ch in exp:
    if ch == ')':
        top = []
        while stack[-1] != '(':
            top.append(stack.pop())
        stack.pop()

        has_low_op = any(x in ['+', '-'] for x in top)
        op_before = stack[-1] if stack else None
        need = op_before in ['*', '/'] and has_low_op

        if need:
            stack.append('(')
            for x in reversed(top):
                stack.append(x)
            stack.append(')')
        else:
            for x in reversed(top):
                stack.append(x)
    else:
        stack.append(ch)

print(''.join(stack))
