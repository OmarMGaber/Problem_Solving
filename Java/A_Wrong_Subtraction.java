import java.util.Scanner;

public class A_Wrong_Subtraction {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        int k = input.nextInt();
        int counter = 0;

        while (counter != k) {
            if (n % 10 == 0) {
                n = n / 10;
            } else {
                n = n - 1;
            }
            counter++;
        }
        System.out.println(n);

    }
}