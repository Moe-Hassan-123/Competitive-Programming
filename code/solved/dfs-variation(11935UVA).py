import sys

def get_input(): return sys.stdin.readline().rstrip("\n\r")
sys.setrecursionlimit(int(1e9))

def all(x,y):
    visit(x+1, y, True)
    visit(x-1, y, True)
    visit(x, y-1, True)
    visit(x, y+1, True)


def visit(x, y, group=False):
    if x < 0 or y < 0 or x >= l or y >= l:
        return False
    
    if visited[x][y] == 0:
        visited[x][y] = 1
        if group == True:
            if graph[x][y] == "x" or graph[x][y] == "@":
                all(x,y)
        else:
            if graph[x][y] == "x":
                group = True
                all(x,y)
                return True
    return False


if __name__ == "__main__":
    for count in range(int(get_input())):
        graph = []
        ans = 0
        for line in range(int(get_input())):
            graph.append(list(get_input()))
        l = len(graph)
        visited = [[0 for _ in range(l)] for _ in range(l)]
        for i in range(l):
            for j in range(l):
                if visited[i][j] == 1:
                    continue
                ans += visit(i, j)
        print(f"Case {count+1}: {ans}")
