import java.util.*;

public class A_Theatre_Square {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        double n = input.nextInt();
        double m = input.nextInt();
        double a = input.nextInt();

        System.out.println((long) (Math.ceil(n / a) * Math.ceil(m / a)));
    }
}