#!/usr/bin/env python

import math

max_int_to_test = 6*math.factorial(9)

def curious_sum(n):
    """Returns the sum of the factorial of n's digits"""
    s = 0
    while n > 0:
        digit = n%10
        s += math.factorial(digit)
        n = (n - digit) / 10
    return s

def is_curious_sum(n):
    return n == curious_sum(n)

if __name__ == '__main__':
    result = 0
    for i in range(3, max_int_to_test):
        if is_curious_sum(i):
            print(i)
            result += i

    print("Result: " + str(result))
