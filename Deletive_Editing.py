import os, io

input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def get_input():
    return input().decode().rstrip("\n")


def main():
    for _ in range(int(get_input())):
        s, e = get_input().split()
        print("YES" if solve(s, e) else "NO") 


def solve(s: str, e: str) -> bool:
    def calc_occurences(array):
        occ = {}
        for c in array:
            if c in occ: occ[c] += 1
            else: occ[c] = 1
        return occ
    
    # Remove Unnecessary letters
    temp = s
    for c in s:
        if c not in e:
            temp = temp.replace(c,"", 1)
    s = temp
    s_occ = calc_occurences(s)
    e_occ = calc_occurences(e)

    if len(s_occ) != len(e_occ): return False
    
    for key in s_occ:
        diff = s_occ[key] - e_occ[key]
        if diff < 0:
            return False
        s = s.replace(key, "", diff)

    return True if s == e else False


        
main()
