%codigo de la cerradura. Se puede editar para otros casos de prueba!
cerradura(1, 4, 5, 1, 0).

%Regla que determina si 2 numeros son iguales.
igual(X, Y, Resp) :-
    X = Y, Resp is 1, !;
    X \== Y, Resp is 0.

%Regla que entrega la respuesta según la cantidad que se obtiene en la "regla verificar".
respuesta(Cantidad, Resp) :-
    Cantidad = 5, Resp = "contraseña descubierta", !;
    Cantidad < 5, Resp is Cantidad.

%Regla que verifica cuantos digitos del codigo acertaron en su respectivo orden.
verificar(X1, X2, X3, X4, X5, R) :-
    cerradura(V, W, X, Y, Z),
    igual(V, X1, N1),
    igual(W, X2, N2),
    igual(X, X3, N3),
    igual(Y, X4, N4),
    igual(Z, X5, N5),
    N is N1 + N2 + N3 + N4 + N5,
    respuesta(N, R).