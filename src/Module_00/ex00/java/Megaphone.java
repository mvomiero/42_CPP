public class Megaphone {
    private static String[] uppercaseArgs;

    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
        } else {
            uppercaseArgs = new String[args.length];

            for (int i = 0; i < uppercaseArgs.length; i++) {
                uppercaseArgs[i] = args[i].toUpperCase();
            }
            for (String arg : args) {
                System.out.print(arg.toUpperCase());
                System.out.println();
            }
            for (String arg : args) {
                System.out.print("original str: " + arg + "\n");
            }
            for (String arg : uppercaseArgs) {
                System.out.print("uppercase str: " + arg + "\n");
            }
        }
    }
}