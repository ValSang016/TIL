package Chap_04;

public class _11_Continue {
    public static void main(String[] args) {
        int max = 20;
        int sold = 0;
        int noShow = 17;
        for (int i = 1; i <= 50; i++) {
            System.out.println(i + "번 손님 주문하신 치킨 나왔습니다.");

            //손님이 없다면
            if(i == noShow){
                System.out.println(i + "번 손님 없으시면 다음 손님 드리겠습니다.");
                continue;
            }
            sold++;  //판매처리
            if(sold == max){
                System.out.println("재고가 소진되었습니다.");
                break;
            }
        }
    }
}
