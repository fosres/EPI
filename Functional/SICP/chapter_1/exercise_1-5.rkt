#lang sicp

(define (p) (p))

(define (test x y) 
  (if (= x 0) 
      (0) 
      (y)
  )
)

(test 0 (p))

;;;The program is an applicative-order program
;;;since it evaluates arguments before 
;;;evaluating procedure.
