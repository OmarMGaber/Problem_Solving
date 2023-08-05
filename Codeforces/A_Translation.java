import java.util.Scanner;

public class A_Translation {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        String s = input.next();
        String t = input.next();

        if (s.length() != t.length()) {
            System.out.println("NO");
        } else {
            int index = t.length()-1;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) != t.charAt(index)) {
                    System.out.println("NO");
                    return;
                }
                index--;
            }
            System.out.println("YES");
        }
    }
}