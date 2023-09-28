package Chap_07;

import Chap_07.camera.Camera;
import Chap_07.camera.FactoryCam;
import Chap_07.camera.SpeedCam;

public class _14_Polymorphism_R {
    public static void main(String[] args) {
        //다형성
//    Camera camera = new Camera();
//    FactoryCam factoryCam = new FactoryCam();
//    SpeedCam speedCam = new SpeedCam();

        //IS-A 규칙
        //class person : 사람
        //class student extends person : 학생 (student is a person) 반대는 안됨
        //class teacher extends person : 선생님 (teacher is a person)

        Camera camera = new Camera();
        Camera factoryCam = new FactoryCam();
        Camera speedCam = new SpeedCam();

        Camera[] cameras = new Camera[3];
        cameras[0] = new Camera();
        cameras[1] = new FactoryCam();
        cameras[2] = new SpeedCam();

        for (Camera cam : cameras) {
            camera.showMainFeature();
        }

        if (camera instanceof Camera) {
            System.out.println("카메라입니다.");
        }
        if (factoryCam instanceof FactoryCam) {
            ((FactoryCam) factoryCam).detectFire();    //형변환
        }
        if (speedCam instanceof SpeedCam){
            ((SpeedCam)speedCam).checkSpeed();
            ((SpeedCam)speedCam).recognizeLicensePlate();
        }

        Object[] objs = new Object[3];  //모든 클래스는 Object를 상속함
        objs[0] = new Camera();
        objs[1] = new FactoryCam();
        objs[2] = new SpeedCam();
    }
}
