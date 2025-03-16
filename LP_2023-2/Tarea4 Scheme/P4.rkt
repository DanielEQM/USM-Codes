#lang scheme

;; a travez de su función interna 'receta' buscar en cual de las recetas
;; se encuentra el elemento pedido. Se usa la función 'ing' para recorrer la
;; lista y encontrar el elemento pedido.
;;
;; ingrediente : es el ingrediente a buscar.
;; lista : la lista con recetas.
;; dentro de receta -> una copia de los elementos entregados
;; dentro de ing -> rec : la receta con la que se buscará el ingrediente

(define buscar_recetas
  (lambda (ingrediente lista)
    (if (null? ingrediente)
        '()    
        (if (null? lista)
            '()
            (let receta ((l lista))
              (if (null? l)
                  '()
                  (if (eqv? (car ingrediente) (let ing ((rec (cdr (car l))))
                                                (if (null? rec)
                                                    '()
                                                    (if (eqv? (car ingrediente) (car rec))
                                                        (car rec)
                                                        (ing (cdr rec))))))
                      (cons (car (car l)) (receta (cdr l)))
                      (receta (cdr l)))))))))
