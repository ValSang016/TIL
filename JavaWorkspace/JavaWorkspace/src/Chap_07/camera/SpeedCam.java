package Chap_07.camera;

public class SpeedCam extends Camera{  //자식클래스
    //하나의 부모로부터만 상속가
    //부모클래스의 변수, 메소드 등 모두 사용가능
    //command + n

    public SpeedCam() {
        super("과속단속카메라");
    }
    public void takePicture(){
        super.takePicture();  //부모클래스의 기능 불러오기
        checkSpeed();
        recognizeLicensePlate();
    }

    public void checkSpeed(){
        System.out.println("속도를 측정합니다.");
    }
    public void recognizeLicensePlate(){
        System.out.println("차량번호를 인식합니다.");
    }

    @Override  //annotation (부모클래스의 메소드를 오버라이드 하는 것이라고 표시) 없어도 됨
    public void showMainFeature() {
            System.out.println(this.name + "의 주요기능 : 속도측정, 번호인식");
    }
}
