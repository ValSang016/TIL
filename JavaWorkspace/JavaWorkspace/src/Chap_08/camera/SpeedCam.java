package Chap_08.camera;

import Chap_08.detector.Detectable;
import Chap_08.reporter.Reportable;

public class SpeedCam extends Camera{
    public void setDetector(Detectable detector) {
        this.detector = detector;
    }

    public void setReporter(Reportable reporter) {
        this.reporter = reporter;
    }

    public Detectable detector;
    public Reportable reporter;

    @Override
    public void showMainFeature() {
        System.out.println("속도 측정, 번호 인식");
    }
//`    public void detect(){
//        System.out.println("사고를 감지합니다.");
//    }
//    public void report(){
//        System.out.println("사고를 신고합니다.");
//    }

    @Override
    public void detect() {
        detector.detect();
    }

    @Override
    public void report() {
        reporter.report();
    }
}
