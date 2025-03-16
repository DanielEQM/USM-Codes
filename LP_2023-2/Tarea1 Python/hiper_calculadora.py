import re
#Python 3.11.4

def balance(frase):
    '''
    ***
    * frase: String
    ***
    Se le pasa por parametro una linea del problema y si tiene parentesis los cuenta
    y verifica que este balanceado, esta retorna True si esta bien balanceada o False
    si no esta bien balanceada.
    '''
    par = 0
    for char in frase:
        if char == "(":
            par += 1
        elif char == ")":
            par -= 1
            if par < 0:
                break
    if par != 0:
        return False
    else:
        return True

def calCupon(cuponcito):
    '''
    ***
    * cuponcito: String
    ***
    calcula el cupon que se le entregue y retorna 'res' que
    es el resultado del cupon.
    '''
    cuponcito = cuponcito[6:-1]
    res = 0
    if re.fullmatch(Cup, cuponcito) != None:
        res = int(int(cuponcito) * 0.2)
    elif re.fullmatch(Cup2,cuponcito) != None:
        resL = cuponcito.split(",")
        res = int(int(resL[0]) * (int(resL[1]) / 100))
    return res

def identificador(ide):
    '''
    ***
    * ide: string
    ***
    identifica el tipo de elemento que se le entrega y esta
    puede retornar:
    - ans: en caso de que se le haya entregado un 'ANS'
    - res: que es el resultado de cupon en caso de que haya
        llegado un cupon
    - ide: en caso de que el mismo ide haya sido solo un entero
    - "Error": en caso de que no sea ninguna de las anteriores,
        significa que es un error, y por lo tanto retorna "Error"
    '''
    if re.fullmatch(CupoN, str(ide)) != None:
        res = calCupon(ide)
        return res
    elif ide == "ANS":
        return str(ans)
    elif re.fullmatch(entero,str(ide)):
        return str(ide)
    else:
        return "Error"

def opBinaria(Lista):
    '''
    ***
    * Lista: Lista con 3 elementos
    ***
    Se le entrega una lista que puede realizar una operación binaria,
    en caso de que alguno de los valores antes de donde deberia estar
    la operación es un Error, retornará "Error"
    Caso contrario, de que este todo correcto, entonces retornará el
    resultado correspondiente
    '''
    if Lista[1] == "*":
        pri = identificador(Lista[0])
        seg = identificador(Lista[2])
        if pri == "Error" or seg == "Error":
            return "Error"
        else:
            return int(int(pri) * int(seg))
    elif Lista[1] == "//":
        pri = identificador(Lista[0])
        seg = identificador(Lista[2])
        if pri == "Error" or seg == "Error":
            return "Error"
        if seg == "0":
            return "Error"
        else:
            return int(int(pri) // int(seg))
    elif Lista[1] == "+":
        pri = identificador(Lista[0])
        seg = identificador(Lista[2])
        if pri == "Error" or seg == "Error":
            return "Error"
        else:
            return int(int(pri) + int(seg))
    elif Lista[1] == "-":
        pri = identificador(Lista[0])
        seg = identificador(Lista[2])
        if pri == "Error" or seg == "Error":
            return "Error"
        else:
            if int(int(pri) - int(seg)) < 0:
                return 0
            return int(int(pri) - int(seg))
        
def mudas(frase):
    '''
    ***
    * frase: String
    ***
    Separa el string en una lista donde estaran las operaciones y
    los numeros separados, en caso de que haya un error en el momento
    de la resolución, retornara "Error", sino, seguirá calculando hasta 
    que solo quede un elemento dentro de Lista, y retornará dicho elemento
    '''
    L = re.split(operador,frase)
    L2 = list(L)
    cont = 0
    for op in L:
        if op == "*" or op == "//":
            res = opBinaria(L2[cont-1:cont+2])
            if res == "Error":
                return "Error"
            del L2[cont-1:cont+2]
            L2.insert(cont-1,res)
            cont -= 2
        cont += 1
    L3 = list(L2)
    cont = 0
    for op in L2:
        if op == "+" or op == "-":
            res = opBinaria(L3[cont-1:cont+2])
            if res == "Error":
                return "Error"
            del L3[cont-1:cont+2]
            L3.insert(cont-1,res)
            cont -= 2
        cont += 1
    if int(L3[0]) < 0:
        return 0
    else:
        return L3[0]

def calParentesis(frase):
    '''
    ***
    * frase: String
    ***
    Resuelve los parentesis desde el más dentro hasta el
    más externo con recursión. Y retorna el resultado de
    los parentesis más lo que le sigue para que la función
    siga calculando, se detiene cuando completo de calcular
    los parentesis, en caso de que solo haya quedado un numero,
    retornará este, sino, retornará la expresión que quedo.
    en caso de que encuentre algún Error en medio de la resolución,
    retornara "Error"
    '''
    pos = 0
    flag = False
    Resultado = ""
    for char in frase:
        if char == "(":
            if frase[pos-5:pos] != "CUPON":
                Resultado += frase[:pos] 
                llegada = calParentesis(frase[pos+1:])
                if llegada == "Error":
                    return "Error"
                Resultado += llegada
                flag = True
                break
        pos += 1
    if flag == False:
        if re.match(sentencia2, frase) != None:
            fin = re.match(sentencia2, frase)
            newStr = re.split(operador, frase[:fin.end()-1])
            primero = re.split(espacio,newStr[0])
            ultimo = re.split(espacio,newStr[-1])
            newStr[0] = primero[-1]
            newStr[-1] = ultimo[0]
            Operacion = "".join(newStr)
            return str(mudas(Operacion)) + frase[fin.end():]
        if re.fullmatch(sentencia,frase) != None:
            return frase
    else:
        if re.match(sentencia2, Resultado) != None:
            fin = re.match(sentencia2, Resultado)
            newStr = re.split(operador, Resultado[:fin.end()-1])
            primero = re.split(espacio,newStr[0])
            ultimo = re.split(espacio,newStr[-1])
            newStr[0] = primero[-1]
            newStr[-1] = ultimo[0]
            Operacion = "".join(newStr)
            return str(mudas(Operacion)) + Resultado[fin.end():]
        if re.fullmatch(sentencia,Resultado) != None:
            return Resultado
    if re.fullmatch(entero,Resultado) != None:
        return Resultado
    return "Error"

def resolver(frase):
    '''
    ***
    * frase: String
    ***
    Manda al string a verificarse de distintas maneras, primero
    si esta balanceada la ecuación o no, en caso de que lo este,
    revisará los parentesis. Una vez revisado los parentesis, si
    es que no hubo ningún error, retorna el resultado final. En 
    caso de encontrar un error, retorna "Error"
    '''
    if balance(frase) == False:
        return "Error"
    frase = calParentesis(frase)
    if frase == "Error":
        return "Error"
    elif re.fullmatch(sentencia, frase) != None:
        return str(mudas(frase))
    else:
        return frase 

#-------------#
#     MAIN    #
#-------------#

digito = f"[1-9]"
digito_0 = f"{digito}|0"
entero = f"{digito}({digito_0})*|0"
espacio = fr"\s"
clave = fr"ANS|CUPON\({espacio}*({entero}|ANS)({espacio}*\,{espacio}*([0-9]([0-9])?|ANS|100){espacio}*)?\)"
CupoN = fr"CUPON\({espacio}*({entero}|ANS)({espacio}*\,{espacio}*([0-9]([0-9])?|ANS|100){espacio}*)?\)"
Cup = fr"{espacio}*({entero}|ANS)"
Cup2 = fr"{espacio}*({entero}|ANS)({espacio}*\,{espacio}*([0-9]([0-9])?|ANS|100){espacio}*)"
operador = fr"{espacio}*(\+|\*|-|//){espacio}*"
operacion = f"({clave}|{entero}){operador}({clave}|{entero})"
sentencia = f"{operacion}({operador}({entero}|{clave}))*"
sentencia2 = fr"({espacio})*{operacion}({operador}({entero}|{clave}))*({espacio})*\)"

digito = re.compile(digito)
digito_0 = re.compile(digito_0)
entero = re.compile(entero)
espacio = re.compile(espacio)
clave = re.compile(clave)
CupoN = re.compile(CupoN)
Cup = re.compile(Cup)
Cup2 = re.compile(Cup2)
operador = re.compile(operador)
operacion = re.compile(operacion)
sentencia = re.compile(sentencia)
sentencia2 = re.compile(sentencia2)

problema = open("problemas.txt")
List = []
for line in problema:
    List.append(line.strip())
problema.close()
desarrollo = open("desarrollos.txt", "w")
ans = 0
DiccProblemas = {}
problemas = 0

for line in List:
    if line == "":
        problemas += 1
        ans = 0
    else:
        respuesta = resolver(line)
        if respuesta != "Error":
            ans = int(respuesta)
        if problemas not in DiccProblemas:
            DiccProblemas[problemas] = []
        DiccProblemas[problemas].append([line, respuesta])

flag = True
for prob in DiccProblemas:
    for comprobar in DiccProblemas[prob]:
        if comprobar[1] == "Error":
            flag = False
    if flag == False:
        for cambiar in DiccProblemas[prob]:
            if entero.fullmatch(cambiar[1]) != None:
                cambiar[1] = "Sin Resolver"
        flag = True
    for write in DiccProblemas[prob]:
        desarrollo.write(write[0]+" = "+write[1]+"\n")
    desarrollo.write("\n")
desarrollo.close()