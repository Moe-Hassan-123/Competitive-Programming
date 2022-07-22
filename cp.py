import os
import io

input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline


def get_input():
    return input().decode().rstrip("\n\r")


def main():
    _, quests_no = [int(x) for x in get_input().split()]
    cols = [int(x) for x in get_input().split()]
    graph, rev_graph = create_graphs(cols)
    quests = []
    for _ in range(quests_no):
        # GET QUESTS
        quests.append([int(x) for x in get_input().split()])
    print(*solve(graph, rev_graph, quests), sep="\n")
    
        
        
def create_graphs(cols):
    graph = {}
    rev_graph = {}
    for i in range(0,len(cols)-1):
        x = cols[i] - cols[i+1]
        if x < 0:
            graph[i+1] = 0
            continue
        if x > 0:
            graph[i+1] = x
            continue            
        graph[i+1] = x
    for i in range(len(cols)-1, -1,-1):
        x = cols[i] - cols[i-1]
        if x < 0:
            rev_graph[i] = 0
            continue
        if x > 0:
            rev_graph[i] = x
            continue 
        rev_graph[i] = x
    return graph, rev_graph


def solve(graph, rev_graph, quests):
    answers = []
    for quest in quests:
        fr = quest[0]
        to = quest[1]
        if fr > to:
            total = 0
            for i in range(to, fr):
                total += rev_graph[i]
            answers.append(total)
        elif fr < to:
            total = 0
            for i in range(fr,to):
                total += graph[i]
            answers.append(total)
    return answers

main()
