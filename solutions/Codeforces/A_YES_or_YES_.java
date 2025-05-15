import java.util.*;

public class A_YES_or_YES_ {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int size = input.nextInt();
        String[] s = new String[size];
        for (int i = 0; i < size; i++) {
            s[i] = input.next();
        }

        for (int i = 0; i < size; i++) {
            if (s[i].toUpperCase().equals("YES")) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}