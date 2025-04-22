package colecciones;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class persona_1 {

	public static void main(String[] args) {
		List<Persona> personas = new ArrayList<>();
		personas.add(new Persona("Isaian", 25));
		personas.add(new Persona("Carlos", 30));
		personas.add(new Persona("Alvaro", 22));
		System.out.println("Antes de ordenar:");
		for (Persona p : personas) {
			System.out.println(p);
		}
		Collections.sort(personas); // Usa compareTo
		System.out.println("\nDespués de ordenar por edad:");
		for (Persona p : personas) {
			System.out.println(p);
		}
	}
}

class Persona implements Comparable<Persona> {
	private String nombre;
	private int edad;

	public Persona(String nombre, int edad) {
		this.nombre = nombre;
		this.edad = edad;
	}

	public String getNombre() {
		return nombre;
	}

	public int getEdad() {
		return edad;
	}

	@Override
	public String toString() {
		return "Persona{" + "nombre='" + nombre + '\'' + ", edad=" + edad + '}';
	}

	@Override
	public int compareTo(Persona o) {
		return Integer.compare(this.edad, o.edad);
	}
}