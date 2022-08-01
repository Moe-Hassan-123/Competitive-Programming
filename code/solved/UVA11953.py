import sys
get_input = lambda: sys.stdin.readline().rstrip("\n\r")

ans = []
def dfs(graph, row, col, wanted=0):
    letters = "IEHOVA#"
    if wanted == 7:
        return
    for delta in [1,-1]:
        if col+delta > len(graph[0])-1:
            continue
        if graph[row][col+delta] == letters[wanted]:
            ans.append("right" if delta == 1 else "left")
            return dfs(graph, row,col+delta, wanted+1)
    ans.append("forth")
    return dfs(graph, row-1,col,wanted+1) 

if __name__ == "__main__":
    for _ in range(int(get_input())):
        steps, __ = list(map(int, get_input().split()))
        graph = []
        for step in range(steps):
            graph.append(list(get_input()))
        col = graph[-1].index("@")
        row = len(graph)-1
        dfs(graph, row, col)
        print(*ans)
        ans = []