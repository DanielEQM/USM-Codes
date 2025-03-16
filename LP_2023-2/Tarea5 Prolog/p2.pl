%codigo de la cerradura. Se puede editar para otros casos de prueba!
cerradura(1, 4, 5, 1, 0).

%Regla para sacar el valor absoluto segun 2 numeros.
abs(X, Y, Resp) :-
    X < Y, Resp is Y - X, !;
    Y < X, Resp is X - Y, !;
    Y = X, Resp is 0.

%Regla que entrega la respuesta según el E que se obtiene en la "regla verificar".
respuesta(E, R) :-
    E < 1, E > 0, R = "cerca", !;
    E >= 1, R = "lejos", !;
    E = 0, R = "Contraseña descubierta".

%Regla para verficar que tan cerca estas del codigo de la cerradura.
verificar(X1, X2, X3, X4, X5, R) :-
    cerradura(V, W, X, Y, Z),
    abs(V, X1, C1),
    abs(W, X2, C2),
    abs(X, X3, C3),
    abs(Y, X4, C4),
    abs(Z, X5, C5),
    E is (C1 + C2 + C3 + C4 + C5)/5,
    respuesta(E, R).