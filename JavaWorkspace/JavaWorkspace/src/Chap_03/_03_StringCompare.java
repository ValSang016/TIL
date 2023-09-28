package Chap_03;

public class _03_StringCompare {
    public static void main(String[] args) {
        String s1 = "Java";
        String s2 = "Python";

        System.out.println(s1.equals(s2)); //같은면 true
        System.out.println(s1.equals("Java"));

        System.out.println(s2.equals("python"));
        System.out.println(s2.equalsIgnoreCase("python")); //대소문자 구분없이 문자열이 같은

        //문자열 비교 심화
        s1 = "1234";      // s1과 s2 모두 같은 참조를 가르킴
        s2 = "1234";
        System.out.println(s1.equals(s2));   //true
        System.out.println(s1 == s2);     // true

        s1 = new String("1234");  //s1과 s2가 다른 참조
        s2 = new String("1234");
        System.out.println(s1.equals(s2));  // true (내용을 비교)
        System.out.println(s1 == s2);  //false (참조를 비교)
    }
}
