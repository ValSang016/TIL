package Chap_07;

import Chap_07.camera.Camera;

public class _16_Reference {
    public static void main(String[] args) {
        //참조
        //기본형 자료형 (primitive data types) : int, long, double, float, boolean ..
        int[] i = new int[3];
        System.out.println(i[0]);  // 0

        double[] d = new double[3];
        System.out.println(d[0]);  // 0.0

        //참조 자료형 (non-primitive, reference data types) : String, Camera, FactoryCam..
        String[] s = new String[3];
        System.out.println(s[0]); //null

        Camera[] c = new Camera[3];
        System.out.println(c[0]==null); //true

        //기본자료형은 메소드x, 참조자료형은 메소드를 가질 수 있음.


        int a = 30;
        int b = 10;
        System.out.println(a);
        System.out.println(b);
        b = a;
        System.out.println(a);
        System.out.println(b);
        b = 100;
        System.out.println(a);
        System.out.println(b);

        ////////////////////////

        Camera c1 = new Camera();
        Camera c2 = new Camera();
        c1.name = "카메라1";
        c2.name = "카메라2";
        System.out.println(c1.name);
        System.out.println(c2.name);
        c2 = c1;  //c1이 잡고있는 풍선을 c2도 잡는다.
        System.out.println(c1.name);
        System.out.println(c2.name);
        c2.name = "고장난 카메라"; // 따라서 c2가 잡고 있는 풍선이 바뀌면 c1이 잡고 있는 풍선이 바뀐다는 말과 같다.
        System.out.println(c1.name);
        System.out.println(c2.name);
        //기본자료형은 내용을 복사, 붙여넣기 하는 것이지만
        //참조자료형은 참조하는 장소를 공유하는 것이다
        changeName(c2);
        System.out.println(c1.name);
        System.out.println(c2.name);
        c2 = null; //풍성을 놓게 됨
    }
    public static void changeName(Camera camera){
        camera.name = "잘못된 카메라";
    }
}
