n = int(input())
snacks = list(map(int, input().split()))
taken = []
max = n
for i in range(n):
    if snacks[i] == max:
        