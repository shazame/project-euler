/*******************************
 * Site: Project Euler
 * Link: http://projecteuler.net/problems
 * Problem:
 * The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
 * 
 * There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
 * 
 * How many circular primes are there below one million?
 * 
 * Solution by: David
 * Answer:
 *
 * Comment:
 *******************************/

#include <cmath>
#include <iostream>
#include "eulib/PrimeList.hpp"

using namespace std;
using eulib::PrimeList;

#define UPPER_PRIME 1000000

PrimeList<unsigned int> primeList(UPPER_PRIME);

unsigned int nextRotation(unsigned int n)
{
    unsigned int nbDigit = log10(n);
    unsigned int lastDigit = n%10;
    unsigned int newRotation = n/10 + lastDigit * (int)pow(10, nbDigit);

    return newRotation;
}

bool isCircularPrime(unsigned int n)
{
    unsigned int n_rotation = n;
    while ((n_rotation = nextRotation(n_rotation)) != n) {
        if (!primeList.isPrime(n_rotation)) {
            return false;
        }
    }
    return true;
}

int main(void)
{
    unsigned int curPrime;
    int result = 0;

    while ((curPrime = primeList.nextPrime()) < UPPER_PRIME) {
        if (isCircularPrime(curPrime)) {
            //cout << curPrime << endl;
            result++;
        }
    }
    cout << "Result: " << result << endl;
    
    return 0;
}
