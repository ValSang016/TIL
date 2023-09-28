package Chap_07;

import Chap_07.camera.Camera;
import Chap_07.camera.FactoryCam;
import Chap_07.camera.SpeedCam;

public class _13_MethodOverriding {
    public static void main(String[] args) {
        //메소드오버라이딩 : 자식 클래스에서 부모 클래스의 메소드 덮어씌우 (재정의)
        Camera camera = new Camera();
        FactoryCam factoryCam = new FactoryCam();
        SpeedCam speedCam = new SpeedCam();

        camera.showMainFeature();
        factoryCam.showMainFeature();
        speedCam.showMainFeature();
    }
}
