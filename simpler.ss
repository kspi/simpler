
;; initialize drawing extension
(load-extension "./libsimpler.so" "SWIG_init")


;; functions

(define (vlt x c)
  (box (* 25 c) x 0 1 (GRID-SIZE))
  (if (> c 0)
    (vlt (+ x 1) (- c 1)) ))

(define (graphic fc)
  (vlt fc 20)
  (render)
  (nap 4)
  (graphic (1- fc)))


;; main code

(init)
(graphic 0)
