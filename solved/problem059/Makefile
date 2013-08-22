all: problem059

problem059: problem059.c
	gcc -Wall -Wextra -o $@ $<

answer: problem059
	@./problem059 | cut -d: -f2 | od -td1 -w1 -v | head -n-3 | cut -d\  -f1 --complement | awk '{ print "a = a + " $$1 "; a" }' | bc -l | tail -1

clean:
	@rm -f problem059 *~
