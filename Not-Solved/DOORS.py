from collections import deque
import io, os
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def get_input():
    return input().decode().rstrip("\n\r")


def main():
    _, req = [int(x) for x in get_input().split()]
    data = [int(x) for x in get_input().split()]
    print(solve(data, req))

def solve(data: list ,req):
    ## Helper functions
    def construct_graph(data):
        return {k+1:v+k+1 for k,v in enumerate(data)}
    
    def DFS(graph, start_node, end_node):
            stack = deque()
            stack.append(start_node)
            while stack:
                cur = stack.pop()
                if cur == end_node: return True
                try: stack.append(graph[cur])
                except KeyError: return False

    graph = construct_graph(data)
    if DFS(graph, 1, req) == True:
        return "YES"
    else:
        return "NO"
    
main()