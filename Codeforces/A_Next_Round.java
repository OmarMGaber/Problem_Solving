import java.util.*;
import java.util.ArrayList;

public class A_Next_Round {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        int k = input.nextInt();

        ArrayList<Integer> scoresArrayList = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) {
            scoresArrayList.add(input.nextInt());
        }
        int counter = 0;
        int index = k - 1;
        if (scoresArrayList.get(0) != 0) {
            for (int i = 0; i < scoresArrayList.size(); i++) {
                if (scoresArrayList.get(index) == 0) {
                    index--;
                }
                if (scoresArrayList.get(i) >= scoresArrayList.get(index)) {
                    counter++;
                }
            }
        }
        System.out.println(counter);
    }
}