package Chap_04;

public class _04_SwitchCase {
    public static void main(String[] args) {
        //if , elseif 는 범위조건에서 주로
        //switch는 단적인 값에서 주로

        //Switch case
        //1등 : 전액장학금
        //2등 : 반액장학금
        //3등 : 반액장학금
        //그 외 장학금 대상 아님

        //ifelse를 이용한 방법
        int ranking = 4;
        if(ranking == 1){
            System.out.println("전액장학금");
        } else if (ranking == 2 || ranking == 3) {
            System.out.println("반액장학금");
        } else {
            System.out.println("장학금 대상 아님");
        }
        System.out.println("조회완료");

        //switch를 이용한 방법
        ranking = 1;
        switch (ranking){
            case 1 :
                System.out.println("전액장학금");
                break;
            case 2 :                //2와 3을 통합
            case 3 :
                System.out.println("반액장학금");
                break;
            default :
                System.out.println("장학금대상이 아님");
        }
        System.out.println("조회 완료");

        //중고상품의 가격을 등급에 따라 책정
        int grade = 2;
        int price = 7000;
        switch (grade){
            case 1:
                price += 1000;
            case 2:
                price += 1000;
            case 3:
                price += 1000;
                break;
        }
        System.out.println("상품의 가격은 "+price+"원");
    }
}
