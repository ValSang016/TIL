package Chap_05;

public class _01_Array {
    public static void main(String[] args) {

        //첫번째 방법
        //String[] coffees = new String[4];

        //두번째 방법
        //String coffees[] = new String[4];
//        coffees[0] = "아메리카노";
//        coffees[1] = "카페라떼";
//        coffees[2] = "모카";
//        coffees[3] = "카푸치노";

        //세번째 방법
//        String [] coffees = new String[] { "아메리카노", "카페라떼", "카페모카", "카푸치노"};

        //네번째 방법
        String [] coffees = { "아메리카노", "카페라떼", "카페모카", "카푸치노"};
        System.out.println(coffees[0] + " 하나");
        System.out.println(coffees[1] + " 하나");
        coffees[2] = "에스프레소";
        System.out.println(coffees[2] + " 하나");
        System.out.println(coffees[3] + " 하나");
        System.out.println("주세요.");

        //다른 자료형들
        int[] i = new int[3];
        double[] d = new double[] {10.0 , 2.1, 33.0};
        boolean[] b = {true, false, true};
    }
}
