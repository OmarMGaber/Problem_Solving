import java.util.Scanner;

public class A_Elections {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int T = input.nextInt();
        long[] votes = new long[T * 3];
        for (int i = 0; i < votes.length; i++) {
            votes[i] = input.nextInt();
        }

        int index1 = 0, index2 = 1, index3 = 2;
        long a, b, c;
        while (T-- != 0) {
            a = votes[index1];
            b = votes[index2];
            c = votes[index3];

            System.out.print(Math.max(0, Math.max(c, b) + 1 - a) + " ");
            System.out.print(Math.max(0, Math.max(a, c) + 1 - b) + " ");
            System.out.print(Math.max(0, Math.max(a, b) + 1 - c) + " \n");

            index1 += 3;
            index2 += 3;
            index3 += 3;
        }
    }
}
