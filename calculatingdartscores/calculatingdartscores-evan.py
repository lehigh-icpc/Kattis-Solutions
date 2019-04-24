'''
Fixed bug: now considering combinations of size 1 and 2 now as well.
'''

# 3 SUM problem
import itertools

n = int(input())

values = []
for i in range(1, 20 + 1):
    values.append(i)
    values.append(i*2)
    values.append(i*3)

# just brute for with O(n^3)
combinations_1 = itertools.combinations_with_replacement(values, 1)
combinations_2 = itertools.combinations_with_replacement(values, 2)
combinations_3 = itertools.combinations_with_replacement(values, 3)

combinations_all = list(combinations_1) + list(combinations_2) + list(combinations_3)

for comb in combinations_all:
    if sum(comb) == n:
        for value in comb:
            if value in [i*3 for i in range(1, 20 + 1)]:
                print('triple {}'.format(int(value / 3)))
            elif value in [i*2 for i in range(1, 20 + 1)]:
                print('double {}'.format(int(value / 2)))
            elif value in range(1, 20 + 1):
                print('single {}'.format(value))
            
        exit()
print('impossible')
