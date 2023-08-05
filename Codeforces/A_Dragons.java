import java.util.Scanner;

public class A_Dragons {
    // A simple Java class that acts like a struct
    public static class Dragons {
        int strengh, bonus;

        public Dragons(int strengh, int bonus) {
            this.strengh = strengh;
            this.bonus = bonus;
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int s = input.nextInt();
        int n = input.nextInt();
        Dragons[] dragonsArray = new Dragons[n];
        for (int i = 0; i < dragonsArray.length; i++) {
            dragonsArray[i] = new Dragons(input.nextInt(), input.nextInt());
        }
        // Sorting the dragons by strengths.
        Dragons temp;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (dragonsArray[i].strengh > dragonsArray[j].strengh) {
                    temp = dragonsArray[j];
                    dragonsArray[j] = dragonsArray[i];
                    dragonsArray[i] = temp;
                }
            }
        }

        int counter = 0;
        while (counter != dragonsArray.length) {
            if (s > dragonsArray[counter].strengh) {
                s += dragonsArray[counter++].bonus;
            } else {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}
