package Chap_07;

public class _08_Constructor {
    public static void main(String[] args) {
        BlackBox b1 = new BlackBox(); // 생성자는 이 인스턴스변수가 만들어질 때, 반드시 실행되어야 하는 행동임. 초기화작업
        b1.modelName = "까망이";
        b1.resolution = "FHD";
        b1.price = 300000;
        b1.color = "Black";
        System.out.println(b1.modelName);
        System.out.println(b1.serialNumber);

        BlackBox b2 = new BlackBox("하양이", "UHD", 3000000, "White"); //한줄로
         System.out.println(b2.modelName);
        System.out.println(b2.serialNumber);

    }
}
