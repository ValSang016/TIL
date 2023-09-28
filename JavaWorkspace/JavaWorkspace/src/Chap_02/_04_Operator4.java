package Chap_02;

public class _04_Operator4 {
    public static void main(String[] args) {
        //논리연산자
        boolean 김치찌개 = false;
        boolean 계란말이 = false;
        boolean 제육볶음 = true;
        System.out.println(김치찌개 || 계란말이 || 제육볶음); //셋 중 하나만이라도 true일 경우 true
        System.out.println(김치찌개 && 계란말이 && 제육볶음); //셋 모두 true여야 true

        //AND 연산
        System.out.println((5 > 3) && 3 < 4); //true

        //OR 연산
        System.out.println((5 > 3) || (3 > 5)); // true

        // 1 < 3 < 5 연속 불가

        //논리 부정연산자
        System.out.println(!true); // false
        System.out.println(!(5==3)); // true
    }
}
