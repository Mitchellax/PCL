#!python3
'''
RULE: player cast two dice with each dice is 1 to 6. 
In the first turn:
    if the sum of two dice is 7 or 11, player win; 
    if the sum of two dice is 2, 3 or 12, player lose;
    else, record the sum and continue to cast dice:
        if the sum of dice equal to the record, player win;
        if the sum of dice equal to 7 then player lose;
        continue cast with other value.
'''

import random

def cast_dice():
    return [random.randint(1, 6), random.randint(1, 6)]

def make_sum(values):
    sum = 0
    for i in values:
        sum += i;
    return sum

dice = cast_dice()
sum_first = make_sum(dice)
if sum_first == 7 or sum_first == 11:
    print('Player wins in turn 1 with dice ', dice)
elif sum_first == 2 or sum_first == 3 or sum_first == 12:
    print('Player loses in turn 1 with dice ', dice)
else:
    turns = 1
    sum = 0
    while (sum != sum_first and sum != 7):
        dice = cast_dice()
        sum = make_sum(dice)
        turns += 1
    if sum == sum_first:
        print('Player wins in turn ', turns, ' with dice ', dice)
    else:
        print('Player loses in turn ', turns, ' with dice ', dice)