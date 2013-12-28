#!/usr/bin/env python

facts = [ 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 ]
max_int_to_test = 6*facts[9]

def curious_sum(n):
    """Returns the sum of the factorial of n's digits"""
    s = 0
    while n > 0:
        digit = n%10
        s += facts[digit]
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
