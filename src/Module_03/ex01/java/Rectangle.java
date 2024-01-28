package Module_03.ex01.java;

public class Rectangle extends Shape {
    private float height;
    private float width;

    Rectangle (float height, float width) {
        this.height = height;
        this.width = width;
    }

    public float getArea() {
        return (height * width);
    }

    public String introduce() {
        return ("I have four corners :)");
    }
}