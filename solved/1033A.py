from math import sqrt
from os import sep
import sys

get_input = lambda: sys.stdin.readline()
get_list = lambda: [int(x) for x in get_input().split()]

def index(l, row,col) -> int:
    return int(row * sqrt(l) + col)
    
def main():
    size = int(get_input())
    q_x, q_y = get_list()
    k_x, k_y = get_list()
    req_x, req_y = get_list()
    if (req_x > q_x > k_x) or (k_x > q_x > req_x):
        print("NO")
        return
    if (req_y > q_y > k_y) or (k_y > q_y > req_y):
        print("NO")
        return
    print("YES")
    return
main()