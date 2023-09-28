package Chap_07.camera;

public class Camera { //부모클래스
    public String name;
    public Camera() {  //부모 클래스
        this("카메라");
    }
    protected Camera(String name){
        this.name = name;
    }

    public void takePicture(){
        System.out.println(this.name + " : 사진을 촬영합니다.");
    }
    public void recordVideo(){
        System.out.println(this.name + " : 동영상을 촬영합니다.");
    }


    public void showMainFeature(){
        System.out.println(this.name + "의 주요기능 : 사진 촬영, 동영상 녹화");
    }
}
