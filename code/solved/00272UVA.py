import re
import sys

get_input = lambda: sys.stdin.readline().rstrip("\n\r")

def main():
    s = get_input()
    n1= 0
    n2 = 0
    double_pattern = re.compile("\"")
    single_pattern = re.compile("[^']'[^']")
    for i in range(len(s)):
        if n1 % 2 == 0:
            s = re.sub(double_pattern, "``",s,1)
            n1 += 1
        else:
            s = re.sub(double_pattern, "''",s,1)
            n1 += 1
        if n2 % 2 == 0:
            s = re.sub(single_pattern, "`",s,1)
            n2 += 1
        else:
            s = re.sub(single_pattern, "'",s,1)
            n2 += 1
    print(s)
    
main()