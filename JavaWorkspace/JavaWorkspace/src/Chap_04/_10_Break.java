package Chap_04;

public class _10_Break {
    public static void main(String[] args) {
        int max = 20;
        for (int i = 1; i <= 50; i++) {
            System.out.println(i + "번 손님 치킨 나왔습니다.");
            if(i == max){
                System.out.println("모두 소진되었습니다.");
                break;
            }
        }
        System.out.println("금일 영업을 종료합니다.");
    }
}
