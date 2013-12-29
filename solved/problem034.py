#!/usr/bin/env python

facts = [ 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 ]
max_int_to_test = 6*facts[9]

# Time: ~4.5s
def curious_sum(n):
    """Returns the sum of the factorial of n's digits"""
    s = 0
    while n > 0:
        digit = n%10
        s += facts[digit]
        n = n / 10
    return s

# Time: ~15s
def map_curious_sum(n):
    return sum(map(lambda d: facts[int(d)], str(n)))

# Time: ~13s
def list_comprehension_curious_sum(n):
    return sum([facts[int(d)] for d in str(n)])

def reduce_curious_sum(n):
    #l = map(int, str(n))        # Time: ~15s
    l = [int(d) for d in str(n)] # Time: ~16s
    return reduce(lambda x, y: x+facts[y], l, 0)

def is_curious_sum(n):
    return n == curious_sum(n)

if __name__ == '__main__':
    result = 0
    for i in range(3, max_int_to_test):
        if is_curious_sum(i):
            print(i)
            result += i

    print("Result: " + str(result))
