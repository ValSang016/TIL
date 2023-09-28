package Chap_08;

import Chap_08.camera.SpeedCam;
import Chap_08.detector.AccidentDetector;
import Chap_08.detector.Detectable;
import Chap_08.reporter.VideoReporter;

public class _Quiz_08 {
    public static void main(String[] args) {
        SpeedCam speedCam = new SpeedCam();
        speedCam.setDetector(new AccidentDetector());
        speedCam.setReporter(new VideoReporter());
        speedCam.report();
        speedCam.detect();

    }
}
