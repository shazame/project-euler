;/*******************************
; * Site: Project Euler
; * Link: http://projecteuler.net/problems
; * Problem:
; * Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
; * 
; *     1634 = 14 + 64 + 34 + 44
; *     8208 = 84 + 24 + 04 + 84
; *     9474 = 94 + 44 + 74 + 44
; * 
; * As 1 = 14 is not a sum it is not included.
; * 
; * The sum of these numbers is 1634 + 8208 + 9474 = 19316.
; * 
; * Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
; * 
; * Solution by: David
; * Answer: 443839
; *
; * Comment :
; *******************************/

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

(defun sum-power-digit(n p)
  "Return the sum of p-th powers of n's digits"
  (if (< n 1)
      0
      (+ (pow (mod n 10) p) (sum-power-digit (floor n 10) p))))

(sum-power-digit 1634 4) ;-> 1634
(sum-power-digit 1635 4)
(sum-power-digit 9474 4) ;-> 9474

(defun is-special (n p)
  "Returns true if n is equals to the sum of p-th powers of its digits
and false otherwise."
  (= n (sum-power-digit n p)))

(is-special 1634 4)
;-> T
(is-special 1635 4)
; -> nil

(is-special 8975788 5)

(defun sum-special-numbers-below (n p)
  "Returns the sum of the numbers below n that are specials
with the p-th power."
  (cond ((= 1 n)
	 0)
	((is-special n p)
	 (+ n (sum-special-numbers-below (1- n) p)))
	(t
	 (sum-special-numbers-below (1- n) p))))

(sum-special-numbers-below 100000 4)

(defun sum-special-numbers-below (n p)
  "Returns the sum of the numbers below n that are specials
with the p-th power."
  (let ((s 0))
    (loop for x from 2 to n
	 do (when (is-special x p)
	      (setf s (+ s x))))
    s))

(sum-special-numbers-below 10000000 5)
;-> 443839

