import sys

get_input = lambda: sys.stdin.readline()

def main():
    coorrdinates = [int(x) for x in get_input().split()]
    answers = list()
    answers.append(rook(*coorrdinates))
    answers.append(bishop(*coorrdinates))
    answers.append(king(*coorrdinates))
    print(*answers)


def bishop(start_x,start_y, end_x, end_y):
    if (start_x + start_y) % 2 == (end_x + end_y) % 2:
        # TODO DETECT two pieces are on the same diagonal
        if abs(end_x - start_x) == abs(end_y - start_y):
            return 1
        else:
            return 2   
    else:
        return 0
    
def rook(start_x, start_y, end_x, end_y):
    # Increases X or Y per time by an arbitarty number
    if start_x == end_x and start_y != end_y:
        return 1
    if start_y == end_y and start_x != end_x:
        return 1
    else:
        return 2

def king(start_x,start_y, end_x, end_y):
    # Changes X or Y by 1 OR Changes Both of them by 1 (Diagnoal Movement) 
    if start_x == end_x:
        return abs(end_y - start_y)
    if start_y == end_y:
        return abs(end_x - start_x)
    
    if abs(end_x - start_x) == abs(end_y - start_y):
          return abs(end_y - start_y)
      
    return max(abs( end_x - start_x ), abs( end_y - start_y ))
main()