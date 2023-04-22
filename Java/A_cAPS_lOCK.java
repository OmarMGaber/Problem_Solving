import java.util.Scanner;

public class A_cAPS_lOCK {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String string = in.nextLine();
        if (string.toUpperCase() == string) {
            System.out.println(string.toLowerCase());
        } else if (string.substring(1).equals(string.toUpperCase().substring(1))) {
            System.out.println(string.toUpperCase().charAt(0) + string.toLowerCase().substring(1));
        } else {
            System.out.println(string);
        }
    }
}
