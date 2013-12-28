#define LOWER_PRIME_LIMIT 2
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

//#define curPrimeSieve basicSieve
#define curPrimeSieve erathosSieve

namespace eulib{

	template <class PrimeType>
	void
	PrimeList<PrimeType>::basicSieve(unsigned int n) {
		// The position from which the primality test will be done
		unsigned int nextTestedNb = isPrimeList.size();

		if (n > nextTestedNb) {
			isPrimeList.resize(n+1, 1);
		}

		// At initialization every number primality must be tested
		if (curPrimePos == 0) {
			isPrimeList[0] = 0; isPrimeList[1] = 0; 
			nextTestedNb = 2;
		}

		// Basic primality test
		for (unsigned int curTestedNb = nextTestedNb; curTestedNb <= n; curTestedNb++) {

			for (unsigned int divIndex = 0; divIndex < primeList.size(); divIndex++) {
				PrimeType div = primeList[divIndex];

				if (div*div > curTestedNb) {
					break;
				}
				if (curTestedNb%div == 0) {
					isPrimeList[curTestedNb] = 0;
					break;
				}
			}

			if (isPrimeList[curTestedNb] == 1) {
				primeList.push_back(curTestedNb);
			}
		}
	}

	template <class PrimeType>
	void
	PrimeList<PrimeType>::erathosSieve(unsigned int n) {
		// The position from which the primality test will be done
		unsigned int nextTestedNb = isPrimeList.size();

		if (n > nextTestedNb) {
			isPrimeList.resize(n+1, 1);
		}

		// At initialization every number primality must be tested
		if (curPrimePos == 0) {
			isPrimeList[0] = 0; isPrimeList[1] = 0; 
			nextTestedNb = 2;
		}

		unsigned int i, k = 0;

		// Sieve of Erathostenes
		for (i = 2; i*i <= n; i++) {
			if (isPrimeList[i]) {
				for (k = i*i; k <= n; k += i) {
					isPrimeList[k] = 0;
				}
			}
		}

		// Update primeList
		for (i = nextTestedNb; i <= n; i++) {
			if (isPrimeList[i]) {
				primeList.push_back(i);
			}
		}
	}

	template <class PrimeType>
  PrimeList<PrimeType>::PrimeList(): 
		isPrimeList(LOWER_PRIME_LIMIT+1, 1), 
		curPrimePos(0) {

		curPrimeSieve(LOWER_PRIME_LIMIT);
	}

	template <class PrimeType>
	PrimeList<PrimeType>::PrimeList(unsigned int n): 
		isPrimeList(MAX(LOWER_PRIME_LIMIT, n)+1, 1),
		curPrimePos(0) {

		curPrimeSieve(MAX(n, LOWER_PRIME_LIMIT));
	}

	template <class PrimeType>
	PrimeList<PrimeType>::~PrimeList() {}

	template <class PrimeType>
	bool
	PrimeList<PrimeType>::isPrime(PrimeType n) {
		if (n > isPrimeList.size()) {
			curPrimeSieve(n);
		}

		return (isPrimeList[n] == 0) ? false : true;
	}

	template <class PrimeType>
	PrimeType 
	PrimeList<PrimeType>::nthPrime(unsigned int i) {
		if (i < 1) {
			return -1;
		}

		while (i > primeList.size()) {
			curPrimeSieve(2 * isPrimeList.size());
		}

		curPrimePos = i;
		return primeList[i - 1];
	}

	template <class PrimeType>
	PrimeType 
	PrimeList<PrimeType>::firstPrime(void) {
		curPrimePos = 1;
		return primeList.front();
	}

	template <class PrimeType>
	PrimeType 
	PrimeList<PrimeType>::lastPrime(void) {
		curPrimePos = primeList.size();
		return primeList.back();
	}

	template <class PrimeType>
	PrimeType 
	PrimeList<PrimeType>::nextPrime(void) {
		return nthPrime(curPrimePos + 1);
	}

	template <class PrimeType>
	PrimeType
	PrimeList<PrimeType>::operator[](unsigned int i) {
		return nthPrime(i);
	}
}

// vim: set tabstop=2 shiftwidth=2 softtabstop=2:
