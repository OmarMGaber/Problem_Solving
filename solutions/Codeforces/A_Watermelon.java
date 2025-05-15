import java.util.Scanner;

public class Watermelon {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int w = input.nextInt();
        if (w > 2) {
            if ((w % 2) == 0) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        } else {
            System.out.println("NO");
        }
    }
}