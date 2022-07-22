from collections import defaultdict, deque
import os
import io
from tracemalloc import start

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
    _, edgeN, s = list(map(int, get_input().split()))
    graph = populate_graph(edgeN)
    if graph == None:
        print("Impossible")
        return
    answers = solve(graph, s)
    answers = [list(x) for x in set(tuple(x) for x in answers)]
    if len(answers) != 2:
        print("Impossible")
    else:
        f, s = answers
        for i in range(1, len(f)-1):
            for j in range(1, len(s)-1):
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
    def DFS(graph, visited, current_vertex, start_vertex, path=None):
        """" This function should Traverse the graph for every possible path from the starting point
        """
        if current_vertex in visited:
            return path
        visited.append(current_vertex)
        if path != None:
            path.append(current_vertex)

        # Non Branching Paths
        if len(graph[current_vertex]) == 1:
            if current_vertex == start_vertex:
                return
            return DFS(graph, visited,graph[current_vertex][0],start_vertex,path)

        # End of Paths
        if len(graph[current_vertex]) == 0:
            return path

        # Main Paths - Answers
        if current_vertex == start_vertex:
            for vertex in graph[current_vertex]:
                path = [start_vertex]
                answer = DFS(graph, visited,vertex,start_vertex,path)
                answers.append(answer)
                end_vertex = path[-1]
                visited.remove(end_vertex)
                path = None
            return path
                
        # Branching Paths
        # How should i do it?
    answers = []
    visited = []
    DFS(graph, visited,s,s)
    return answers


main()
