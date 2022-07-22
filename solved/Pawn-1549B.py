import os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def get_input():
    return input().decode().rstrip("\n\r")

def main():
    for _ in range(int(get_input())):
        size = int(get_input())
        enemy = get_input()
        gregor = get_input()
        print(solve(size, list(enemy), list(gregor)))
    
def solve(size, enemy, gregor):
    ans = 0    
    for i in range(len(gregor)):
            if gregor[i] == "1":
                if enemy[i] == "0":
                    enemy[i] = "2"
                    ans += 1
                    continue
                if enemy[i-1] == "1" and i > 0:
                    enemy[i-1] = "2"
                    ans += 1
                    continue
                if i < len(gregor) - 1:
                    if enemy[i+1] == "1":
                        enemy[i+1] = "2"
                        ans += 1
                        continue

    return ans
main()

        