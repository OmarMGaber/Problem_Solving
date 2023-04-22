import java.util.Scanner;

public class A_Sum {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int t = input.nextInt();
        int index1 = 0;
        int index2 = 1;
        int index3 = 2;
        int[] array = new int[t*3];
        for(int i = 0; i < t*3; i++){
            array[i] = input.nextInt();
        }

        while(index3 < t*3){
            if(array[index1] + array[index2] == array[index3]){
                System.out.println("YES");
            } else if(array[index1] + array[index3] == array[index2]){
                System.out.println("YES");
            } else if(array[index3] + array[index2] == array[index1]){
                System.out.println("YES");
            }
            else {
                System.out.println("NO");
            }
            index1 += 3;
            index2 += 3;
            index3 += 3;
        }
    }
}
