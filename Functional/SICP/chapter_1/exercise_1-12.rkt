#lang sicp

(define (! n)
  (if (= n 0)
    1
    (* n (! (- n 1)))
  )
)

(define (pascal-element n r)
  (/ (! n) (* (! r) (! (- n r))))
)

;calculates rth element in nth row, row and element numbers are 0-based indices
; Reference: Binomial Coefficients in Pascal's Triangle
; http://www.mathwords.com/b/binomial_coefficients_pascal.htm

(pascal-element 5 4)
(pascal-element 7 2)

