'''
Evan Hruskar
busnumbers2
2019-04-08 17:35:38
0.02 s
'''

max = 0
m = int(input())

seen = {}
c = [i**3 for i in range(0, 80)]

for i in range(1, 75):
    for j in range(i, 75):
        if c[i] + c[j] > m:
            break
        if (c[i] + c[j]) in seen.keys():
            seen[c[i] + c[j]] += 1
        else:
            seen[c[i] + c[j]] = 1

for k, v in seen.items():

    if v >= 2 and k > max:
        max = k

if max == 0:
    print('none')
else:
    print(max)
