#lang scheme

;; cantidades_simple ocupa una función interna llamada 'simple' que ejecuta la
;; recursión de la lista y evalua con el numero entregado, acumulando las
;; respuestas.
;;
;; base : el numero con el que se evaluará.
;; lista : todas las operaciones lambda a ejecutar.
;; dentro de simple -> una copia de los elementos entregados.

(define cantidades_simple
  (lambda (base lista)
    (let simple ((x base)(l lista))
      (if (null? l)
          '()
          (cons ((car l) x) (simple x (cdr l)))))))

;; cantidades_cola ocupa una función interna llamada 'cola' que ejecuta la
;; recursión de la lista y evalua con el numero entregado, acumulando las
;; respuestas.
;;
;; base : el numero con el que se evaluará.
;; lista : todas las operaciones lambda a ejecutar.
;; dentro de cola -> una copia de los elementos entregados.
;;                -> res : acumula las respuestas de la recursión.

(define cantidades_cola
  (lambda (base lista)
    (let cola ((x base) (l lista) (res '()))
      (if (null? l)
          res
          (cola x (cdr l) (append res (list ((car l) x))))))))

