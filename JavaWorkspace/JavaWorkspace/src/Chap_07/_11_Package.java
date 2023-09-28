package Chap_07; //소속 명시

import java.util.Random;

public class _11_Package {
    public static void main(String[] args) {
        //패키지(랜덤클래스)
        Random random = new Random();
        System.out.println("랜덤정수 : " + random.nextInt());  //Int의 범위 내에 정수형 값 반환
        System.out.println("랜덤정수(범위) : " + random.nextInt(10)); // 0 ~ 10 사이의 정수형 값 반환
        System.out.println("랜덤실수 : " + random.nextDouble());  // 0.0 ~ 1.0 사이의 실수
        //System.out.println("랜덤실수(범위) : " + random.doubles(5.0)); <불가능>

        double min = 5.0;
        double max = 10.0;
        System.out.println("랜덤실수(범위) : " + (min + (max - min) * random.nextDouble())); // 5 ~ 10사이의 실수

        System.out.println("랜덤 boolean : " + random.nextBoolean());

        //로또 번호를 랜덤으로 뽑으려면 1~45
        System.out.println("로또번호 : " + (random.nextInt(45)+1));
        //nextInt(45) : 0 이상 45 미만
        //nextInt(45)+1 : 1 이상 46 미만



        //구글에 자바 유용한 클래스 서칭해보기
    }
}
