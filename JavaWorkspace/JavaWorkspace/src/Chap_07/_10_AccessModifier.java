package Chap_07;

public class _10_AccessModifier {
    public static void main(String[] args) {
        //캡슐화(Encapsulation)
        //정보 은닉 ( Information hiding)

        //접근 제어자
        //private : 해당 클래스 내에서만 접근가능
        //public : 모든 클래스에서 접근가능
        //default : (아무것도 적지 않았을 때)해당 패키지 내에서만 접근가능
        //protected : 같은 패키지 내에서, 다른 패키지인 경우 자식클래스에서 접근가능

        BlackBoxRefurbish b1 = new BlackBoxRefurbish();
        b1.modelName = "까망이";
//        b1.resolution = "FHD";
        //b1.price = 300000;  이렇게 직접접근 불가능 => get 메소드 사용하여 접근
        b1.color = "Black";

        b1.setPrice(-5000);
        System.out.println(b1.modelName + "의 가격 : " + b1.getPrice());

        System.out.println("해상도 : " + b1.resolution);

        BlackBoxRefurbish b2 = new BlackBoxRefurbish();
        b2.setModelName("하양이");
        b2.setPrice(-5000);
        b2.setColor("화이트");

        System.out.println("가격 : " + b2.getPrice() + "원");
        System.out.println("해상도 : " + b2.getResolution());
    }
}
