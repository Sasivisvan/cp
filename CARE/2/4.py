
arr = [7,4,8,2,9]
 
max_element = -1
count =0
for i in arr:
    if i>max_element:
        max_element = i
        count+=1
print(count)
