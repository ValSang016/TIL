package Chap_06;

public class _06_WhenToUse {

    public static int getPower(int number){
        return getPower(number, 2);
    }
    public static  int getPower(int number, int exponent) {
        int result = 1;
        for (int i = 0; i < exponent; i++) {
            result *= number;
        }
        return result;
    }
    public static void main(String[] args) {
        System.out.println(getPower(4));
        //같은 기능의 코드를 여러번 쓰게 될 때, 일일이 작성하지 않고 메소드를 사용한다면
        //유지보수가 용이해지고 코드의 효율성이 좋아진다.
    }
}
