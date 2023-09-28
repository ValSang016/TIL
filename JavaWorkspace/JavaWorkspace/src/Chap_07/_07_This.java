package Chap_07;

public class _07_This {
    public static void main(String[] args) {
        //현 객체를 가르킴
        BlackBox b1 = new BlackBox();
        b1.modelName = "까망이";  //까망이(최신형)
        b1.appendModelName("(최신형)");   // 선택하고 option + enter => 자동완성 선택
        //선택하고 option + space => 코드 미리보기
        System.out.println(b1.modelName);
    }
}
