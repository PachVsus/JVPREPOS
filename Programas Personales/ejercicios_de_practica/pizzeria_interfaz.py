import tkinter as tk
from tkinter import messagebox

# Ingredientes y precios
ingredientes_vegetarianos = {
    "tomate": 20,
    "queso": 20,
    "tofu": 20,
    "pimientos": 20
}
ingredientes_no_vegetarianos = {
    "tomate": 20,
    "queso": 20,
    "pepperoni": 25,
    "jamón": 25,
    "pollo": 25,
    "bacon": 25
}
masa = 100

def calcular_precio(ingredientes_seleccionados, tipo):
    if tipo == "vegetariana":
        precios = ingredientes_vegetarianos
    else:
        precios = ingredientes_no_vegetarianos
    return masa + sum(precios[i] for i in ingredientes_seleccionados)

def mostrar_opciones(tipo):
    for widget in frame_opciones.winfo_children():
        widget.destroy()
    if tipo == "vegetariana":
        lista = list(ingredientes_vegetarianos.keys())
    else:
        lista = list(ingredientes_no_vegetarianos.keys())

    tk.Label(frame_opciones, text="Elige ingredientes:").pack()
    vars = []
    for ing in lista:
        var = tk.IntVar()
        chk = tk.Checkbutton(frame_opciones, text=ing, variable=var)
        chk.pack(anchor="w")
        vars.append((ing, var))

    def calcular():
        seleccionados = [ing for ing, var in vars if var.get()]
        if not seleccionados:
            messagebox.showinfo("Error", "Selecciona al menos un ingrediente.")
            return
        precio = calcular_precio(seleccionados, tipo)
        messagebox.showinfo("Resultado", f"Has elegido pizza con: {', '.join(seleccionados)}\nPrecio: {precio}$")

    tk.Button(frame_opciones, text="Calcular precio", command=calcular).pack(pady=5)

def elegir_tipo(tipo):
    mostrar_opciones(tipo)

root = tk.Tk()
root.title("Pizzería")

frame_tipo = tk.Frame(root)
frame_tipo.pack(pady=10)

tk.Label(frame_tipo, text="¿Desea una pizza vegetariana o no vegetariana?").pack()
tk.Button(frame_tipo, text="Vegetariana", command=lambda: elegir_tipo("vegetariana")).pack(side="left", padx=5)
tk.Button(frame_tipo, text="No vegetariana", command=lambda: elegir_tipo("no vegetariana")).pack(side="left", padx=5)

frame_opciones = tk.Frame(root)
frame_opciones.pack(pady=10)

root.mainloop()
