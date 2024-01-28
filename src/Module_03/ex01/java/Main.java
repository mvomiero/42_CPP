package Module_03.ex01.java;

import consoleUtils.ConsoleColors;

public class Main {
    public static void main(String[] args) {
        Shape shape = new Circle("red", 5);
        ConsoleColors.printRed(shape.getColor()); // Output: red
        ConsoleColors.printRed(shape.introduce());
        System.out.println(shape.getArea()); // Output: 78.5
        
        shape = new Rectangle(2f, 5f);
        ConsoleColors.printGreen(shape.introduce());
        ConsoleColors.printGreen(shape.getColor());
        System.out.println(shape.getArea());

        shape = new Square(2f);
        System.out.println(shape.getArea());
    }
    
}
