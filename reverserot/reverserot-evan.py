rot = list("ABCDEFGHIJKLMNOPQRSTUVWXYZ_.")

while True:
    line = input().split(' ')
    n = int(line[0])
    if n == 0:
        break
    string = line[1]
    string_rev = reversed(string)
    arr_rev_rot = []
    for char in string_rev:
        pos = rot.index(char)
        arr_rev_rot.append(rot[(pos + n) % len(rot)])
    print(''.join(arr_rev_rot))
