/*******************************
 * Site: Project Euler
 * Link: http://projecteuler.net/problems
 * Problem:
 * The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.
 * 
 * We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
 * 
 * There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.
 * 
 * If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
 * 
 * Solution by: David
 * Answer: 100
 *
 * Comment:
 *******************************/

#include <iostream>

#define UNIT_DIG(x) (x%10)
#define TEN_DIG(x)  (x/10)

struct Fraction{
	int num;
	int den;
};

/* Returns the false simplification of a fraction.
 * When no false simplificaton is found, the den of
 * the returns Fraction is 0.
 */
struct Fraction *
falseSimplification(struct Fraction frac) {
	struct Fraction * f = new struct Fraction;

	// Find common digit and simplify them
	if ( UNIT_DIG(frac.num) == UNIT_DIG(frac.den) ) {
		f->num = TEN_DIG(frac.num);
		f->den = TEN_DIG(frac.den);
	}
	else if ( UNIT_DIG(frac.num) == TEN_DIG(frac.den) ) {
		f->num = TEN_DIG(frac.num);
		f->den = UNIT_DIG(frac.den);
	}
	else if ( TEN_DIG(frac.num) == UNIT_DIG(frac.den) ) {
		f->num = UNIT_DIG(frac.num);
		f->den = TEN_DIG(frac.den);
	}
	else if ( TEN_DIG(frac.num) == TEN_DIG(frac.den) ) {
		f->num = UNIT_DIG(frac.num);
		f->den = UNIT_DIG(frac.den);
	}
	else {
		f->den = 0;
	}

	return f;
}

int isSimplification(struct Fraction *frac, struct Fraction *simplifiedFrac) {
	return (frac->num * simplifiedFrac->den) == (simplifiedFrac->num * frac->den);
}

int isNonTrivial(struct Fraction *frac) {
	if ( UNIT_DIG(frac->num) == 0 && UNIT_DIG(frac->den) == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

int
main(void) {
	struct Fraction frac, *simplifiedFrac;

	for (int i=10; i < 100; i++) {
		for (int j=i+1; j < 100; j++) {

			frac.num = i; frac.den = j;
			simplifiedFrac = falseSimplification(frac);

			if (simplifiedFrac->den != 0 && isSimplification(&frac, simplifiedFrac) && isNonTrivial(&frac)) {
				std::cout << frac.num << "/" << frac.den           << " : " <<
				   simplifiedFrac->num << "/" << simplifiedFrac->den << std::endl;
			}

			delete simplifiedFrac;
		}
	}

	return 0;
}
