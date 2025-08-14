# Número de “islas” en una matriz binaria
# Objetivo: Contar componentes de 1s (conectadas por arriba/abajo/izq/der).
# Firma: count_islands(grid: list[list[int]]) -> int
# Requisitos: Marca visitados; DFS o BFS.
# Pista: Itera celdas; cuando veas un 1 no visitado, expándelo.

def count_islands(grid: list[list[int]]) -> int:
    if not grid:
        return 0

    visited = set()
    island_count = 0

    def dfs(r: int, c: int):
        if (r, c) in visited or r < 0 or r >= len(grid) or c < 0 or c >= len(grid[0]) or grid[r][c] == 0:
            return
        visited.add((r, c))
        # Explorar vecinos
        dfs(r + 1, c)
        dfs(r - 1, c)
        dfs(r, c + 1)
        dfs(r, c - 1)

    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 1 and (i, j) not in visited:
                dfs(i, j)
                island_count += 1

    return island_count

# Ejemplo de uso y salida de datos

if __name__ == "__main__":
    grid = [
        [1, 1, 0, 0, 0],
        [1, 1, 0, 1, 1],
        [0, 0, 0, 1, 1],
        [0, 0, 1, 0, 0]
    ]
    num_islands = count_islands(grid)
    print(f"Número total de islas: {num_islands}")
