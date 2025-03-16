#lang scheme

;; Recorre la lista y busca si se encuentra el elemento que se busca.
;; la función comp interna, lo busca recursivamente. Devuelve el elemento
;; buscado si es que esta en la lista.
;;
;; obj : objeto a buscar.
;; lista : lista donde se quiere buscar el objeto.
;; dentro de comp -> l : lista a recorrer recursivamente.

(define in_list
  (lambda (obj lista)
    (let comp ((l lista))
      (if (null? l)
          '()
          (if (eqv? (car obj) (car l))
              (car obj)
              (comp (cdr l)))))))

;; Busca el utensilio en el arbol a travez de la función buscar,
;; la cual recursivamente ve los hijos izquierdos y los derechos
;; para buscar el camino más corto.
;;
;; utensilio : objeto a buscar.
;; arbol : lista de listas en forma de arbol binario, de donde
;; se quiere buscar el objeto.
;; dentro de buscar -> tree : arbol por el cual se recorrera por recusión.

(define buscar_utensilio
  (lambda (utensilio arbol)
    (cond ((null? utensilio) "no está")
          ((null? arbol) "no está")
          (else (define resp (let buscar ((tree arbol))
                               (cond ((null? tree) '())
                                     ((eqv? (car utensilio) (car tree)) (list (car tree)))
                                     (else (define izq (buscar (car (cdr tree))))
                                           (define der (buscar (car (cdr (cdr tree)))))
                                           (cond ((null? izq) (if (eqv? (car utensilio) (in_list utensilio der))
                                                                  (cons (car tree) der)
                                                                  '()))
                                                 ((null? der) (if (eqv? (car utensilio) (in_list utensilio izq))
                                                                  (cons (car tree) izq)
                                                                  '()))
                                                 ((> (length izq) (length der)) (cons (car tree) der))
                                                 (else (cons (car tree) izq)))))))
                (if(null? resp)
                   "no está"
                   (reverse (cdr (reverse resp))))))))

