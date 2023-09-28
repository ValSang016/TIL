package Chap_06;

public class _08_MainMethod {
    public static void main(String[] args) {
        for (String s : args) {
            System.out.println(s);
        }
        if (args.length == 1){
            switch (args[0]) {
                case "1":
                    System.out.println("도서조회 메뉴입니다.");
                    break;
                case "2":
                    System.out.println("도서대출 메뉴입니다.");
                    break;
                case "3":
                    System.out.println("도서반납 메뉴입니다.");
                    break;
                default:
                    System.out.println("잘못 입력하셨습니다.");
            }
        } else {
            System.out.println("사용법) 1 ~ 3 메뉴를 입력해주세요.");
        }
    }
}
