import java.util.Scanner;

public class A_Design_Tutorial_Learn_from_Math {

    static boolean isPrime(int x) {
        boolean isPrime = true;

        if (x <= 1) {
            isPrime = false;
            return isPrime;
        } else {
            for (int i = 2; i <= x / 2; i++) {
                if ((x % i) == 0) {
                    isPrime = false;
                    break;
                }
            }
            return isPrime;
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        int x, y;
        x = n / 2;
        y = n - x;
        while (x > 0) {
            if (!isPrime(x) && !isPrime(y)) {
                if (x + y == n) {
                    System.out.println(x + " " + y);
                    return;
                }
            }
            x--;
            y++;
        }
    }
}
