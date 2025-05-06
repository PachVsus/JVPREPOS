package test;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;

public class Test_Student_wIterator {

	public static void main(String[] args) {

		List<Student> studentList =  new ArrayList<>();
		Student student1 = new Student(321, "Karla");
		Student student2 = new Student(100, "Daniel");
		Student student3 = new Student(127, "Alejandro");
		Student student4 = new Student(321, "Carlos");

		studentList.add(student1);
		studentList.add(student2);
		studentList.add(student3);
		studentList.add(student4);
		
		Iterator<Student> iterator = studentList.iterator();
		while( iterator.hasNext()) {
			Student s = iterator.next();
			if (s.getName().equals("Karla"))
				iterator.remove();
			    //studentList.remove(s);  //Concurrency problem
		}
		// Remove an element from list without use iterator
		for( int i=0; i < studentList.size(); i++) {
			if (studentList.get(i).getName().equals("Karla")) {
				studentList.remove(i);	
			}			
		}
		// Print the list 
	    for( Student s : studentList) {
	    	System.out.println(s.getName());
	    }
	}	
}


