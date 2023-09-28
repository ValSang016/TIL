package Chap_07;

public class _09_GetterSetter {
    public static void main(String[] args) {
        BlackBox b1 = new BlackBox();
        b1.modelName = "까망이";
//        b1.resolution = "FHD";
        b1.price = 300000;
        b1.color = "Black";

        b1.price = -5000;
        System.out.println(b1.modelName + "의 가격 : " + b1.price);

        System.out.println("해상도 : " + b1.resolution);

        BlackBox b2 = new BlackBox();
        b2.setModelName("하양이");
        b2.setPrice(-5000);
        b2.setColor("화이트");

        System.out.println("가격 : " + b2.getPrice() + "원");
        System.out.println("해상도 : " + b2.getResolution());
    }
}
