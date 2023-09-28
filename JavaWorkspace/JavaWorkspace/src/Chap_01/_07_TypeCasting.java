package chap_01;

public class _07_TypeCasting {  // 복습필ㄹ요ㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛ
    public static void main(String[] args) {
        //형변환 TypeCasting
        //정수형에서 실수형으로
        //실수형에서 정수형으로

        int score = 93;
        System.out.println(score); //93
        System.out.println((float) score);  //93.0
        System.out.println((double) score);  //93.0

        float score_f = 93.3F;
        double score_d = 98.9;
        System.out.println((int) score_f);  //93
        System.out.println((int) score_d);  //98

        //정수 + 실수 연산
        score = 93 + (int) 98.8;  //93+98
        System.out.println(score);

        score_d = (double) 93 + 98.8;
        System.out.println(score_d);
        score_d = 93 + 98.8;   //자동 casting
        System.out.println(score_d);

        //변수에 형 변환 데이터 집어넣기
        double  convertedScoreDouble = score; // 191 -> 191.0
        // int -> long -> float -> double 큰 형태로 갈 때는 자동으로 형변환

        //int convertedScoreInt = score_d; (x)
        int convertedScoreInt = (int) score_d;
        //double -> float -> long -> int 수동변


        //숫자를 문자열로
        String s1 = String.valueOf(63);
        s1 = Integer.toString(63); // 위랑 같은 기능
        System.out.println(s1);

        String s2 = String.valueOf(63.3);
        s2 = Double.toString(63.3); // 위랑 같은 기능
        System.out.println(s2);

        //문자열을 숫자로
        int i = Integer.parseInt("93");
        System.out.println(i); //93
        //double d = Double.parseDouble(98.8);
        //System.out.println(d);
    }
}
