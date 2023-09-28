package Chap_03;

public class _Quiz_03 {
    public static void main(String[] args) {
        String num;
        num = "011026-3455567";

        System.out.println(num.substring(0, 8));
        System.out.println(num.substring(0, num.indexOf("-") + 2));
    }
}

