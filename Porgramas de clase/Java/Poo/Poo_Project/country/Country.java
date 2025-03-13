package country;

import java.util.*;
//Country class

class Country {

    private String name;
    List<SportsPerson> sportsPerson;
//to assign Country name

    public Country(String name) {
        this.name = name;
    }

    public String getName() {
        return this.name;
    }
//To assign sportsPerson

    public void setSportsPerson(List<SportsPerson> sportsPerson) {
        this.sportsPerson = sportsPerson;
    }

    public List<String> getSportsPerson() {
        List<SportsPerson> sList = this.sportsPerson;
        List<String> names = new ArrayList<String>();
        for (SportsPerson sp : sList) {
            names.add(sp.getName());
        }
        return names;
//return this.sportsPerson;
    }
}
