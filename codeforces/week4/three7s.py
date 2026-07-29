t = int(input())
for _ in range(t):

    m = int(input())
    participants = []

    for i in range(m):
        count = int(input())

        participants.append(set(map(int, input().split())))

    # print(participants)
    possible_winners = []
    exclude = set()
    for i in range(m-1, -1, -1):
        possible_winners.append(participants[i] - exclude)
        exclude |= participants[i]
    possible_winners = possible_winners[::-1]
    # print(possible_winners)
    done = False
    for i in possible_winners:
        if len(i)==0:
            print(-1)
            done = True
            break

    if not done:
        for i in possible_winners:
            print(i.pop(), end = " ")
        print()
#1798B
