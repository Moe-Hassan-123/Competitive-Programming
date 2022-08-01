import sys
import graphlib

def get_int():
    return [int(x) for x in sys.stdin.readline().strip("\n\r").split()]


graph = {}
initial = []


def solve():
    for node in graph:
        if visited[node-1] == False:
            top_sort(node)
    if len(initial) < total:
        for i in range(1, total+1):
            if i not in initial:
                initial.insert(0, i)
    final = [0 for _ in range(total)]
    pos = 0
    for i in range(total-1, -1, -1):
        current = initial[i]
        final[current-1] = pos
        pos = current
    print(*final, sep="\n")


def top_sort(node):
    visited[node - 1] = True
    if node in graph:
        for next in graph[node]:
            if visited[next - 1] == False:
                top_sort(next)
    initial.append(node)


if __name__ == "__main__":
    total, n = get_int()
    visited = [False for _ in range(total)]
    for i in range(1, n + 1):
        _, *edges = get_int()
        for wish in edges:
            if i in graph:
                graph[i].append(wish)
            else:
                graph[i] = [wish]
    solve()
    sys.exit(0)
