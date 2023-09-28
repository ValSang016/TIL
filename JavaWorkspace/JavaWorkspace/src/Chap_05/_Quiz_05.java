package Chap_05;

public class _Quiz_05 {
    public static void main(String[] args) {
        int[] size = new int[10];
        int plus = 5;

        for (int i = 0; i < size.length; i++) {
            size[i] = 250 + (5 * i);
        }
        for (int i = 0; i < size.length; i++) {
            System.out.println("사이즈 " + size[i] + " (재고있음)");
        }
    }
}
