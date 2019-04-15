# from sys import stdin
#maps strings to ints
map = {}

# stuff = input()
while True:
    try:
        stuff = input()
        line = stuff.split()
        if line[0] == 'define':
            map[line[2]] = int(line[1])
        else: #it's eval
            # first undefined case
            if line[1] in map and line[3] in map:
                if line[2] == '<':
                    if map[line[1]] < map[line[3]]:
                        print('true')
                    else:
                        print('false')
                elif line[2] == '>':
                    if map[line[1]] > map[line[3]]:
                        print('true')
                    else:
                        print('false')
                elif line[2] == '=':
                    if map[line[1]] == map[line[3]]:
                        print('true')
                    else:
                        print('false')
            else:
                print('undefined')
            # stuff = input()
    except EOFError:
        break
