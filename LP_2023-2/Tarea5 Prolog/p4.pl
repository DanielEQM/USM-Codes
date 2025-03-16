%sigue: pX sigue a pY.
sigue(p1, p2).
sigue(p1, p9).
sigue(p1, p15).
sigue(p2, p3).
sigue(p3, p4).
sigue(p4, p5).
sigue(p5, p6).
sigue(p6, p7).
sigue(p7, p8).
sigue(p7, p17).
sigue(p8, p1).
sigue(p9, p10).
sigue(p10, p11).
sigue(p11, p12).
sigue(p12, p13).
sigue(p13, p14).
sigue(p15, p16).
sigue(p16, p20).
sigue(p20, p21).
sigue(p21, p22).
sigue(p17, p18).
sigue(p18, p19).

%Regla que entrega la respuesta según la Lista que se consigue.
respuesta(L, R) :-
    length(L, Largo), Largo =< 7, R = "Es de la rama principal", !;
    length(L, Largo), Largo > 7, R = "No es de la rama princial".

%Regla que permite encontrar la ruta de P.
%     -> La segunda parte de esta regla, muestra la Lista obtenida y busca la respuesta.
ruta(L, P, Inicial, R) :-
    sigue(Anterior, P),
    Inicial \== Anterior,
    not(member(Anterior, L)),
    append(L, [Anterior], L1),
    ruta(L1, Anterior, Inicial, R), !.
ruta(L, P, _, R) :-
    member(P, L),
    print(L),
    respuesta(L, R).

%Regla que permite encontrar si es de la ruta principal o no.
principal(P, R) :-
    ruta([], P, P, R).