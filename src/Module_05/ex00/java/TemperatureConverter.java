package Module_05.ex00.java;

import consoleUtils.ConsoleColors;

import java.util.InputMismatchException;
import java.util.Scanner;

public class TemperatureConverter {

    public static double celsiusToFahrenheit(double celsius) throws IllegalArgumentException {
        if (celsius > 1000)
            throw new IllegalArgumentException("Temperature value is too high");
        return (celsius * 1.8 + 32);
    }

    public static double fahrenheitToCelsius(double fahrenheit) throws IllegalArgumentException {
        if (fahrenheit > 1000)
            throw new IllegalArgumentException("Temperature value is too high");
        return (1.8 * (fahrenheit - 32));
    }

    public static void main(String[] args) {
        
        while (true) {
            Scanner scanner = new Scanner(System.in); // Declare scanner outside the try block

            try {
                
                ConsoleColors.printRed("Welcome to this temperature converter");
                ConsoleColors.printGreen("Enter temperature value:");
    
                double temperature = scanner.nextDouble();
                ConsoleColors.printGreen("Enter temperature unit");

                String unit = scanner.next();

                if (unit.equalsIgnoreCase("C")) {
                    temperature = celsiusToFahrenheit(temperature);
                }
                else if (unit.equalsIgnoreCase("F")) {
                    temperature = fahrenheitToCelsius(temperature);
                }
                else if (unit.equalsIgnoreCase("Q")) {
                    scanner.close();
                    break;
                }
                System.out.println("Temperature and unit: " + temperature + " " + unit);
            } catch (InputMismatchException e) {
                System.out.println("Invalid input. Please enter a valid temperature value.");
                scanner.next(); // Clear the invalid input from the scanner
            } catch (IllegalArgumentException e) {
                System.out.println("Temperature too high! Please enter a lower value.");
            } finally {
                // Close the scanner to release system resources
                //scanner.close();
            }
        }
    }
}

