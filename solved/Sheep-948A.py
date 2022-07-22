import os
import io


input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline


def get_input():
    return input().decode().rstrip("\n\r")


def main():
    rows, cols = list(map(int, get_input().split()))
    matrix = []
    for row in range(rows):
        matrix.append(list(get_input()))
    ans = solve(matrix,rows,cols)
    if ans == "No":
        print("NO")
    else:
        print("Yes")
        for i in ans:
            print("".join(i))


def solve(matrix, rows, cols):
    for r in range(rows):
        for c in range(cols):
            if matrix[r][c] == "S":
                # Check The 4 surrounding spaces for a wolf
                # if a wolf exists, then its impossible
                # Else add a dog to guard the sheep
                status = True
                if r != 0:
                    if matrix[r-1][c] == "W":
                        return "No"
                    if matrix[r-1][c] == ".":
                        matrix[r-1][c] = "D"
                if r != rows-1:
                    if matrix[r+1][c] == "W":
                        return "No"
                    if matrix[r+1][c] == ".":
                        matrix[r+1][c] = "D"
                if c != 0:
                    if matrix[r][c-1] == "W":
                        return "No"
                    if matrix[r][c-1] == ".":
                        matrix[r][c-1] = "D"
                if c != cols-1:
                    if matrix[r][c+1] == "W":
                        return "No"
                    if matrix[r][c+1] == ".":
                        matrix[r][c+1] = "D"
                if status == False:
                    return "No"
    return matrix

main()
