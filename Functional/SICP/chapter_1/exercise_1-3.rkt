#lang sicp


(define (square a)
  (* a a)
  	  )

(define (sum-of-squares a b)
  (+ (square a) (square b) )
  					)

(define (max a b)
  (cond ((>= a b) a)
  	(else b)
  )
  			)

(define (sum-of-biggest-squares a b c    )
  (cond ((>= a b)
	  (sum-of-squares a (max b c) )
	)
	  (else
	  (sum-of-squares b (max a c) ) 
	  )
  ) 
						  
  						    )


(sum-of-biggest-squares 6 5 7)
(sum-of-biggest-squares 0 0 0)
(sum-of-biggest-squares 5 2 3)
(sum-of-biggest-squares 6 3 2)
(sum-of-biggest-squares -1 -2 -3)
(sum-of-biggest-squares 3 -2 5)
(sum-of-biggest-squares 3 7 5)
(sum-of-biggest-squares 7 3 5)
(sum-of-biggest-squares 8 4 2)
(sum-of-biggest-squares 8 2 8)
(sum-of-biggest-squares 8 8 8)
(sum-of-biggest-squares 5 4 8)
(sum-of-biggest-squares 4 5 8)
(sum-of-biggest-squares 2 5 8)
(sum-of-biggest-squares -3 -5 -6)
(sum-of-biggest-squares 5 3 2)
(sum-of-biggest-squares 5 2 3)
(sum-of-biggest-squares 2 3 5)
(sum-of-biggest-squares 8 -3 -27)





 




