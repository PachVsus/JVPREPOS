# Hay una pizzeria que ofrece pizzas vegetarianas y no vegetarianas, los ingredientes que pueden llevar las pizzas son:
ingredientes_vegetarianos = ["tomate", "queso", "tofu", "pimientos"]
ingredientes_no_vegetarianos = ["tomate", "queso", "pepperoni", "jamón", "pollo", "bacon"]
# Se necesita hacer un programa que le pregunte al usuario si quiere una pizza vegetariana o no vegetariana. Si elige vegetariana, debe mostrarle tres opciones: pizza con tofu, pizza con pimientos y pizza con tomate.
# Si elige no vegetariana, debe mostrarle tres opciones: pizza con pepperoni, pizza con jamón y pizza con pollo. Luego el programa debe mostrar el precio de la pizza elegida. Cada ingrediente no vegetariano cuesta 25, vegetariano cuesta 20$, cada ingrediente elegido de suma 100$ que cuesta la masa de la pizza.
masa = 100
tomate = 20
queso = 20
tofu = 20
pimientos = 20

pepperoni = 25
jamón = 25
pollo = 25
bacon = 25

ingredientes = {
    "tomate": tomate,
    "queso": queso,
    "tofu": tofu,
    "pimientos": pimientos
}

eleccion = input("¿Desea una pizza vegetariana o no vegetariana? (vegetariana/no vegetariana): ")

if eleccion == "vegetariana":
    print("Opciones de pizza vegetariana:")
    print("1. Pizza con tofu")
    print("2. Pizza con pimientos")
    print("3. Pizza con tomate")

    eleccion_pizza = input("Seleccione una opción (1-3) elige 4 para elegir multiples ingredientes: ")

    if eleccion_pizza == "1":
        precio = masa + tofu
        print("Has elegido la pizza con tofu.")
        print(precio)
    elif eleccion_pizza == "2":
        precio = masa + pimientos
        print("Has elegido la pizza con pimientos.")
        print(precio)
    elif eleccion_pizza == "3":
        precio = masa + tomate
        print("Has elegido la pizza con tomate.")
        print(precio)
    elif eleccion_pizza == "4":
        ingredientes_seleccionados = []
        while True:
            ingrediente = input("Ingrese un ingrediente vegetariano (o 'fin' para terminar): ")
            if ingrediente == "fin":
                break
            elif ingrediente in ingredientes_vegetarianos:
                ingredientes_seleccionados.append(ingrediente)
            else:
                print("Ingrediente no válido.")
        precio = masa + sum(ingredientes[ingrediente] for ingrediente in ingredientes_seleccionados)
        print("Has elegido una pizza con los siguientes ingredientes:", ingredientes_seleccionados)
        print(precio)

elif eleccion == "no vegetariana":
    print("Opciones de pizza no vegetariana:")
    print("1. Pizza con pepperoni")
    print("2. Pizza con jamón")
    print("3. Pizza con pollo")

    eleccion_pizza = input("Seleccione una opción (1-3) elige 4 para elegir multiples ingredientes: ")

    if eleccion_pizza == "1":
        precio = masa + pepperoni
        print("Has elegido la pizza con pepperoni.")
        print(precio)
    elif eleccion_pizza == "2":
        precio = masa + jamón
        print("Has elegido la pizza con jamón.")
        print(precio)
    elif eleccion_pizza == "3":
        precio = masa + pollo
        print("Has elegido la pizza con pollo.")
        print(precio)
    elif eleccion_pizza == "4":
        ingredientes_seleccionados = []
        while True:
            ingrediente = input("Ingrese un ingrediente no vegetariano (o 'fin' para terminar): ")
            if ingrediente == "fin":
                break
            elif ingrediente in ingredientes_no_vegetarianos:
                ingredientes_seleccionados.append(ingrediente)
            else:
                print("Ingrediente no válido.")
        precio = masa + sum(ingredientes[ingrediente] for ingrediente in ingredientes_seleccionados)
        print("Has elegido una pizza con los siguientes ingredientes:", ingredientes_seleccionados)
        print(precio)
