'''
TODO: There are probably still major optimzations which can be done. My submission is currently the slowest python3 submission at 0.97 sec

instead of checking the moves of all possible knights.
pretend the blank space is a knight and swap it with all valid moves.

early termination trick: take the sum of the upper triangle. (Sped up program by 10.81 times)
Must be:
move# <= resulting sum of upper triangle - 2
worst case:
move#, resulting sum of upper triangle
0, 2
1, 3
2, 4
...
10, 12 (correct finish)


'''

import queue
# import cProfile

def to_tup(board):
    return tuple([tuple(row) for row in board])

def to_list(board):
    return list([list(row) for row in board])

def sum_triag(board):
    sum = 0
    for i in range(4):
        for j in range(i, 5):
            if board[i][j] == ' ' or (i == 2 and j == 2) or (i == 3 and j == 3): # 4,4 case is handled in i range(4)
                continue
            sum += int(board[i][j])
    return sum

def add(offset, index, b, b_tup, q, distance):
    b_tmp = [row.copy() for row in b] # Just using regular copy() is shallow! This was a nasty bug!
    b_tmp[index[0]][index[1]], b_tmp[index[0] + offset[0]][index[1] + offset[1]] = b_tmp[index[0] + offset[0]][index[1] + offset[1]], b_tmp[index[0]][index[1]]
    b_tmp_tup = to_tup(b_tmp)
    if b_tmp_tup not in distance:
        distance[b_tmp_tup] = distance[b_tup] + 1
        q.put(b_tmp_tup)
        # print('Distance: {}'.format(distance[b_tmp_tup]))
        # for row in b_tmp:
        #     print(row)

n = int(input())
goal = [['1', '1', '1', '1', '1'],
        ['0', '1', '1', '1', '1'],
        ['0', '0', ' ', '1', '1'],
        ['0', '0', '0', '0', '1'],
        ['0', '0', '0', '0', '0']]
for i in range(n):
    # Read in board
    target_board = [list(input()) for x in range(5)]
    # print('Distance: 0')
    # for row in target_board:
    #     print(row)

    # Do 10 iterations of BFS
    q = queue.Queue()
    q.put(to_tup(target_board))
    distance = {to_tup(target_board) : 0}   #map of board to # of steps
    while not q.empty():
        b_tup = q.get()
        b = to_list(b_tup)
        if b == goal:
            print('Solvable in {} move(s).'.format(distance[b_tup]))
            break
        if distance[b_tup] > sum_triag(b) - 2 or distance[b_tup] == 10: #enormous early termination, see header
        # if distance[b_tup] == 10:
            continue

        # find blank space
        for row_num, row in enumerate(b):
            for col_num, elem in enumerate(row):
                if elem == ' ':
                    index = [row_num, col_num]
        # go from top row to bottom
        if index[0] >= 2:
            if index[1] >= 1:
                add((-2, -1), index, b, b_tup, q, distance)
            if index[1] <= 3:
                add((-2, 1), index, b, b_tup, q, distance)
        if index[0] >= 1:
            if index[1] >= 2:
                add((-1, -2), index, b, b_tup, q, distance)
            if index[1] <= 2:
                add((-1, 2), index, b, b_tup, q, distance)
        if index[0] <= 3:
            if index[1] >= 2:
                add((1, -2), index, b, b_tup, q, distance)
            if index[1] <= 2:
                add((1, 2), index, b, b_tup, q, distance)
        if index[0] <= 2:
            if index[1] >= 1:
                add((2, -1), index, b, b_tup, q, distance)
            if index[1] <= 3:
                add((2, 1), index, b, b_tup, q, distance)
    if b != goal: # out of while loop, and we don't find it.
        print('Unsolvable in less than 11 move(s).')
