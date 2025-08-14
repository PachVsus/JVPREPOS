# Substring más larga sin repetidos (two pointers)
# Objetivo: Longitud de la subcadena más larga sin caracteres repetidos.
# Firma: longest_unique_substring(s: str) -> int
# Requisitos: O(n) usando ventana deslizante.
# Pista: Usa diccionario {carácter: última_pos} y dos índices.

def longest_unique_substring(s: str) -> int: # Ventana deslizante
    char_dict = {} # Diccionario para almacenar la última posición de cada carácter
    left = 0 # Índice izquierdo de la ventana
    max_length = 0 # Longitud máxima de la subcadena sin repetir
    for right in range(len(s)): # Índice derecho de la ventana
        if s[right] in char_dict: # Si el carácter ya está en el diccionario
            left = max(left, char_dict[s[right]] + 1) # Mover el índice izquierdo
        char_dict[s[right]] = right # Actualizar la última posición del carácter
        max_length = max(max_length, right - left + 1) # Calcular la longitud de la ventana
    return max_length # Longitud de la subcadena más larga sin repetir

# Ejemplo de uso
if __name__ == "__main__": # Ventana deslizante
    cadena = "abcabcbb"
    print(longest_unique_substring(cadena)) # imprimira 3 porque la subcadena "abc" es la más larga sin repetir

    cadena2 = "bbbbb"
    print(longest_unique_substring(cadena2)) # imprimira 1 porque la subcadena "b" es la más larga sin repetir

    cadena3 = "pwwkew"
    print(longest_unique_substring(cadena3)) # imprimira 3 porque la subcadena "wke" es la más larga sin repetir