package Module_01.ex01.java;


public class Zombie {
    private String name;

    public Zombie(String name) {
        this.name = name;
    }

    public String announce() {
        return ("Zombie " + name + " says: Brainzzzzz!");
    }
}