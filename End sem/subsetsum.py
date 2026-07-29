from collections import deque
nums = {3,4,6,8,9,13}
target = 12
#DFS
stack = deque()
stack.append([])
while(len(stack)!=0):

    ele = stack.pop()

    if sum(ele)>target:
        continue
    elif sum(ele) == target :
        print(ele)
    else:
        for i in nums:
            new = ele[::]
            if i not in new:
                new.append(i)
                stack.append(new)

