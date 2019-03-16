#lang sicp


(define (f-iter a b c d count)
  (if (= count 0)
    a
    (f-iter (+ a (* 2 b) (* 3 c)) a b c (- count 1))
  )
)

(define (f n)
  (if (< n 3)
    n
  (f-iter 2 1 0 0 (- n 2) )
  )
)





(f -3)
(f 1)
(f 2)
(f 3)
(f 4)
(f 5)
(f 6)
(f 7)
(f 8)
(f 9)
(f 10)
(f 11)
(f 12)
(f 13)
(f 14)
(f 15)
(f 16)
(f 17)
(f 18)
(f 19)
(f 20)

