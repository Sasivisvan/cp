t = int(input(""))

for _ in range(t):
    
    n,Ax,Ay,Bx,By = tuple(map(int,input().split(" ")))
    Bx = Bx-Ax
    By = By-Ay
    def Axfun(x):
        return int(x)-Ax
    def Ayfun(x):
        return int(x)-Ay
    
    x = list(tuple(map(Axfun,input().split(" "))))
    y = list(tuple(map(Ayfun,input().split(" "))))
    