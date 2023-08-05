import java.util.Scanner;

public class A_Stones_on_the_Table {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        String inputString = input.next();
        String unduplicatedString = "";
        int counter = 0;

        for (int i = 0; i < inputString.length(); i++) {
            if (unduplicatedString.endsWith(String.valueOf(inputString.charAt(i)))) {
                counter++;
            } else {
                unduplicatedString += inputString.charAt(i);
            }
        }
        System.out.println(counter);
    }
}

