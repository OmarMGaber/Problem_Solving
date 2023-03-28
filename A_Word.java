import java.util.Scanner;

public class A_Word {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int upperCaseCounter = 0;
        int lowerCaseCounter = 0;
        String inputString = input.nextLine();

        for (int i = 0; i < inputString.length(); i++) {
            if (Character.isLowerCase(inputString.charAt(i))) {
                lowerCaseCounter++;
            } else {
                upperCaseCounter++;
            }
        }
        if (upperCaseCounter > lowerCaseCounter) {
            System.out.println(inputString.toUpperCase());
        } else {
            System.out.println(inputString.toLowerCase());
        }
    }
}
