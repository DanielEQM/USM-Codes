%cifrado de cada elemento del ADN, según el binario asignado.
cifrado([0,0], a).
cifrado([0,1], g).
cifrado([1,0], c).
cifrado([1,1], t).

%Regla que permite determinar la base de ADN según el mensaje entregado a traves del cifrado.

descifrar([Binario1, Binario2 | L1], [A | L2]) :-
    cifrado([Binario1,Binario2], A),
    descifrar(L1, L2), !.
descifrar([], []).