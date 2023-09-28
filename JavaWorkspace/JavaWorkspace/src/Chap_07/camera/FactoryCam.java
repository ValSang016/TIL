package Chap_07.camera;

public class FactoryCam extends Camera { //자식클래스
    public FactoryCam() {
        super("공장 카메라");
    }
    public void recordVideo(){
        super.recordVideo(); //부모클래스의 기능 불러오기
        detectFire();
    }
    public  void detectFire(){
        System.out.println("화재를 감지합니다.");
    }

    public void showMainFeature(){
        System.out.println(this.name + "의 주요기능 : 화재감지");
    }
}
