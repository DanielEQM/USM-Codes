from threading import Thread, Semaphore, Lock
from datetime import datetime
import time
sem1 = Semaphore(64)

sigRound = Semaphore(0)
elim = Semaphore(2)
lock = Lock()
jugadores = 256
participantes = 0
flag = 1

paso = Semaphore(128)
fileLock = Lock()

sigRound2 = Semaphore(0)
repro = Semaphore(2)
lock2 = Lock()
jugadoresP = 128
aux = 64
perdedores = 0
flag2 = 1
flagStop = 1

last = 0
last2 = 0
lastFinal = -1

lockfinal = Lock()

def finalDeFinalesholasonlas9delanocheysoloquieroterminarestatarea(i):
    global lockfinal, lastFinal
    time.sleep(10)
    lockfinal.acquire()
    if(lastFinal == -1):
        lastFinal = i
    else:
        with open(f"Final.txt", "a") as fileF:
            tim = datetime.now().strftime("%X.%f")
            fileF.write(f"{lastFinal} vs {i}, {tim}, Ganador {i}")
    lockfinal.release()

'''
Función: finalDeFinalesholasonlas9delanocheysoloquieroterminarestatarea
**********
Parámetros: int i
**********
Descripción: Realiza el enfrentamiento entre el ganador invicto y el ganador de
la fase de repechaje, escribiendo en Final.txt
'''

def repechaje(i, ronda):
    global lock2, perdedores, jugadoresP, aux, fileLock, last2, flag2, flagStop
    if jugadoresP == 1:
        finalDeFinalesholasonlas9delanocheysoloquieroterminarestatarea(i)
        exit()
    repro.acquire()
    time.sleep(10)
    lock2.acquire()
    perdedores += 1
    fileLock.acquire()
    with open(f"Perdedores_Ronda{ronda}.txt", "a") as file2:
        if flag2:
            last2 = i
            flag2 = 0
            fileLock.release()
            lock2.release()
            exit()
        else:
            if(perdedores == jugadoresP):
                perdedores = 0
                if(ronda == 1):
                    sigRound2.release(int(jugadoresP/2))
                    paso.release(int(jugadoresP/2))
                else:
                    if flagStop:
                        jugadoresP = int(jugadoresP/2)
                        sigRound2.release(jugadoresP)
                        aux = int(aux/2)
                        jugadoresP += aux
                        paso.release(aux)
                        if jugadoresP == 8:
                            flagStop = 0
                    else:
                        jugadoresP = int(jugadoresP/2)
                        sigRound2.release(jugadoresP)
                        paso.release(jugadoresP)
            tim = datetime.now().strftime("%X.%f")
            file2.write(f"{last2} vs {i}, {tim}, Ganador {i}\n")
            flag2 = 1
            repro.release(2)
            lock2.release()
    fileLock.release()
    sigRound2.acquire()
    repechaje(i, ronda+1)

'''
Función: repechaje
**********
Parámetros: int i, int ronda
**********
Descripción: Realiza la fase de repechaje, generando los enfrentamientos sumados a
los que perdieron en la fase de ganadores y van a esta fase. Genera los archivos 
'Perdedores_Ronda{num}.txt'
'''

def elimDirect(i, ronda):
    global lock, participantes, jugadores, fileLock, last
    if jugadores == 1:
        finalDeFinalesholasonlas9delanocheysoloquieroterminarestatarea(i)
        exit()
    elim.acquire()
    time.sleep(10)
    lock.acquire()
    participantes += 1
    fileLock.acquire()
    with open(f"Ganadores_Ronda{ronda}.txt", "a") as file1:
        global flag
        if flag:
            last = i
            flag = 0
            fileLock.release()
            lock.release()
            paso.acquire()
            repechaje(i, ronda)
        else:
            if(participantes == jugadores):
                jugadores = int(jugadores / 2)
                participantes = 0
                sigRound.release(jugadores)
            tim = datetime.now().strftime("%X.%f")
            file1.write(f"{last} vs {i}, {tim}, Ganador {i}\n")
            flag = 1
            elim.release(2)
            lock.release()
    fileLock.release()
    sigRound.acquire()
    elimDirect(i, ronda + 1)

'''
Función: elimDirect
**********
Parámetros: int i, int ronda
**********
Descripción: Realiza la fase de eliminación directa, generando los enfrentamientos
respectivos y escribiendolos en los archivos 'Ganadores_Ronda{num}.txt'
'''

def valInit(i, jugadores):
    sem1.acquire()
    file1 = open("Validación.txt", "a")
    time.sleep(15)
    tim = datetime.now().strftime("%X.%f")
    file1.write(f"hebra{i}, {tim}, validación completada\n")
    file1.close()
    sem1.release()
    elimDirect(i, jugadores)

'''
Función: valInit
**********
Parámetros: int i, int jugadores
**********
Descripción: Realiza la fase de validación, realizando 64 validaciones en
intervalos de 15 segundos y escribiendolos en el archivo 'Validación.txt'
'''

# Main #

thread = []
for i in range(0, 256):
    t = Thread(target=valInit, args=(i, 1, ))
    thread.append(t)
    t.start()

for t in thread:
    t.join()
