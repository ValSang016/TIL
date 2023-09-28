package Chap_04;

public class _05_For {
    public static void main(String[] args) {
        //반복문 for
        for(int i = 0; i < 10; i++){
            System.out.println("안녕하세요 나코입니다.");
        }
        //fori
        //짝수만 출력
        for (int i = 0; i < 10; i += 2) {
            System.out.print(i);    //println 에서 ln을 빼면 줄바꿈x
        }


        System.out.println(); //줄바

        //홀수만 출력
        for (int i = 1; i < 10; i += 2) {
            System.out.print(i);    //println 에서 ln을 빼면 줄바꿈x
        }

        for (int i = 5; i > 0; i--) {
            System.out.print(i);    //println 에서 ln을 빼면 줄바꿈x
        }

    }
}
