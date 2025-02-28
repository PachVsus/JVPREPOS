package secondpartial;

interface Student {
    void print();
        private final String name;
        private final int id;

interface Employee {
    void print();
    void work();
}

interface Teacher {
    void print();
    void teach();
}

class Herencia {
    class StudentImpl implements Student {
        private String name;
        private int id;

        StudentImpl(String name, int id) {
            this.name = name;
            this.id = id;
        }

        @Override
        public void print() {
            System.out.println("Student Name: " + name + ", ID: " + id);
        }

        @Override
        public void study() {
            System.out.println(name + " is studying.");
        }
    }

    class EmployeeImpl implements Employee {
        private String name;
        private int id;

        EmployeeImpl(String name, int id) {
            this.name = name;
            this.id = id;
        }

        @Override
        public void print() {
            System.out.println("Employee Name: " + name + ", ID: " + id);
        }

        @Override
        public void work() {
            System.out.println(name + " is working.");
        }
    }

    class TeacherImpl implements Teacher {
        private String name;
        private int id;

        TeacherImpl(String name, int id) {
            this.name = name;
            this.id = id;
        }

        @Override
        public void print() {
            System.out.println("Teacher Name: " + name + ", ID: " + id);
        }

        @Override
        public void teach() {
            System.out.println(name + " is teaching.");
        }
    }
}