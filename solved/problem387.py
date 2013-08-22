MAX_SIZE = 100000

def sum_digits(n):
	s = 0;
	while n > 0:
		s += n%10
		n /= 10
	return s;

def is_harshad(n):
	return (n % sum_digits(n)) == 0;

#def list_harshad_number_below(n):
#	i = 1;
#
#	while i <= n:
#		if (is_harshad(i)):
#			print "%d\n", (i);
#		i+=1

def add_list_RTHN(n, T):
	k = 0;

	while k < 10: 
		if (is_harshad(n*10+k)):
			T.append(n*10+k)
		k+=1	

	return T

def list_RTHN_number_below(n, T):
	i = 0;
	index = 0;

	while i < 9:
		T.append(i+1)
		i+=1
	
	#T = add_list_RTHN(T[index], T)
	#index+=1
	while T[-1] <= n:
		#print T[index]
		T = add_list_RTHN(T[index], T)
		index+=1

	return T

def is_prime(n):
	i = 2;

	if (n == 1):
		return 0

	while i*i <= n:
		if (0 == (n%i)):
			return 0;
		i+=1

	return 1;

def is_strong_H(n):
	return is_prime(n/sum_digits(n));	

def filter_strong_RTHN(T, S):

	for element in T:
		if is_strong_H(element):
			S.append(element)

	return S;

def add_list_SRTHP(n, P):
	k = 0;

	while k < 10:
		if (is_prime(n*10+k)):
			P.append(n*10+k)
		k+=1

	return P

def list_SRTHP(S, P):

	for element in S:
		P = add_list_SRTHP(element, P);

	return P

def sum_below(T, max):
	s = 0;

	for e in T:
		if e <= max:
			s += e

	return s;

#################

go_until = 100000000000000;
print "go until: %d" % (go_until);

T = list_RTHN_number_below(go_until, []);
print "number of RTHN: %d" % (len(T))

S = filter_strong_RTHN(T, []);
print "number of SRTHN: %d" % (len(S))

P = list_SRTHP(S, []);
print "number of SRTHP: %d" % (len(P))

print "sum of SRTHP less than %d: %d\n" % (go_until, sum_below(P, go_until));

for e in P:
	print e

