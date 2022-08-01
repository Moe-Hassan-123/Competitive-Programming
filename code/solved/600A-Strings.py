import io, os
from re import split
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def get_input():
    return input().decode().rstrip("\n\r")

def main():
    values = get_input()
    values = split(",|;", values)
    numbers = []
    rest = []
    for value in values:
        if value.isnumeric():
            if not (value[0] == "0" and len(value) != 1):
                numbers.append(value)
            else:
                rest.append(value)
        else:
            rest.append(value)
    if numbers:
        print('"',end="")
        print(*numbers, sep=",",end="")
        print('"')
    else:
        print('-')
    if rest:
        print('"',end="")
        print(*rest, sep=",",end="")
        print('"')
    else:
        print('-')
    
def solve():
    ...

main()