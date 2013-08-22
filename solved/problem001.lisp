(defun sum (n)
  "Returns the sum of all the multiples of 3 or 5 below n."
  (cond ((zerop n)
	 0)
	((or (zerop (mod n 3)) (zerop (mod n 5)))
	 (+ n (sum (1- n))))
	(t
	 (sum (1- n)))))

(print (sum 999))
(time (sum 999))
;-> 233168
