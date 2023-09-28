package Chap_07.camera;

public final class ActionCam extends Camera { //final 클래스로 바꾸면 상속 불가능
    public final String lens; // = "광각렌즈";
    public ActionCam() {
        super("액션카메라");
        lens = "광각렌즈";
    }

    public final void makeVideo(){
        System.out.println(this.name + " : " + this.lens + "로 촬영한 멋진 비디오를 제작합니다.");
    }
}
