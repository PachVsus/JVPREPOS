// Una clase singleton es una clase que solo puede tener una instancia en toda la apliacion.
// En este caso, la clase Persona es un ejemplo de una clase singleton.
// La clase Persona tiene un constructor privado, lo que significa que no se puede crear una instancia de la clase desde fuera de la clase.
// La clase Persona tiene un atributo privado que almacena la única instancia de la clase.

package singleton;

public class Persona {
    private static final Persona INSTANCE = new Persona(); // Instancia única de la clase
    // Método estático para obtener la instancia única de la clase
    // Atributos de la clase
    private String nombre;
    private int edad;
    private Persona() {
        // Constructor privado para evitar la creación de instancias desde fuera de la clase
        this.nombre = "Dummy";
        this.edad = 21;
    }
    // Metodos = acciones que puede hacer el objeto
    void caminar() {
        System.out.println("Caminando...");
    }
    public static Persona getInstance() { // getter de la instancia única
        // Método estático para obtener la instancia única de la clase
        return INSTANCE;
    }
}

// 3 pasos:
// 1. Constructor privado
// 2. final staic class
// 3. getter de la instancia única
