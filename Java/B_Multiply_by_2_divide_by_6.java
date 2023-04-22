import java.util.Scanner;

public class B_Multiply_by_2_divide_by_6 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();
        int[] array = new int[t];
        for (int i = 0; i < t; i++) {
            array[i] = scanner.nextInt();
        }
        int i = 0;
        while (t-- > 0) {
            int n = array[i++];
            int moves = 0;

            if (n == 1) {
                System.out.println(0);
                continue;
            }
            while (n != 1) {
                if (n % 6 == 0) {
                    n = n / 6;
                    moves++;
                } else if (n % 3 == 0) {
                    n *= 2;
                    moves++;
                } else {
                    moves = -1;
                    break;
                }
            }
            System.out.println(moves);
        }
    }
}
