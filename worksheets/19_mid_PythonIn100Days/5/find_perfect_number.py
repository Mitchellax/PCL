#! python3
# max = input('Set the maximum range: ')
max = 10000
for i in range(4, max):
    factors_list = []
    for j in range(1, i):
        if i % j == 0:
            factors_list.append(j)
    factors_sum = 0
    for k in factors_list:
        factors_sum += k
    if factors_sum == i:
        print('There is a perfact number: %d' % i)