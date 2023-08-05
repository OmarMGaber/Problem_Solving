import java.util.Scanner;

public class A_Expression {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int a = input.nextInt();
        int b = input.nextInt();
        int c = input.nextInt();

        if ((a == 1 && b == 1 && c == 1) || (a == 1 && c == 1)) {
            System.out.println(a + b + c);
        } else if ((a == 1 && b == 1) || (a == 1)) {
            System.out.println((a + b) * c);
        } else if ((b == 1 && c == 1) || (c == 1)) {
            System.out.println(a * (b + c));
        } else if (b == 1) {
            int min = Math.min(a, c);
            int max = Math.max(a, c);
            System.out.println((b + min) * max);
        } else {
            System.out.println(a * b * c);
        }
    }
}
