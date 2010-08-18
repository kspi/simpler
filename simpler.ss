
;; initialize drawing extension
(load-extension "./libsimpler.so" "SWIG_init")


;; functions

(define (int x)
  (inexact->exact (round x)))

(define (nsin x)
  (* 1/2 (+ 1 (sin x))))
(define (ncos x)
  (* 1/2 (+ 1 (cos x))))

(define pi 3.14)

(define (drawpoint phase x y)
  (let* ((th (* 10 pi (sin (* 0.01 phase))))
        (xr (- (* x (sin th)) (* y (cos th))))
        (yr (+ (* x (cos th)) (* y (sin th))))
        (scale (* 1 (sin (* 0.001 phase)))))
   (point (int (* 127
                  (+ (nsin (* xr scale))
                     (ncos (* yr scale)))))
          x y))
  
  (if (< x (1- (GRID-SIZE)))
      (drawpoint phase (1+ x) y)
      (if (< y (1- (GRID-SIZE)))
          (drawpoint phase 0 (1+ y)))))

(define (graphic phase)
  (drawpoint phase 0 0)
  (render)
  (nap 1)
  (graphic (1+ phase)))


;; main code

(init)
(graphic 0)
