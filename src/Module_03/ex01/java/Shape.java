package Module_03.ex01.java;

public class Shape {
    protected String color;

    public void setColor(String color) {
        this.color = color;
    }

    public String getColor() {
        return this.color;
    }

    public float getArea() {
        return 1;
    }

    public String introduce() {
        return ("I am a newly created shape");
    }
}
