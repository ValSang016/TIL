package Chap_03;

public class _01_String1 {
    public static void main(String[] args) {
        String s = "I like Java and Python and C.";
        System.out.println(s);

        //문자열의 길이
        System.out.println(s.length());
        //대소문자 변환
        System.out.println(s.toUpperCase());
        //소문자 변환
        System.out.println(s.toLowerCase());

        //포함관계
        System.out.println(s.contains("Java"));  //true
        System.out.println(s.contains("C#"));   //false

        System.out.println(s.indexOf("Java"));  //위치정보  0부터 시작해서 7의 위치에 있음
        System.out.println(s.indexOf("C#"));  //포함되지 않았다면 -1

        System.out.println(s.indexOf("and"));  //맨앞
        System.out.println(s.lastIndexOf("and"));   //맨뒤부터

        System.out.println(s.startsWith("I"));  //이 문자열로 시작하면 true (아니라면 false)
        System.out.println(s.endsWith("."));   //이 문자열로 끝나면 true

    }
}
