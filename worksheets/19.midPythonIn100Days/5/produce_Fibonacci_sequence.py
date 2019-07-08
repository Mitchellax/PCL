#!python3
max = 100
num1 = 1
num2 = 1
for i in range(0, max):
    print(num1, end=' ')
    temp = num1
    num1 = num2
    num2 = temp + num1
