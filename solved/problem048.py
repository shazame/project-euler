import time

som = 0

t = time.time()
for n in range(1,1000):
	som += pow(n,n)
t = time.time() - t

print som
print
print "Temps de calcul :"
print t
