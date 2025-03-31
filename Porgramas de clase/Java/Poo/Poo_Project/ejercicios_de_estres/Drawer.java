package ejercicios_de_estres;

public class Drawer {
    private Object objectInside = null;

    public void put(Object o) {
        if (this.objectInside == null)
            this.objectInside = o;
    }

    public Object peek() {
        return this.objectInside;
    }

    public Object remove() {
        Object tmp = this.objectInside;
        this.objectInside = null;
        return tmp;
    }
}
