package Module_03.ex01.java;

public class Circle extends Shape {
    protected float radius;

    Circle(String color, float radius) {
        this.color = color;
        this.radius = radius;
    }

    public float getArea() {
        return (radius* radius * 3.14f);
    }
}
