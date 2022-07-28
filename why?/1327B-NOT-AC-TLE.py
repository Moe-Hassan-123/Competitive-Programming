import sys

get_input = lambda: sys.stdin.readline()

def main():
    for _ in range(int(get_input())):
        answer = solve(int(get_input()))
        if answer == None:
            print("OPTIMAL\n")
        else:
            print("IMPROVE")
            print(*answer)

def solve(n):
    married = {}
    for queen in range(n):
        s , *targets = [int(x) for x in get_input().split()]
        for prince in targets:
            if prince not in married:
                married[prince] = queen+1
                break
    if len(married) < n:
        for queen in range(1,n+1):
            if queen not in married.values():
                prince = next((prince for prince in range(1,n+1) if prince not in married), None)
                if prince != None:
                    return queen, prince
                else:
                    return None
    return None

main()
