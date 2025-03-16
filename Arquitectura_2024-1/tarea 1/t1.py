
import random
from prettytable import PrettyTable

cant_naves_menos = 0

def crear_mapa(size,cantidad_naves):
    listaposnaves = []
    lista = []
    for i in range(0,size*2):
        row = []
        for j in range(0,size):
            row.append('?')
        lista.append(row)

    for i in range(0,cantidad_naves):
        cordx = random.randint(0,2*size-1)
        cordy = random.randint(0,size-1)
        tipo = random.randint(0,2)
        tipos = 'XYZ'
        if lista[cordx][cordy] != '?':
            global cant_naves_menos
            cant_naves_menos += 1
            print("\nCoordenadas de nave", i, "colisionaron con otra nave, no se añade al mapa")
            continue
        else:
            lista[cordx][cordy] = tipos[tipo]
            listaposnaves.append((cordx,cordy))


    return(lista,listaposnaves)

'''  ************
     * Parametros: size (entero), cantidad_naves (entero)
     * **********
     * Retorno: (tupla)
     * **********
     * Descripción: Crea el mapa
     ************
     *
'''

def visualizar_mapa(lista):
    
    tabla = PrettyTable()
    
    tabla.field_names = [''] + list(range(len(lista[0])))
    
    for numberfila, row in enumerate(lista):
        row_data = [numberfila] + row
        tabla.add_row(row_data)
    
    print(tabla)

'''  ************
     * Parametros: lista (list)
     * **********
     * Retorno: null
     * **********
     * Descripción: imprime el mapa
     ************
     *
'''

def decimal_a_basenum(num,tipo): #num es entero, tipo es entero
    base = 16
    if(tipo == 1):
        base = 2
    elif(tipo == 2):
        base = 8
    lista = []
    while(num != 0):
        if(num % base == 10):
            lista.append("A")
        elif(num % base == 11):
            lista.append("B")
        elif(num % base == 12):
            lista.append("C")
        elif(num % base == 13):
            lista.append("D")
        elif(num % base == 14):
            lista.append("E")
        elif(num % base == 15):
            lista.append("F")
        else:
            lista.append(str(num % base))
        num = num // base
    lista.reverse()
    return ''.join(lista)

'''  ************
     * Parametros: num (entero), tipo (entero)
     * **********
     * Retorno: string
     * **********
     * Descripción: Realiza la conversión de decimal a binario, octal o hexadecimal
     dependiendo del tipo ingresado. Divide el número decimal por la base ingresada
     y el modulo es guardado en la lista, la cual es invertida y juntada en un string 
     para el retorno.
     ************
     *
'''

def basenum_a_decimal(num,tipo): #num es string, tipo es entero
    lista = ["0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"]
    i = -1
    decimal = 0
    potencia = 0
    if(tipo == 1):
        for iteracion in range(0,len(num)):
            if(num[i] not in lista[0:2]):
                return -1
            else:
                decimal += int(num[i]) * (2 ** potencia)
                potencia += 1
                i -= 1
    if(tipo == 2):
        for iteracion in range(0,len(num)):
            if(num[i] not in lista[0:8]):
                return -1
            else:
                decimal += int(num[i]) * (8 ** potencia)
                potencia += 1
                i -= 1
    if(tipo == 3):
        for iteracion in range(0,len(num)):
            if(num[i] not in lista[0:-1]):
                return -1
            else:
                if(num[i] == "A"):
                    decimal += 10 * (16 ** potencia)
                elif(num[i] == "B"):
                    decimal += 11 * (16 ** potencia)
                elif(num[i] == "C"):
                    decimal += 12 * (16 ** potencia)
                elif(num[i] == "D"):
                    decimal += 13 * (16 ** potencia)
                elif(num[i] == "E"):
                    decimal += 14 * (16 ** potencia)
                elif(num[i] == "F"):
                    decimal += 15 * (16 ** potencia)
                else:
                    decimal += int(num[i]) * (16 ** potencia)
                potencia += 1
                i -= 1        
    return decimal

'''  ************
     * Parametros: num (string), tipo (entero)
     * **********
     * Retorno: cont (entero)
     * **********
     * Descripción: Realiza la conversión de binario, octal o hexadecimal a decimal
     dependiendo del tipo ingresado. Genera el polinomio característico del número y
     realiza una sumatoria de él que se guarda en la variable cont, que es retornada al final.
     ************
     *
'''

# main #
tamaño = int(input("¡Bienvenido a Bittleship! Ingresa el tamaño del tablero a jugar: "))
if(tamaño > 40):
    while(tamaño > 40):
        tamaño = int(input("El valor que has ingresado es muy alto. No superes 40: "))
cant_naves = int(input("Ahora ingresa la cantidad de naves enemigas en el tablero: "))
if(cant_naves > (tamaño * tamaño * 2)):
    while(cant_naves > (tamaño * tamaño * 2)):
          cant_naves = int(input("La cantidad de naves no puede superar la cantidad de casillas disponibles: "))
juego,enemigos = crear_mapa(tamaño,cant_naves)
cant_naves -= cant_naves_menos
while(cant_naves != 0):
    print("\nCantidad de naves enemigas: " + str(cant_naves))
    visualizar_mapa(juego)
    tipo = int(input("Ingrese el tipo de base numérica deseada, siendo la opcion 1 binario, 2 octal, 3 hexadecimal: "))
    if(tipo <= 0 or tipo >= 3):
        while(tipo <= 0 or tipo > 3):
            tipo = int(input("El tipo ingresado no pertenece a ninguno de los mencionados anteriormente. Repita el tipo: "))
    x = input("Ingrese la coordenada x en la base pedida: ") #x es un string
    y = input("Ingrese la coordenada y en la base pedida: ") #y es un string
    dec_x = basenum_a_decimal(x,tipo)
    if(dec_x == -1):
        print("\ncoordenada X no valida")
    dec_y = basenum_a_decimal(y,tipo)
    if(dec_y == -1):
        print("\ncoordenada Y no valida")
    if((dec_x,dec_y) not in enemigos):
        print("\nNo derribaste ninguna nave")
    for i in range(0, len(enemigos)):
        if(dec_x == -1 or dec_y == -1):
            break
        if(enemigos[i] == (dec_x,dec_y) and juego[dec_x][dec_y] == "X" and tipo == 1):
            juego[dec_x][dec_y] = "0"
            cant_naves -= 1
            print("\n¡Derribaste una nave enemiga!")
        elif(enemigos[i] == (dec_x,dec_y) and juego[dec_x][dec_y] == "Y" and tipo == 2):
            juego[dec_x][dec_y] = "0"
            cant_naves -= 1
            print("\n¡Derribaste una nave enemiga!")
        elif(enemigos[i] == (dec_x,dec_y) and juego[dec_x][dec_y] == "Z" and tipo == 3):
            juego[dec_x][dec_y] = "0"
            cant_naves -= 1
            print("\n¡Derribaste una nave enemiga!")
print("--------------------------------------------------------------")
print("¡Felicidades! Destruiste todas las naves enemigas, ¡Ganaste!\n")