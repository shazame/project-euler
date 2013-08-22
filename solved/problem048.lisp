(defun pow (n p)
  "Returns n^p"
  (cond ((zerop p)
	 1)
	((= 2 p)
	 (* n n))
	((zerop (mod p 2))
	 (pow (pow n (/ p 2)) 2))
	(t
	 (* n (pow n (1- p))))))

(trace pow)
(pow 2 8)
(pow 3 3)
(untrace pow)


(mod 75865746365397 10000000000)

(defun sum (n)
  "Returns the sum 1^1 + 2^2 + ... + n^n"
  (if (zerop n)
      0
      (mod (+ (sum (1- n)) (pow n n))
	   10000000000)))

(time (sum 1000))
