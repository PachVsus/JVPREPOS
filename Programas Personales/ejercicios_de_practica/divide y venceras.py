# La técnica [divide y vencerás](https://bit.ly/46afaca) consta de
# los siguientes pasos:
# + Dividir el problema en subproblemas menores.
# + Resolver por separado cada uno de los subproblemas:
# + si los subproblemas son complejos, usar la misma técnica recursivamente;
# + si son simples, resolverlos directamente.
# + Combinar todas las soluciones de los subproblemas en una solución simple.

from typing import Callable, TypeVar

P = TypeVar('P')  # Tipo de los parámetros de la función
R = TypeVar('R')  # Tipo del valor de retorno de la función

def divide_y_venceras(func: Callable[[P], R], problema: P) -> R:
    # Dividir el problema en subproblemas
    subproblemas = dividir_problema(problema)
    # Resolver cada subproblema
    soluciones = [func(sub) for sub in subproblemas]
    # Combinar las soluciones
    return combinar_soluciones(soluciones)


def dividir_problema(problema: P) -> list[P]:
    # Implementar la lógica para dividir el problema en subproblemas
    pass
