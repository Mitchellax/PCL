#!python3
for i in range(100, 1000):
    bit1 = i % 10
    bit10 = int((i % 100) / 10)
    bit100 = int(i / 100)
    if bit1**3 + bit10**3 + bit100**3 == i:
        print('There is a narcissistic number: %d' % i)
