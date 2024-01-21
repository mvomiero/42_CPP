public class Megaphone {
    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
        } else {
            for (String arg : args) {
                System.out.print(arg.toUpperCase());
                System.out.println();
            }
        }
    }
}