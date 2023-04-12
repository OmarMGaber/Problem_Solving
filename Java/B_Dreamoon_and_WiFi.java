import java.util.Scanner;

public class B_Dreamoon_and_WiFi {
    static Scanner input = new Scanner(System.in);
    static String s1 = input.nextLine();
    static String s2 = input.nextLine();
    static int[] unrecognizedPos = new int[10];
    static int counter = 0;
    static int sucsses = 0;

    static boolean isEqual(String s1, String s2) {
        int counterX1 = 0;
        int counterX2 = 0;
        int counterY1 = 0;
        int counterY2 = 0;

        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) == '+') {
                counterX1++;
            }
            if (s2.charAt(i) == '+') {
                counterX2++;
            }
            if (s1.charAt(i) == '-') {
                counterY1++;
            }
            if (s2.charAt(i) == '-') {
                counterY2++;
            }

        }
        return (counterX1 == counterX2) && (counterY1 == counterY2);
    }

    static int findPosition(String s) {
        int position = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '+') {
                position++;
            }
            if (s.charAt(i) == '-') {
                position--;
            }
        }
        return position;
    }

    static void calculatePossibilities(String s, int newCounter) {
        if (newCounter == 0) {
            if (findPosition(s) == findPosition(s1)) {
                sucsses++;
            }
            return;
        }

        StringBuilder temp1 = new StringBuilder(s);
        StringBuilder temp2 = new StringBuilder(s);
        newCounter--;
        temp1.setCharAt(unrecognizedPos[newCounter], '+');
        calculatePossibilities(temp1.toString(), newCounter);

        temp2.setCharAt(unrecognizedPos[newCounter], '-');
        calculatePossibilities(temp2.toString(), newCounter);

    }

    static double calculateProbability(String s2) {
        int unrecognized = 0;

        for (int i = 0; i < s2.length(); i++) {
            if (s2.charAt(i) == '?') {
                unrecognized++;
                unrecognizedPos[counter++] = i;
            }
        }
        calculatePossibilities(s2, counter);

        return sucsses / (Math.pow(2, unrecognized));
    }

    public static void main(String[] args) {
        if (isEqual(s1, s2)) {
            System.out.printf("%.12f", 1.0);
        } else {
            System.out.printf("%.12f", calculateProbability(s2));
        }
    }
}