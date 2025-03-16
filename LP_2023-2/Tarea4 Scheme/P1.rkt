#lang scheme

;; checkea la cantidad de elementos en la lista, y la funcion
;; chek dentro de esta hace la recursión para contar los elementos
;; y luego compararlo con la cantidad entregada.
;;
;; cantidad : es la cantidad de elementos que supuestamente estan en la lista
;; lista : todos los elementos de la lista
;; dentro de check -> l : es la lista que se recorrerá recursivamente

(define checkear
  (lambda (cantidad lista)
    (= cantidad (let check ((l lista))
                  (if (null? l)
                      0
                      (+ 1 (check (cdr l))))))))
