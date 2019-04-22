coords = []
N = int(input())
for i in range(N):
  coords.append([float(x) for x in input().split(" ")])

minoverall = float('inf')

for i in range(N):

  [x0, y0] = coords[i-1]
  [x1, y1] = coords[i]

  # get line in the form of ax + by + c = 0
  a = (y0-y1)
  b = (x1-x0)
  c = x0*y1 - x1*y0
  
  # find largest distance to all points from this line
  maxdistfromthis = 0
  # denominator is constant
  denom = (a*a + b*b)**.5
  for [x, y] in coords:
    dist = abs(a * x + b * y + c)/denom
    if dist > maxdistfromthis:
      maxdistfromthis = dist
  if maxdistfromthis < minoverall:
    minoverall = maxdistfromthis

print(minoverall)
