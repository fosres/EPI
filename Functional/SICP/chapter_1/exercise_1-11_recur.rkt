#lang racket
(require sicp)
(require racket/trace)

(define (f n)
  (cond
    ((< n 3)
     n
     )
    (else (+ (f (- n 1)) (* 2 (f (- n 2))) (* 3 (f (- n 3))) ))

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

