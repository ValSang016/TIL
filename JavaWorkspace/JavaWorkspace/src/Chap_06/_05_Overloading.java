package Chap_06;

public class _05_Overloading {
    public static int getPower(int number){  // number 는 parameter(매개변수)
        return number * number;
    }

    public static int getPower(String strNumber){
        int number = Integer.parseInt(strNumber);
        return number * number;
    }

    public static int getPower(int number, int exponent){
        int result = 1;
        for (int i = 0; i < exponent; i++) {
            result *= number;
        }
        return result;
    }

    public static void main(String[] args) {
        //메소드 오버로딩
        //전달값의 자료형 or 개수가 다른 같은 이름의 메소드를 여러개 생성 가능
        //대신 반환형이 다르면 같은 이름으로 여러 메소드 안됨
        System.out.println(getPower(3));
        System.out.println(getPower("4"));
        System.out.println(getPower(3,3));
    }
}
