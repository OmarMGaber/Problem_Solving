import java.util.Scanner;

public class A_C_Plus_Equal {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int T = input.nextInt();
        int[] values = new int[T * 3];
        for (int i = 0; i < values.length; i++) {
            values[i] = input.nextInt();
        }

        int index1 = 0, index2 = 1, index3 = 2;
        int a, b, n;
        while (T-- != 0) {
            a = values[index1];
            b = values[index2];
            n = values[index3];

            int count = 0;
            while (a <= n && b <= n) {
                if (a < b) {
                    a += b;
                } else {
                    b += a;
                }
                count++;
            }
            System.out.println(count);

            index1 += 3;
            index2 += 3;
            index3 += 3;
        }
    }
}
