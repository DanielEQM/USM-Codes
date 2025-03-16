#lang scheme

;; Arma la lista según los ingredientes que faltan, dentro de esta
;; función se encuentra 'armar' que genera la recursión. compara
;; el tamaño de la lista con el ingrediente con la cantidad que tiene
;; estipulada, y acumula en una lista los ingredientes que faltan.
;; Dentro hay una función que llamada 'listita' que cuenta la cantidad
;; de elementos
;; 
;; stock : la lista con el stock.
;; dentro de armar -> una copia de los elementos entregados
;; dentro de listita -> ing : lista con ingredientes a contar

(define armar_lista
  (lambda (stock)
    (let armar ((l stock))
      (cond ((null? l) '())
            (else (define cant (let listita ((ing (car (cdr (car l)))))
                                 (if (null? ing)
                                     0
                                     (+ 1 (listita (cdr ing))))))
                  (cond ((= (car (car l)) cant) (armar (cdr l)))
                        ((< (car (car l)) cant) (armar (cdr l)))
                        (else (cons (list (- (car (car l)) cant) (car (car (cdr (car l))))) (armar (cdr l))))))))))

