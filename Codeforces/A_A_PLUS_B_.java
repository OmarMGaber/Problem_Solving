import java.util.Scanner;

public class A_A_PLUS_B_ {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int t = in.nextInt();
        String[] strings = new String[t];
        for (int i = 0; i < t; i++) {
            strings[i] = in.next();
        }
        int i = 0;
        while (t-- != 0) {
            int a = Integer.parseInt(String.valueOf(strings[i].charAt(0)));
            int b = Integer.parseInt(String.valueOf(strings[i++].charAt(2)));

            System.out.println(a + b);
        }
    }
}
