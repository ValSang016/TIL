package Chap_05;

public class _05_ASKII {
    public static void main(String[] args) {
        char c = 'A';
        System.out.println(c);
        System.out.println((int)c);

        String[][] seats3 = new String[10][15];
        for (int i = 0; i < seats3.length; i++) {
            for (int j = 0; j < seats3[i].length; j++) {
                seats3[i][j] = String.valueOf(c) + (j + 1);
            }
            c++;
        }
        for (int i = 0; i < seats3.length; i++) {
            for (int j = 0; j < seats3[i].length; j++) {
                System.out.print(seats3 [i][j] + " ");
            }
            System.out.println();
        }
    }
}
