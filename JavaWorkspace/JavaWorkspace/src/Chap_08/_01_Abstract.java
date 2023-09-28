package Chap_08;

import Chap_08.camera.Camera;
import Chap_08.camera.FactoryCam;
import Chap_08.camera.SpeedCam;

public class _01_Abstract {
    public static void main(String[] args) {
        //데이터 추상화 (Data Abstraction)
        //Abstract
        //추상 클래스 : 아직 완성되지 않은 클래스 (객체화 불가능)
        //추상 메소드 : 추상 클래스 또는 인터페이스에서 사용 가능한, 껍데기만 있는 메소드)

//        Camera camera = new camera; (객체화 불가능)
        FactoryCam factoryCam = new FactoryCam();
        factoryCam.showMainFeature();

        SpeedCam speedCam = new SpeedCam();
        speedCam.showMainFeature();

        Camera factory = new FactoryCam();
        factory.showMainFeature();

        Camera speed = new SpeedCam();
        speed.showMainFeature();

    }
}
