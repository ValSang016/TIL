package Chap_07;

import Chap_07.camera.*;

public class _15_Super {
    //super 부모의 변수, 메소드에 접근
    public static void main(String[] args) {
        FactoryCam factoryCam = new FactoryCam();
        SpeedCam speedCam = new SpeedCam();

        factoryCam.recordVideo();
        speedCam.takePicture();
    }
}
