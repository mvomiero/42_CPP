package Module_01.ex00.java;
import consoleUtils.ConsoleColors;

public class Main {
    public static void main(String[] args) {
        Zombie zombie = new Zombie("Zozo", 20);
        Zombie zombie2 = new Zombie(/* "Zozo", 20 */);
        System.out.println(zombie);
        ConsoleColors.printRed(zombie.toString());
        System.out.println(zombie2);
        ConsoleColors.printRed(zombie2.toString());
    }
}
