import os

calculosFeitos = []

def dataUser(x, y, operador):
    resposta = None
    if operador == "1":
        resposta = x + y
    elif operador == "2":
        resposta = x - y
    elif operador == "3":
        resposta = x / y
    elif operador == "4":
        resposta = x * y
    print(resposta)
    return resposta

contador = 1

nome = input("Digite seu nome: ")


while True:
    os.system('cls')
    print("conta", contador)
    x = float(input(nome + ", digite um valor para o número x: "))
    y = float(input(nome + ", digite um valor para o número y: "))
    operacao = input(nome + ", digite qual operação você quer que seja feita (1) adição, (2) subtração, (3) divisão, (4) multiplicação): ").lower()
    resultado = dataUser(x, y, operacao)
    calculosFeitos.append({
        "x": x,
        "y": y,
        "operacao": operacao,
        "resposta": resultado
    })
    pergunta = input(nome + ", para continuar fazendo as operações, digite 1 parar 'continuar'; caso queira parar, digite 2 para 'finalizar': ")
    contador += 1
    if pergunta.lower() == "2":
        os.system('cls')
        break

conta = 0
print(nome, "aqui estão todas as suas contas feitas:")
print("----------------------------")
for calculo in calculosFeitos:
    conta += 1
    valorX = calculo["x"]
    valorY = calculo["y"]
    operacao = calculo["operacao"]
    nomeOperador = ""
    if operacao == "1":
        nomeOperador = "adição"
    elif operacao == "2":
        nomeOperador = "subtração"
    elif operacao == "3":
        nomeOperador = "divisão"
    elif operacao == "4":
        nomeOperador = "multiplicação"
    
    valorResposta = calculo["resposta"]
    
    print("Conta:", conta)
    print("x:", valorX, "y:", valorY, "operação:", nomeOperador, ", resposta:", valorResposta)
    print("--------------------------------")