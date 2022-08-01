import sys
get_input = lambda: sys.stdin.readline()


get_input() # Number Of Cards
cards = [int(x) for x in get_input().split()]
A = B = turn = 0
while(cards):
    ans = max((0,-1), key=lambda i: cards[i])
    val = cards.pop(ans)
    if turn%2 == 0: A += val
    else: B += val
    turn += 1
print(A,B)