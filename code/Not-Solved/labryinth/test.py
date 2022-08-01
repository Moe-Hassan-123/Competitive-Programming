from collections import defaultdict, deque
import os, io

input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def get_input():
    return input().decode().rstrip("\n\r")

def populate_graph(m):
    if m <= 3:
        return
    graph = defaultdict(list)
    for _ in range(m):
        s, e = list(map(int, get_input().split()))
        graph[s].append(e)
    return graph
        
def main():
    _ , edgeN, s = list(map(int, get_input().split()))
    graph = populate_graph(edgeN)
    if graph == None:
        print("Impossible")
        return
    answers = solve(graph, s)
    answers = [list(x) for x in set(tuple(x) for x in answers)]
    if len(answers) != 2: print("Impossible")
    else:
        f, s = answers
        for i in range(1,len(f)-1):
            for j in range(1,len(s)-1):
                if f[i] == s[j]:
                    f = f[:i+1]
                    s = s[:j+1]
                    break
        answers = f,s
        print(f"Possible")
        for answer in answers:
            print(len(answer))
            print(*answer)

def solve(graph, s):
    def DFS(current_vertex, end_vertex = None,visited = None):
        """" This function should detect if there are 2 path in the graph
            that are >= 2 and start in the same point and don't have any crossover
        """
        visited = []
        stack = deque()
        stack.append(current_vertex)
        while stack:
            current_vertex = stack.popleft()
            print(visited)
            if current_vertex not in visited:
                visited.append(current_vertex)        
                if current_vertex == end_vertex:
                    answers.append(visited)
                    break
                for vertex in graph[current_vertex]:
                    stack.append(vertex)
        
        return visited
    answers = []
    # for vertex in graph[s]:
    # answers.append(DFS(graph,2))
    print(DFS(s))
    return answers

main()
