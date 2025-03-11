package example;

abstract class Animal {
    protected int status;
        public void sleep() {
            System.out.println("I'm sleeping...");
        }
        public void die() {
            System.out.println("I'm dead...");
        }
        public void move() {
            System.out.println("I'm moving...");
        }
        public interface Flyable {
            void fly();
        }
    }

