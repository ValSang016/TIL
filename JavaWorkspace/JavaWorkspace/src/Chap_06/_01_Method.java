package Chap_06;

public class _01_Method {
    //메소드(함수)
    public static void sayHello(){
        System.out.println("안녕하세요. 메소드입니다.");
    }

    public static void main(String[] args) {
        System.out.println("메소드 호출전");
        sayHello();
        System.out.println("메소드 호출후");
    }
}
