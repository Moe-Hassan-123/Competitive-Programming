import os
import io
from time import time_ns
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline


def get_input():
    return input().decode().rstrip("\n\r")


def main():
    key = int(get_input())
    doors = [int(x) for x in get_input().split()]
    data = {k+1:v for k,v in enumerate(doors)}
    print("YES" if solve(data, key) == True else "NO")
    
def solve(data, key):
    closed = 3
    doors = [1,2,3]
    while closed > 0:
        if key not in doors:
            return False
        else:
            closed -= 1
            key = data[key]
    return True
        
main()
