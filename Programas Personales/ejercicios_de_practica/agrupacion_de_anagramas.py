# Objetivo: Dado un listado de palabras, agrupar las que son anagramas.
# Firma sugerida: group_anagrams(words: list[str]) -> list[list[str]]
# Requisitos: Ordena cada grupo alfabéticamente; ignora mayúsculas/minúsculas.
# Pista: La clave puede ser tuple(sorted(palabra.lower())).

def group_anagramas(words: list[str]) -> list[list[str]]:
    anagramas = {}
    for palabra in words:
        clave = tuple(sorted(palabra.lower()))
        anagramas.setdefault(clave, []).append(palabra) # append hace que se agregue la palabra al grupo correspondiente
    return [sorted(grupo) for grupo in anagramas.values()]

import tkinter as tk

def mostrar_anagramas(words: list[str]):
    grupos = group_anagramas(words)
    ventana = tk.Tk()
    ventana.title("Anagramas")
    for grupo in grupos:
        etiqueta = tk.Label(ventana, text=", ".join(grupo))
        etiqueta.pack()
    ventana.mainloop()

# Ejemplo de uso
if __name__ == "__main__":
    palabras = ["Roma", "amor", "mora", "ramo", "perro", "porre", "repor", "gato", "toga"]
    mostrar_anagramas(palabras)
