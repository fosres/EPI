#lang sicp

(define (square guess)
  (* guess guess) 
)

(define (cube guess)
  (* guess guess guess) 
)

(define (improve guess x)
  (/ (+ 
       (/ x (square guess) )
       
       (* 2 guess)
     )
     
     3.
  )
)

(define (abs x)
  (cond ((> x 0) x)
        ((= x 0) 0)
        ((< x 0) (- x))
  )
)

(define (good-enough? guess x)
  (< (abs (- (cube guess) x)) 0.00000000000001)
)

;What if (cube guess) is itself negative?

(define (cube-root guess x)
  
  (if (good-enough? guess x)
       
    	guess
       
	(cube-root (improve guess x) x)
  )

)

(cube-root 2 27)
(cube-root 0.025 0.5)
(cube-root 0.15 4096)
(cube-root 0.0001 216000)
(cube-root 0.0001 132651)
(cube-root 0.0001 46656)
(cube-root 0.0001 1000)
(cube-root 0.0001 729)
(cube-root 0.0001 117649)
(cube-root 0.0001 205379)
(cube-root 0.0001 157464)
(cube-root 0.0001 54872)
(cube-root 0.0001 0.0008)
(cube-root 0.0001 10.0)
(cube-root 0.0001 166.375)
(cube-root 0.0001 0.027)
(cube-root 0.0001 1.331)
(cube-root 0.0001 0.000216)
(cube-root 0.0001 0.005832)
(cube-root 0.0001 0.015625)
(cube-root 0.0001 0.2)


