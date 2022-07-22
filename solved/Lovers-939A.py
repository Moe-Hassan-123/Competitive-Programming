from collections import deque
import os
import io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline


def get_input():
    return input().decode().rstrip("\n\r")


def main():
    input()
    lovers = list(map(int, get_input().split()))
    lovers = {k+1:v for k,v in enumerate(lovers)}
    print(solve(lovers))


def solve(lovers):
    def DFS(next,start_node):
        stack = deque()
        stack.append(start_node)
        triangle = []
        while stack:
            cur = stack.pop()
            triangle.append(cur)
            stack.appendleft(next[cur])
            if len(triangle) == 3 and next[cur] == lover:
                return True
            elif len(triangle) == 3:
                return False
            else:
                continue
                
    for lover in lovers:
        if DFS(lovers, lover) == True:
            return "YES"
    return "NO"
            

main()
