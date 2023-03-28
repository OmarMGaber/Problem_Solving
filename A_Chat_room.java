import java.util.*;

public class A_Chat_room {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        String inputString = input.nextLine();
        String hello = "hello";
        int index = 0;
        for (int i = 0; i < inputString.length(); i++) {
            if (inputString.charAt(i) == hello.charAt(index)) {
                index++;
                if (index == 5) {
                    System.out.println("YES");
                    return;
                }
            }
        }
        System.out.println("NO");
    }
}