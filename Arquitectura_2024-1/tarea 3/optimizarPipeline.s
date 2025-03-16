.data
lista:  .word 3,1,2,6,2,20,1,3,34,1
t:      .word 10

.text
_start:
    @ Inicializar registros
    LDR R0, =lista    @ Dirección de la lista
    LDR R1, =t        @ Dirección de t
    LDR R1, [R1]      @ Valor de t
    MOV R2,#0
    MOV R4, #0        @ Inicializar a = 0
    CMP R1,#3
    BLE max_less3

loop_a:
    CMP R4, R1        @ Comparar a con t
    BGE set_values   @ Si a >= t, salir del bucle

    ADD R5, R4, #3    @ R5 = a + 3
    CMP R5, R1        @ Comparar (a + 3) con t
    BGT set_values  @ Si (a + 3) > t, romper el bucle

    MOV R6, #0        @ Inicializar cont = 0
    MOV R7, #0        @ Inicializar suma = 0

loop_cont:
    ADD R3, R4, R6    @ R3 = a + cont
    CMP R3, R1        @ Comparar (a + cont) con t
    BGE check_sumaT   @ Si (a + cont) >= t, verificar sumaT

    LSL R3,R3,#2
    ADD R3, R0, R3  @ Dirección de lista[a + cont]
    LDR R3, [R3]           @ Cargar lista[a + cont]
    ADD R7, R7, R3        @ suma += lista[a + cont]

    ADD R6, R6, #3    @ cont += 3
    B loop_cont       @ Volver al inicio del bucle

check_sumaT:
    CMP R7, R2     @ Comparar suma con sumaT
    BLE skip_update   @ Si suma <= sumaT, saltar la actualización

    MOV R2,R7      @ Actualizar sumaT

skip_update:
    ADD R4, R4, #1    @ a += 1
    B loop_a          @ Volver al inicio del bucle

set_values:
    MOV R6,#0	     @ Reiniciar el cont y la suma para revisar cual es el elemento maximo segun la lista
    MOV R7,#0

max_less3:
    MOV R6,R7       @realiza el maximo de los elementos de la lista
    LSL R6,R6,#2
    LDR R4,[R0,R6]
    CMP R4,R2
    BLT sig

    MOV R2,R4

sig:
    ADD R7,R7,#1
    CMP R7,R1
    BLT max_less3

end_program:
    MOV R0,#0
    MOV R1,#0
    bl printInt
wfi
