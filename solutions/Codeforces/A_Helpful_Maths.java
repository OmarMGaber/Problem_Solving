import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class A_Helpful_Maths {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        String s = input.next();
        ArrayList numbers = new ArrayList();

        for (int i = 0; i < s.length(); i++) {
            if (Character.isDigit(s.charAt(i))) {
                numbers.add(Integer.parseInt(String.valueOf(s.charAt(i))));
            }
        }

        Collections.sort(numbers);

        for (int i = 0; i < numbers.size(); ) {
            System.out.print(numbers.get(i++));
            if (i != numbers.size()) {
                System.out.print("+");
            }
        }
    }
}
