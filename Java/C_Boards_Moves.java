import java.util.Scanner;

public class C_Boards_Moves {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
        int[] values = new int[t];
        for (int i = 0; i < t; i++) {
            values[i] = input.nextInt();
        }
        int i = 0;
        while (t-- != 0) {
            long n = values[i++];
            long result = 0;
            long level = 0;
            long vertex = 0;

            for (long j = 1; j <= n; j += 2) {
                result += level * vertex;
                level++;
                vertex += 8;
            }
            System.out.println(result);
        }
    }
}