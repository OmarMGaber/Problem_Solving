import java.util.Scanner;

public class B_Drinks {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        double sum = 0;
        int n = input.nextInt();
        for (int i = 0; i < n; i++) {
            sum += input.nextInt();
        }
        System.out.println(String.format("%.12f", sum/n));
    }
}