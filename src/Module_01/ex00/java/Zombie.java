package Module_01.ex00.java;

public class Zombie {
    private String name;
    private int age;

    public Zombie() {
        this.name = "undfined";
        this.age = 0;
    }

    public Zombie(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String toString() {
        return "Zombie " + name + " is " + age + " years old";
    }
    
}

