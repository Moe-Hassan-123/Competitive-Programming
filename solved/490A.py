from collections import defaultdict

def main():
    input()
    
    students = list(map(int, input().split()))
    hashed_students = defaultdict(list)
    # O(n)
    for k,v in enumerate(students):
        hashed_students[v].append(k+1)
    # O(1)    
    if len(hashed_students) != 3:
        print(0)
        return
    # 3 Operations --> O(1)
    teams_count = len(hashed_students[min(hashed_students, key=lambda item: len(hashed_students[item]))])

    teams = []
    # O(teams_count * 3) -> O(3n)
    for i in range(teams_count):
        team = []
        for j in hashed_students.values():
            team.append(j.pop(0))
        teams.append(team)
        
    print(teams_count)
    for team in  teams:
        print(*team)

# O(4N) -> O(N)
main()