package Chap_04;

public class _01_If {
    public static void main(String[] args) {
        //조건문 IF
        int hour = 15; //10시
        if(hour < 14){
            System.out.println("아이스아메리카노 +1");
        }
        System.out.println("커피 주문완료.");

        //오후 두 시 이전에 커피를 마시지 않은 경우
        hour = 10;
        boolean morningCoffee = false;

        if(hour < 14 && !morningCoffee){
            System.out.println("아이스아메리카노 +1");
        }
    }
}


