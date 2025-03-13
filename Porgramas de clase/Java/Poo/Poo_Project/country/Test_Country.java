package country;

import java.util.ArrayList;
import java.util.List;

public class Test_Country {

    public static void main(String[] args) {
//Create three Sportsperson objects
        SportsPerson checoP = new SportsPerson("Checo Pérez");
        SportsPerson hugoS = new SportsPerson("Hugo Sánchez");
        SportsPerson eduardoN = new SportsPerson("Eduardo Nájera");
//Create a country
        Country mexico = new Country("México");
//Create a arraylist and add the sportspersons
        List<SportsPerson> listOfSportsPersons = new ArrayList<SportsPerson>();
        listOfSportsPersons.add(checoP);
        listOfSportsPersons.add(hugoS);
        listOfSportsPersons.add(eduardoN);
//now add this list to Country Class
        mexico.setSportsPerson(listOfSportsPersons);
//Outputting the Has-a association between Country and Sportsperson
        System.out.println(mexico.getName() + " sport team: "
                + mexico.getSportsPerson());
    }
}
