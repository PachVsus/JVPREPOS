import tkinter as tk

class SemaforoPeatonalJapones:
	def __init__(self, root):
		self.root = root
		self.root.title("Semáforo Peatonal Japonés")
		self.canvas = tk.Canvas(root, width=200, height=300, bg="gray20")
		self.canvas.pack(padx=20, pady=20)
		# Estados: 0 = Rojo, 1 = Verde
		self.estado = 0
		self.dibujar_semaforo()
		self.root.after(1200, self.cambiar_estado)

	def dibujar_semaforo(self):
		self.canvas.delete("all")
		# Marco del semáforo
		self.canvas.create_rectangle(40, 30, 160, 270, fill="black", outline="white", width=3)
		if self.estado == 0:
			# Persona estática (rojo) (formato de coordenadas: (x1, y1, x2, y2))
			self.canvas.create_oval(80, 60, 120, 100, fill="red", outline="red") # cabeza
			self.canvas.create_line(100, 100, 100, 180, fill="red", width=8) # cuerpo
			self.canvas.create_line(100, 120, 80, 150, fill="red", width=6) # brazo izq
			self.canvas.create_line(100, 120, 120, 150, fill="red", width=6) # brazo der
			self.canvas.create_line(100, 180, 85, 230, fill="red", width=6) # pierna izq
			self.canvas.create_line(100, 180, 115, 230, fill="red", width=6) # pierna der
			self.canvas.create_text(100, 250, text="NO CRUZAR", fill="red", font=("Arial", 14, "bold"))
		else:
			# Persona caminando (verde)
			self.canvas.create_oval(80, 60, 120, 100, fill="#13ECC8", outline="#13ECC8") # cabeza
			self.canvas.create_line(100, 100, 100, 180, fill="#13ECC8", width=8) # cuerpo
			self.canvas.create_line(100, 120, 80, 150, fill="#13ECC8", width=6) # brazo izq
			self.canvas.create_line(100, 120, 120, 150, fill="#13ECC8", width=6) # brazo der
			self.canvas.create_line(100, 180, 85, 230, fill="#13ECC8", width=6) # pierna izq
			self.canvas.create_line(100, 180, 120, 220, fill="#13ECC8", width=6) # pierna der (caminando)
			self.canvas.create_text(100, 250, text="CRUZAR", fill="#13ECC8", font=("Arial", 14, "bold"))

	def cambiar_estado(self):
		self.estado = 1 - self.estado
		self.dibujar_semaforo()
		self.root.after(1200, self.cambiar_estado)

if __name__ == "__main__":
	root = tk.Tk()
	app = SemaforoPeatonalJapones(root)
	root.mainloop()
