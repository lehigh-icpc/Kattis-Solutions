'''
Evan Hruskar
treehouses
2019-04-15 18:56:30
Using itemgetter: 2.06 s -> 2.04 s
'''

import math
from operator import itemgetter

def distance(p1, p2):
    return math.sqrt((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2)

def find(x):
    while x != links[x]:
        x = links[x]
    return x

def same(a, b):
    return find(a) == find(b)

def unite(a, b):
    a, b = find(a), find(b)
    if sizes[a] < sizes[b]:
        sizes[b] += sizes[a]
        links[a] = b
    else:
        sizes[a] += sizes[b]
        links[b] = a

dist = 0
points = []
edges = []

n, e, p = [int(x) for x in input().split()]

links = [i for i in range(n)]
sizes = [0] * n

# Reading in points
for i in range(n):
    x, y = [float(x) for x in input().split()]
    if e != 0:
        links[i] = 0
        sizes[i] = 0
        sizes[0] += 1
        points.append((x, y, i)) # id = index + 1
        e -= 1
    else:
        links[i] = i
        sizes[i] = 1
        points.append((x, y, i))

# Creating new connections
for i in range(p):
    i1, i2 = [int(x) - 1 for x in input().split()]
    if not same(i1, i2):
        unite(i1, i2)

# Creating edges TODO: User itertools here instead?
for p1 in points:
    for p2 in points:
        edges.append((p1, p2, distance(p1, p2)))

# Sort the edges by distance TODO: Use itemgetter?
# sorted_edges = sorted(edges, key=lambda tup : tup[2])
sorted_edges = sorted(edges, key=itemgetter(2))

# Creating the MST
for edge in sorted_edges:
    if not same(edge[0][2], edge[1][2]):
        unite(edge[0][2], edge[1][2])
        dist += edge[2]

print(dist)
