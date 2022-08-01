def main():
    q = input()
    word = input()
    left, right = make_dict()
    ans = list(map(lambda i: right[i], word)) if q == "R" else list(map(lambda i : left[i], word))
    print(*ans, sep="")


def make_dict():
    a = "qwertyuiop"
    b = "asdfghjkl;"
    c = "zxcvbnm,./"
    r = {}
    l = {}
    for row in [a, b, c]:
        r |= ({v:row[i-1] for i,v in enumerate(row) if v not in ["q", "a", "z"]})
        l |= {v:row[i+1] for i,v in enumerate(row) if v not in ["p", ";", "/"]}
    return l, r
    
main()