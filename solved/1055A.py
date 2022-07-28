import io, os

input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
get_input = lambda : input().decode().rstrip("\n\r")
 
      
def main():
    _,  target  = [int(x) for x in get_input().split()]
    asc_dir = [int(x) for x in get_input().split()]
    des_dir = [int(x) for x in get_input().split()] 
    print("YES" if solve(asc_dir, des_dir, target-1) == True else "NO")
         
def solve(asc, des, target):
    if asc[0] != 1:
        return False
    if asc[target] == 0 and des[target] == 0:
        return False
    if asc[target] == 1:
        return True
    else:
        # Checks the Numbers after x for any number thats equal to one 
        # and its corresponding number in the other array is also 1
        if any((x == 1 and des[target+i] == 1) for i, x in enumerate(asc[target:])):
            if des[target] == 1:
                return True
        else:
            return False
    
main()