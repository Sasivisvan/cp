
t = int(input())

for _ in range(t):
    count = int(input())
    candies = list(map(int, input().split(" ")))

    ateMap = dict()
    ateSet = set()

    #build from left to right
    LtoR = [0]
    for i in range(len(candies)):
        LtoR.append(LtoR[i]+candies[i])
    LtoR = LtoR[1:]

    candies = candies[::-1]
    RtoL = [0]
    for i in range(len(candies)):
        RtoL.append(RtoL[i]+candies[i])
        ateSet.add(RtoL[i]+candies[i])
        ateMap[RtoL[i]+candies[i]] = i+1


    RtoL = RtoL[1:]

    candies = candies[::-1]

    maxCandiesAte = 0
    # print("LtoR:",LtoR)
    # print("RtoL",RtoL)
    for i,n in enumerate(LtoR):
        # print(i,n)

        if n in ateSet:
            if (count-ateMap[n])>i:
                maxCandiesAte = max(maxCandiesAte, i+1+ateMap[n])
                # print("inside same values found:",i+1, ateMap[n])
    print(maxCandiesAte)


