import java.util.*;
import java.util.ArrayList;

public class A_Petya_and_Strings {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        String string1 = (input.nextLine()).toLowerCase();
        String string2 = (input.nextLine()).toLowerCase();

        if (string1.compareTo(string2) == 0) {
            System.out.println("0");
        }
        if (string1.compareTo(string2) > 0) {
            System.out.println("1");
        }
        if (string1.compareTo(string2) < 0) {
            System.out.println("-1");
        }
    }
}