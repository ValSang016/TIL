package Chap_04;

public class _03_ElseIf {
    public static void main(String[] args) {
        //조건문 ElseIf
        //한라봉에이드가 있다면 +1 또는 망고주스가 있다면 +1 또는 아이스아메리카노가 있다면 +1
        boolean hallabongaAde = false;
        boolean mangoJuice = true;

        if (hallabongaAde) {
            System.out.println("한라봉에이드 +1");
        } else if (mangoJuice) {
            System.out.println("망고주스 +1");
        } else {
            System.out.println("아이스아메리카노 +1");
        }
        System.out.println("커피주문완료");

        //elseif는 여러번 사용가능하며
        //else는 필수가 아님
    }
}
