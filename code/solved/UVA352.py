import sys

sys.setrecursionlimit(int(1e9))
get_pixels = lambda: sys.stdin.readline().rstrip()
get_int = lambda: int(get_pixels())


global is_visited

def main():
    n = 1
    while True:
        matrix = []
        try: t = get_int()
        except: return
        for _ in range(t):
            matrix.append(list(map(int, get_pixels())))
        print(f"Image number {n} contains {solve(matrix)} war eagles.")
        matrix = []
        n += 1


def solve(matrix):
    global is_visited
    is_visited = [[False for _ in range(len(matrix))] for _ in range(len(matrix))]
    groups = 0
    for row in range(len(matrix)):
        for col in range(len(matrix)):
            if is_visited[row][col] == True:
                continue
            else:
                groups += is_connected(row, col, matrix)
    return groups

def is_connected(x,y,matrix):
    global is_visited
    group = False
    for i in range(-1, 2):
        for j in range(-1, 2):
            if x+i < 0 or y+j < 0:
                continue
            try:
                if matrix[x+i][y+j] == 1 and is_visited[x+i][y+j] == False:
                        is_visited[x+i][y+j] = True
                        is_connected(x+i, y+j, matrix)
                        group = True
            except IndexError: pass
    
    if group: return True
    else: return False

main()