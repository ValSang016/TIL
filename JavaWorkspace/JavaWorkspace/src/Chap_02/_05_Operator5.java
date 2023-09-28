package Chap_02;

public class _05_Operator5 {
    public static void main(String[] args) {
        //삼항연산자
        //  ( 결과가 저장될 변수) = (조건) ? (참일 경우 결과값) : (거짓일 경우 결과값)
        int x = 5;
        int y = 3;
        int max = (x > y) ? x : y;
        System.out.println(max);

        boolean b = (x == y) ? true : false; //false
        System.out.println(b);
        String s = (x != y) ? "달라요" : "같아요";
        System.out.println(s);
    }
}
