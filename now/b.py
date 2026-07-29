t = int(input(""))

for _ in range(t):
    n = int(input(""))
    s = input()
    
    flag = False 
    
    for i in range(len(s)-1):
        ts = s[i:i+2]
        
        if "?" in ts:
            pass
        else:
            if "a" in ts and "b" in ts:
                pass
            else:
                print("NO")
                flag = True
                break
                
    if not flag:
        print("YES")