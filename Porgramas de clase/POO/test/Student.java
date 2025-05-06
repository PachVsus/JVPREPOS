package test;

import java.util.Objects;

public class Student implements Comparable<Student>{

	private int id;
	private String name;

	public Student(int id, String name) {
		this.id = id;
		this.name = name;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	@Override
	public boolean equals(Object obj){
		if (this == obj) {
			return true;
		}
		if (obj == null || getClass() != obj.getClass()) {
			return false;
		}
		Student student = (Student) obj;
		return id == student.id && Objects.equals(name, student.name);
	}


    @Override
    public int compareTo(Student student) {
    	/*
        if (this.id == student.id){
            return 0;
        }else if (id > student.id){
            return  1;
        }else{
            return -1;
        }
        */
    	return this.name.compareTo(student.name);    
    }    
    }  


