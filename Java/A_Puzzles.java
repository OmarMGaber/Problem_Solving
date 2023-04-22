import java.util.Scanner;

public class A_Puzzles {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        int m = input.nextInt();
        int[] puzzlePieces = new int[m];
        for (int i = 0; i < m; i++) {
            puzzlePieces[i] = input.nextInt();
        }

        //Sorting the array using selection sort
        for (int i = 0; i < puzzlePieces.length; i++) {
            for (int j = i + 1; j < puzzlePieces.length; j++) {
                if (puzzlePieces[i] > puzzlePieces[j]) {
                    int temp = puzzlePieces[i];
                    puzzlePieces[i] = puzzlePieces[j];
                    puzzlePieces[j] = temp;
                }
            }
        }

        int diff = puzzlePieces[n-1] - puzzlePieces[0];
        for (int i = 0, j = n - 1; i < puzzlePieces.length && j < puzzlePieces.length; i++, j++) {
            if (puzzlePieces[j] - puzzlePieces[i] < diff) {
                diff = puzzlePieces[j] - puzzlePieces[i];
            }
        }
        System.out.println(diff);
    }
}
