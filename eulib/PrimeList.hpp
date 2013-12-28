#ifndef PRIME_LIST_H
#define PRIME_LIST_H

#include <vector>

//typedef void (*primeSieve)(unsigned int);

namespace eulib{

	template <class PrimeType = unsigned int>
	class PrimeList {
	private:
		/* isPrimeList[0] == 0, isPrimeList[1] == 0, isPrimeList[2] == 1,
		 * isPrimeList[3] == 1, isPrimeList[4] == 0, isPrimeList[5] == 1, ...
		 */
		std::vector<bool>       isPrimeList;
		/* primeList[0] == 2, primeList[1] == 3, primeList[2] == 5, ...
		 */
		std::vector<PrimeType>  primeList;
		unsigned int            curPrimePos;

		void basicSieve(unsigned int);
		void erathosSieve(unsigned int);

	public:
		PrimeList();
		PrimeList(unsigned int);

		~PrimeList();

		bool      isPrime(PrimeType);

		PrimeType nthPrime(unsigned int);
		PrimeType firstPrime(void);
		PrimeType lastPrime(void);
		PrimeType nextPrime(void);

		PrimeType operator[](unsigned int);
	};
}

#include "PrimeList.ipp"

#endif /*PRIME_LIST_H*/

// vim: set tabstop=2 shiftwidth=2 softtabstop=2:
