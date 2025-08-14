# Semaforo animado con tkinter en una ventana
import tkinter as tk
import time

class SemaforoAnimado:
	def __init__(self, root):
		self.root = root
		self.root.title("Semáforo Animado")
		self.canvas = tk.Canvas(root, width=120, height=300, bg="gray20")
		self.canvas.pack(padx=20, pady=20)
		# Coordenadas de los círculos
		self.circles = [
			self.canvas.create_oval(20, 20, 100, 100, fill="gray"),    # Rojo
			self.canvas.create_oval(20, 110, 100, 190, fill="gray"),   # Amarillo
			self.canvas.create_oval(20, 200, 100, 280, fill="gray")    # Verde
		]
		self.estado = 0
		self.colores = ["red", "yellow", "green"]
		self.animar()

	def animar(self):
		# Apaga todos los círculos
		for i in range(3):
			self.canvas.itemconfig(self.circles[i], fill="gray")
		# Enciende el círculo correspondiente
		self.canvas.itemconfig(self.circles[self.estado], fill=self.colores[self.estado])
		# Cambia de estado cada 1 segundo
		self.estado = (self.estado + 1) % 3
		self.root.after(1000, self.animar)

if __name__ == "__main__":
	root = tk.Tk()
	app = SemaforoAnimado(root)
	root.mainloop()
