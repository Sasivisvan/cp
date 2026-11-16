#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C
from collections import defaultdict
import math

Path = [800, 600, 750, 900, 1400, 1200, 1100, 1500]
BusStops = [ "TH", "GA", "IC", "HA", "TE", "LU", "NI","CA" ]

d = defaultdict(int)
sumpath = [0]
totalSum = sum(Path)
for i in range(len(Path)):
    sumpath.append(sumpath[-1]+Path[i])

for i in range(len(BusStops)):
    d[BusStops[i]] = i


def getFair(source, dest):
    source = d[source]
    dest = d[dest]

    if dest>=source:
        return math.ceil((sumpath[dest+1] - sumpath[source+1])/200)
    else:
        return math.ceil((totalSum - (sumpath[source+1] - sumpath[dest+1]))/200)


print(getFair("TH", "GA"))


