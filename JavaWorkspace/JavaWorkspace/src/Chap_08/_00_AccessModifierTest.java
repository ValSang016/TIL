package Chap_08;

import Chap_07.*; // chap07의 모든 클래스 사용
public class _00_AccessModifierTest {
    public static void main(String[] args) {
        BlackBoxRefurbish b1 = new BlackBoxRefurbish();
        b1.modelName = "까망이"; //public  모든 클래스에서 사용가능
//        b1.resolution = "FHD";  //default  해당 패키지 내에서만 사용가능(다른 패키지라 사용불가능)
//        b1.color = "화이트";     //같은 패키지 내에서만
//        b1.price = 30000;      //해당 클래스에서만

    }
}
