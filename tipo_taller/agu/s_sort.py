


lista = [1,2,5,6,1,2,4]

n = len(lista)
print(n)
lista_b = []

min = 0 # index
while len(lista) > 0:
    
    for i in range(0, len(lista)):
        if lista[min] >= lista[i]:
            min = i
            print(i)

    print("elemen min;", lista[min])
    lista_b.append(lista[min])
    lista.pop(min-1)
    print("lista sin ese elemento", lista)
    print(f"Lista B: {lista_b}")
    
print(lista_b)

