from collections import defaultdict
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
        answers = f, s
        print(f"Possible")
        for answer in answers:
            print(len(answer))
            print(*answer)

def solve(graph, s):
    def DFS(graph, current_vertex, start_vertex = None, end_vertex = None,visited = None):
        """" This function should detect if there are 2 path in the graph
            that are >= 2 and start in the same point and don't have any crossover
        """
        if visited == None: visited = []
        try:
            answers[1]
            end_vertex = answers[0][-1]
        except:
            pass
        if current_vertex in visited: return visited
        visited.append(current_vertex)
    
        if current_vertex == end_vertex: return visited
        for vertex in graph[current_vertex]:
            if vertex == end_vertex:
                visited.append(end_vertex)
                return visited
        for vertex in graph[current_vertex]:
            if current_vertex == start_vertex:
                if len(answers) == 2: break
                visited = [start_vertex]
                answers.append(visited)
            DFS(graph, vertex, start_vertex,end_vertex,visited)
        return visited
    answers = []
    DFS(graph,s ,s)
    return answers

main()
