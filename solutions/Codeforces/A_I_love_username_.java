import java.util.Scanner;

public class A_I_love_username_ {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        int[] points = new int[n];
        for (int i = 0; i < n; i++) {
            points[i] = input.nextInt();
        }

        int max = points[0];
        int min = points[0];
        int counter = 0;

        for (int i = 0; i < n; i++) {
            if (points[i] > max) {
                max = points[i];
                counter++;
            } else if (points[i] < min) {
                min = points[i];
                counter++;
            }
        }
        System.out.println(counter);
    }
}