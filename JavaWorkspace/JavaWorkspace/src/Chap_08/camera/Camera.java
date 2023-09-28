package Chap_08.camera;

public abstract class Camera {
    public void takePicture(){
        System.out.println("사진을 촬영합니다.");
    }
    public void recordVideo(){
        System.out.println("촬영을 시작합니다.");
    }

    public abstract void showMainFeature(); //구현해야 하는 메소드

    public abstract void detect();

    public abstract void report();
}
