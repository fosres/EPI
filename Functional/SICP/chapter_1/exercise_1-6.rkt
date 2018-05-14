#lang sicp


(define (average x y) 
  (/ (+ x y) 2))

(define (improve guess x)
  (average guess (/ x guess)))

(define (square x)
  (* x x) 
  		)

(define (good-enough? guess x)
  (< (abs (- (square guess) x)) 0.001))

(define (new-if predicate 
                then-clause 
                else-clause)
  (cond (predicate then-clause)
        (else else-clause)))


(define (sqrt-iter guess x)
  (new-if (good-enough? guess x)
      guess
      (sqrt-iter (improve guess x) x)
  )
)

(sqrt-iter 1 9)

;It enters an infinite loop.
;Explanation
;I suspect there is a problem
;with infinite looping due to
;applicative order evaluation.
;PROBLEM: 

;Since MIT-Scheme
;does applicative order evaluation,
;the (new-if function enters an
;infinite loop for
;(sqrt-iter (improve guess x) x)


