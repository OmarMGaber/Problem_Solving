import java.util.Scanner;

public class A_Bear_and_Big_Brother {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int a = input.nextInt();
        int b = input.nextInt();

        for (int i = 0; i < b; i++, a = 3 * a, b = 2 * b) {
            if (a > b){
                System.out.println(i);
                return;
            }
        }
    }
}
