package consoleUtils;

public class ConsoleColors {
    public static final String RESET = "\033[0m";  // Text Reset
    public static final String RED_BOLD = "\033[1;31m"; // RED
    public static final String GREEN_BOLD = "\033[1;32m"; // GREEN
    public static final String YELLOW_BOLD = "\033[1;33m"; // YELLOW
    public static final String BLUE_BOLD = "\033[1;34m"; // BLUE

    public static void printRed(String message) {
        System.out.println(RED_BOLD + message + RESET);
    }
    
}
