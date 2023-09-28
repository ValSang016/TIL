package Chap_06;

public class _04_ParameterAndReturn {
    public static int getPower(int number){  // number 는 parameter(매개변수)
        return number * number;
    }

    public static int getPowerByExp(int number, int exponent){
        int result = 1;
        for (int i = 0; i < exponent; i++) {
            result *= number;
        }
        return result;
    }

    public static void main(String[] args) {
        //전달값, 반환값 모두 있음
        System.out.println(getPower(2));
        System.out.println(getPowerByExp(3,4));

    }
}
