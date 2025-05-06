// Nombre: Jesús Vargas Pacheco
// Archivo: Main.java
// Descripción: Demostración de iterator, validación de números, streams y operaciones con fechas


package test;

import java.time.LocalDate;
import java.util.*;

public class Test {

    public static void main(String[] args) {
        System.out.println("=== 1. Uso de iterator() ===");
        testIterator();

        System.out.println("\n=== 2. Es número par? ===");
        System.out.println("10 es par: " + esPar(10));
        System.out.println("7 es par: " + esPar(7));

        System.out.println("\n=== 3. Es número palíndromo? ===");
        System.out.println("454: " + esPalindromo(454));
        System.out.println("345: " + esPalindromo(345));

        System.out.println("\n=== 4. Múltiplo de 5 y 3? ===");
        System.out.println("15: " + esMultiploDe5y3(15));
        System.out.println("10: " + esMultiploDe5y3(10));

        System.out.println("\n=== 5. Lista palabras ordenadas y con trim() ===");
        List<String> listaPalabras = List.of(" java ", " python ", "     c#  ", "   c++");
        List<String> procesadas = listaPalabras.stream()
            .map(String::trim)
            .sorted()
            .toList();
        System.out.println(procesadas);

        System.out.println("\n=== 6. Lista sin duplicados y en minúsculas ===");
        List<String> lista = List.of("Java", "java", "Python", "PYTHON");
        List<String> resultado = lista.stream()
            .map(String::toLowerCase)
            .distinct()
            .toList();
        System.out.println(resultado);

        System.out.println("\n=== 7. Máximo y mínimo de lista de enteros ===");
        List<Integer> nums = Arrays.asList(1, 717, 15, 104, 3, -5, 54, -1, 24, 33);
        int max = nums.stream().max(Integer::compareTo).orElseThrow();
        int min = nums.stream().min(Integer::compareTo).orElseThrow();
        System.out.println("Máximo: " + max);
        System.out.println("Mínimo: " + min);

        System.out.println("\n=== 8. Fechas del 1 de mayo: años únicos ordenados ===");
        List<LocalDate> dateList = List.of(
            LocalDate.of(2025, 11, 27),
            LocalDate.of(2025, 5, 1),
            LocalDate.of(2020, 4, 5),
            LocalDate.of(2020, 5, 1),
            LocalDate.of(2024, 2, 29)
        );
        List<Integer> yearList = dateList.stream()
            .filter(d -> d.getDayOfMonth() == 1 && d.getMonthValue() == 5)
            .map(LocalDate::getYear)
            .distinct()
            .sorted()
            .toList();
        System.out.println(yearList);
    }

    public static void testIterator() {
        List<Student> studentList = new ArrayList<>();
        studentList.add(new Student(321, "Karla"));
        studentList.add(new Student(100, "Daniel"));
        studentList.add(new Student(127, "Alejandro"));
        studentList.add(new Student(321, "Carlos"));

        Iterator<Student> iterator = studentList.iterator();
        while (iterator.hasNext()) {
            Student s = iterator.next();
            if (s.getName().equals("Karla")) {
                iterator.remove(); // forma segura de eliminar durante iteración
            }
        }

        for (Student s : studentList) {
            System.out.println(s.getName());
        }
    }

    public static boolean esPar(int numero) {
        return numero % 2 == 0;
    }

    public static boolean esPalindromo(int numero) {
        String numStr = String.valueOf(numero);
        return numStr.equals(new StringBuilder(numStr).reverse().toString());
    }

    public static boolean esMultiploDe5y3(int numero) {
        return numero % 5 == 0 && numero % 3 == 0;
    }
}

// Clase Student usada en el ejemplo
class Student implements Comparable<Student> {
    private int id;
    private String name;

    public Student(int id, String name) {
        this.id = id;
        this.name = name;
    }

    public int getId() { return id; }
    public String getName() { return name; }

    @Override
    public int compareTo(Student other) {
        return this.name.compareTo(other.name);
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (!(obj instanceof Student)) return false;
        Student s = (Student) obj;
        return id == s.id && Objects.equals(name, s.name);
    }

    @Override
    public int hashCode() {
        return Objects.hash(id, name);
    }
}
