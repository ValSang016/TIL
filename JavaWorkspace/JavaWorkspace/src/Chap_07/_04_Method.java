package Chap_07;

public class _04_Method {
    public static void main(String[] args) {
        BlackBox b1 = new BlackBox();

        b1.autoReport(); //지원 안 됨
        BlackBox.canAutoReport = true;
        b1.autoReport(); //지원 됨

        b1.insertMemoryCard(256);

        //일반영상  : 1(type)
        //이벤트영상(충돌) : 2
        int fileCount = b1.getVideoFileCount(1);
        System.out.println("일반 영상 파일 수 : " + fileCount);

        fileCount = b1.getVideoFileCount(2);
        System.out.println("이벤트 영상 파일 수 : " + fileCount);
    }
}
