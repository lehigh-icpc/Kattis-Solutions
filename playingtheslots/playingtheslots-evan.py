import math

n = int(input())
points = [[float(x) for x in input().split(" ")] for i in range(n)]

# vector is just an x and a y component.

def dist(p1, p2):
    return math.sqrt((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2)

# vecs = []
min_dist = math.inf
for i in range(n):
    p1 = points[i-1] #This also does the end -> beginning points
    p2 = points[i]
    d1 = dist(p1, p2)
    max_point = 0
    for p in points:
        if (p == p1):
            continue
        d2 = dist(p1, p)
        c = dist(p, p2)
        s = d2 * math.sin(math.acos((d1**2 + d2**2 - c**2) / (2 * d1 * d2)))
        max_point = max(max_point, s)
    min_dist = min(min_dist, max_point)

print(min_dist)
