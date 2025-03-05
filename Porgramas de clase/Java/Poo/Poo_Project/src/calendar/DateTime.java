public class DateTime {
    // Clase base Book
static class Book {
    private final String title;
    private final String author;
    private final int pages;

    // Constructor
    public Book(String title, String author, int pages) {
        this.title = title;
        this.author = author;
        this.pages = pages;
    }

    // Método para obtener información del libro
    public String getInfo() {
        return "'" + title + "' by " + author + ", " + pages + " pages";
    }
}

// Subclase EBook que hereda de Book
static class EBook extends Book {
    private final String fileFormat;

    // Constructor
    public EBook(String title, String author, int pages, String fileFormat) {
        super(title, author, pages);
        this.fileFormat = fileFormat;
    }

    // Sobrescribiendo el método getInfo para incluir el formato del archivo
    @Override
    public String getInfo() {
        return super.getInfo() + ", Format: " + fileFormat;
    }
}

// Clase principal para probar el código
public static class Main {
    public static void main(String[] args) {
        // Creación de objetos
        Book book = new Book("Cien años de soledad", "Gabriel García Márquez", 471);
        EBook ebook = new EBook("1984", "George Orwell", 328, "PDF");

        // Mostrar información
        System.out.println(book.getInfo());  // 'Cien años de soledad' by Gabriel García Márquez, 471 pages
        System.out.println(ebook.getInfo()); // '1984' by George Orwell, 328 pages, Format: PDF
    }
}

}