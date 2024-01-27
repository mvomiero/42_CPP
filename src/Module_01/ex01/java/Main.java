package Module_01.ex01.java;
import consoleUtils.ConsoleColors;

public class Main {
    public static void main(String[] args) {
        final int N = 4;
        Zombie[] zombies = new Zombie[N];

        for (int i = 0; i < N; i++) {
            zombies[i] = i % 2 == 0 ? new Zombie("giorgio") : new Zombie("lucia");
        }

        for (int i = 0; i < N; i++) {
    if (i % 2 == 0) {
        ConsoleColors.printRed(zombies[i].announce());
    } else {
        ConsoleColors.printGreen(zombies[i].announce());
    }
}

}
}
