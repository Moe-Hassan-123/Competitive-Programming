import datetime

def main():
    while True:
        d = int(input())
        if d == 0: return
        dates = []
        consumption = []
        for _ in range(d):
            d, m, y, c = map(int, input().split())
            dates.append(datetime.datetime(y,m,d))
            consumption.append(c)
        print(*solve(dates, consumption))

def solve(dates, consumption):
    next_day = datetime.timedelta(1)
    n = 0
    c = 0
    for i in range(len(dates)-1):
        if dates[i] + next_day == dates[i+1]:
            c += (consumption[i+1] - consumption[i])
            n += 1
    return n, c 
main()