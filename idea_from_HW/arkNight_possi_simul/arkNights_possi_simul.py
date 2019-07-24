#!python3
import random
import math
from matplotlib import pyplot as plt
from matplotlib import numpy as np

def possi(value):
    if random.random() < value:
        return True
    else:
        return False

class Lottery_simul:
    # simulator
    lot_count = 0
    _no_senior_times = 0
    _senior_times = 0
    _all_times = 0
    def __init__(self):
        self.lot_count += 1
    def _do(self):
        self._all_times += 1
        if self._no_senior_times <= 50:
            if possi(0.02):
                self._no_senior_times = 0
                self._senior_times += 1
            else:
                self._no_senior_times += 1
        else:
            if possi(self._no_senior_times - 49) * 0.02:
                self._no_senior_times = 0
                self._senior_times += 1
            else:
                self._no_senior_times += 1

    def _refer_do(self):
        self._all_times += 1
        if possi(0.02):
            self._no_senior_times = 0
            self._senior_times += 1
        else:
            self._no_senior_times += 1

    def calcu_possi(self, times):
        self._no_senior_times = 0
        self._senior_times = 0
        for i in range(0, times):
            self._do()
        if self._no_senior_times <= 50:
            return 0.02
        else:
            return ((self._no_senior_times - 49) * 0.02)

    def calcu_multi_possi(self, times):
        self._no_senior_times = 0
        self._senior_times = 0
        for i in range(0, times):
            self._do()
        return self._senior_times / self._all_times

    def calcu_refer_possi(self, times):
        self._no_senior_times = 0
        self._senior_times = 0
        for i in range(0, times):
            self._refer_do()
        return self._senior_times / self._all_times

    def calcu_multi_times(self, times):
        self._no_senior_times = 0
        self._senior_times = 0
        for i in range(0, times):
            self._do()
        return self._senior_times

    def calcu_refer_times(self, times):
        self._no_senior_times = 0
        self._senior_times = 0
        for i in range(0, times):
            self._refer_do()
        return self._senior_times

if __name__ == "__main__":
    possibility = [] # beginning with 1 and step by 10
    multi_possibility = []
    refer_possibility = []
    multi_times = []
    refer_times = []
    max_times = 501
    test_times = 1000

    for i in range(1, max_times, 10):
        temp_list1 = []
        temp_list2 = []
        temp_list3 = []
        temp_list4 = []
        temp_list5 = []
        for j in range(test_times):
            temp_list1.append(Lottery_simul().calcu_possi(i))
            temp_list2.append(Lottery_simul().calcu_multi_possi(i))
            temp_list3.append(Lottery_simul().calcu_refer_possi(i))
            temp_list4.append(Lottery_simul().calcu_multi_times(i))
            temp_list5.append(Lottery_simul().calcu_refer_times(i))
        possibility.append(np.mean(temp_list1))
        multi_possibility.append(np.mean(temp_list2))
        refer_possibility.append(np.mean(temp_list3))
        multi_times.append(np.mean(temp_list4))
        refer_times.append(np.mean(temp_list5))

    plt.figure(figsize=(8, 6), dpi=80, num=1)
    X = np.arange(1, max_times, 10)
    plt.plot(X, possibility, color='black', label='next time possibility')
    plt.plot(X, multi_possibility, label='simulating possibility')
    plt.plot(X, refer_possibility, color='blue', label='referencing possibility')
    plt.ylim(0, 0.05)
    plt.legend(loc='upper left')
    plt.savefig('1.png')

    plt.figure(figsize=(8, 6), dpi=80, num=2)
    X = np.arange(1, max_times, 10)
    plt.plot(X, multi_times, color='black', label='simulatiing winning record')
    plt.plot(X, refer_times, color='blue', label='referencing winning record')
    plt.legend(loc='upper left')
    plt.savefig('2.png')
    plt.show()