vars = {}

while True:
  try:
    line = input().split(" ")
    if line[0] == 'define':
      val = int(line[1])
      vars[line[2]] = val
    elif line[0] == 'eval':
      if line[1] not in vars or line[3] not in vars:
        print('undefined')
      else:
        a = vars[line[1]]
        b = vars[line[3]]
        r = None
        if line[2] == '<':
          r = a < b
        elif line[2] == '>':
          r = a > b
        else:
          r = a == b
        print('true' if r else 'false')
  except:
    break
