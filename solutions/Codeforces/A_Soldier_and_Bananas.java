import java.util.Scanner;

public class A_Soldier_and_Bananas {
    public static int totalCost(int k, int w) {
        if (w == 0) {
            return 0;
        }
        return k * w + totalCost(k, w - 1);
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int k = input.nextInt();
        int n = input.nextInt();
        int w = input.nextInt();
        if ((totalCost(k, w) - n) < 0) {
            System.out.println(0);
        } else {
            System.out.println(totalCost(k, w) - n);

        }
    }
}