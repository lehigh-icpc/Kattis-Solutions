#   2 3   5
# _ X X _ X _
# _ X X X _ _

#     3   5       9
# _ _ X _ X _ _ _ X _
# _ _ _ _ X X _ _ X _
# _ _ _ _ _ X X _ X _
# _ _ _ _ _ _ X X X _

# Largest number of moves = max(dist(a,b), dist(b,c)) - 1
a, b, c = [int(x) for x in input().split(' ')]
print(max(b - a, c - b) - 1)
