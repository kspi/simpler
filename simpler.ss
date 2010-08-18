
;; initialize drawing extension
(load-extension "./libsimpler.so" "SWIG_init")


;; functions

(define (vlt x c)
  (box (* 25 c) x 0 1 (GRID-SIZE))
  (if (> c 0)
    (vlt (+ x 1) (- c 1)) ))

(define (yay fc)
  (if (< fc 0) (yay (GRID-SIZE))
      (begin        
        (vlt fc 10)
        (render)
        (nap 40)
        (yay (- fc 1)))))


;; main code

(init)

(yay -1)

(end)
