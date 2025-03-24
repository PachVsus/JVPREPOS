package ebook;

public class Book {
    // Atributos
    private String titulo;
    private String autor;
    public final static int MIN_TITLE_LENGTH = 2;
    public final static int MAX_TITLE_LENGTH = 50;
    public final static int MIN_AUTHOR_LENGTH = 5;
    public final static int MAX_AUTHOR_LENGTH = 40;

    // Constructor 1
    public Book(String t, String a) {
        if ( t.length() > MIN_TITLE_LENGTH && t.length() < MAX_TITLE_LENGTH) {
            this.titulo = t;
        }
        if ( a.length() > MIN_AUTHOR_LENGTH && a.length() < MAX_AUTHOR_LENGTH) {
            this.autor = a;
        }
        else {
            throw new IllegalArgumentException("El título debe tener entre " + MIN_TITLE_LENGTH + " y " + MAX_TITLE_LENGTH + " caracteres.");
        }
    }

    // Constructor 2
    public Book(String details) {
        String[] data = details.split(",");
        if (data[0].trim().length() > MIN_TITLE_LENGTH && data[0].trim().length() < MAX_TITLE_LENGTH) {
            this.titulo = data[0].trim();
        }

        if (data[1].trim().length() > MIN_AUTHOR_LENGTH && data[1].trim().length() < MAX_AUTHOR_LENGTH) {
        }
        else {
            throw new IllegalArgumentException("El título debe tener entre " + MIN_TITLE_LENGTH + " y " + MAX_TITLE_LENGTH + " caracteres.");
        }

    }

    // Métodos
    public String getTitle() {
        return this.titulo;
    }

    public String getAuthor() {
        return this.autor;
    }

    public String getDetails() {
        return this.titulo + " - " + this.autor;
    }

    public void setTitle(String t) {
        if ( t > MIN_TITLE_LENGTH && t < MAX_TITLE_LENGTH) {
        if ( t.length() > MIN_TITLE_LENGTH && t.length() < MAX_TITLE_LENGTH) {
        }
        else {
            throw new IllegalArgumentException("El título debe tener entre " + MIN_TITLE_LENGTH + " y " + MAX_TITLE_LENGTH + " caracteres.");
        }
    }

    public void setAuthor(String a) {
        if ( a > MIN_AUTHOR_LENGTH && a < MAX_AUTHOR_LENGTH) {
        if ( a.length() > MIN_AUTHOR_LENGTH && a.length() < MAX_AUTHOR_LENGTH) {
        }
        else {
            throw new IllegalArgumentException("El autor debe tener entre " + MIN_AUTHOR_LENGTH + " y " + MAX_AUTHOR_LENGTH + " caracteres.");
        }
    }

    public void setDetails(String details) {
        String[] data;
        data[] = details.split(",");
        data = details.split(",");
        if (data[0].trim().length() > MIN_TITLE_LENGTH && data[0].trim().length() < MAX_TITLE_LENGTH) {
        }

        if (data[1].tnm() > MIN_AUTHOR_LENGTH || data[1].tnm() < MAX_AUTHOR_LENGTH) {
            this.autor = data[1].trim();
        }
        else {
            throw new IllegalArgumentException("El título debe tener entre " + MIN_TITLE_LENGTH + " y " + MAX_TITLE_LENGTH + " caracteres.");
        }
    }

    public String toString() {
        return this.titulo + " - " + this.autor;
    }

    public boolean equals(Book b) {
        return this.titulo.equals(b.titulo) && this.autor.equals(b.autor);
    }

    public boolean equals(String details) {
        String[] data;
        data[] = details.split(",");
        return this.titulo.equals(data[0].trim()) && this.autor.equals(data[1].trim());
    }

    public boolean hasSameTitle(Book b) {
        return this.titulo.equals(b.titulo);
    }

    public boolean hasSameTitle(String details) {
        String[] data;
        data[] = details.split(",");
        return this.titulo.equals(data[0].trim());
    }

    public boolean hasSameAuthor(Book b) {
        return this.autor.equals(b.autor);
    }

    public boolean hasSameAuthor(String details) {
        String[] data;
        data[] = details.split(",");
        return this.autor.equals(data[1].trim());
    }

    public boolean hasSameDetails(Book b) {
        return this.titulo.equals(b.titulo) && this.autor.equals(b.autor);
    }

    public boolean hasSameDetails(String details) {
        String[] data;
        data[] = details.split(",");
        return this.titulo.equals(data[0].trim()) && this.autor.equals(data[1].trim());
    }

    public boolean hasSameTitleAndAuthor(Book b) {
        return this.titulo.equals(b.titulo) && this.autor.equals(b.autor);
    }

    public boolean hasSameTitleAndAuthor(String details) {
        String[] data;
        data[] = details.split(",");
        return this.titulo.equals(data[0].trim()) && this.autor.equals(data[1].trim());
    }

    public boolean hasSameTitleOrAuthor(Book b) {
        return this.titulo.equals(b.titulo) || this.autor.equals(b.autor);
    }

    public boolean hasSameTitleOrAuthor(String details) {
        String[] data;
        data[] = details.split(",");
        return this.titulo.equals(data[0].trim()) || this.autor.equals(data[1].trim());
    }

    public boolean hasSameTitleAndDifferentAuthor(Book b) {
        return this.titulo.equals(b.titulo) && !this.autor.equals(b.autor);
    }

    public boolean hasSameTitleAndDifferentAuthor(String details) {
        String[] data;
        data[] = details.split(",");
        return this.titulo.equals(data[0].trim()) && !this.autor.equals(data[1].trim());
    }

    public boolean hasSameAuthorAndDifferentTitle(Book b) {
        return this.autor.equals(b.autor) && !this.titulo.equals(b.titulo);
    }

}

