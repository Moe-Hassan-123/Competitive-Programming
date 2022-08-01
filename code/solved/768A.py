def main():
    input()
    stewards = list(map(int, input().split()))
    if len(stewards) < 3:
        print(0)
        return
    stewards.sort()
    mx = stewards[-1]
    mn = stewards[0]
    stewards = list(filter(lambda i: i != mx and i != mn,stewards))
    stewards.append(mx)
    stewards.insert(0,mn)
    print(len(stewards[1:-1]))

main()
    