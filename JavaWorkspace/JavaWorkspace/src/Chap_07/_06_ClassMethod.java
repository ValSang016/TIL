package Chap_07;

public class _06_ClassMethod {
    public static void main(String[] args) {
        BlackBox b1 = new BlackBox();
        b1.callServiceCenter();

        BlackBox b2 = new BlackBox();
        b2.callServiceCenter();

        BlackBox.callServiceCenter();

    }
    //일반 메소드는 객체마다 다른 작동을 할 수 있지만
    //static이 붙은 클래스 메소드는 클래스변수와 마찬가지로 변하지 않는다.
}
