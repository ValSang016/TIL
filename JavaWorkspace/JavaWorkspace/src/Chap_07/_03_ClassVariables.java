package Chap_07;

public class _03_ClassVariables {
    public static void main(String[] args) {
        BlackBox b1 = new BlackBox();
        b1.modelName = "까망이";
        System.out.println(b1.modelName);

        BlackBox b2 = new BlackBox();
        b2.modelName = "하양이";
        System.out.println(b2.modelName);

        //자동 신고기능
        System.out.println("개발 전");
        System.out.println(b1.modelName + " 자동신고기능 : " + b1.canAutoReport);
        System.out.println(b2.modelName + " 자동신고기능 : " + b2.canAutoReport);
        System.out.println("모든블랙박스 자동신고기능 : " + BlackBox.canAutoReport);

        BlackBox.canAutoReport = true;
        System.out.println("개발 후");
        System.out.println(b1.modelName + " 자동신고기능 : " + b1.canAutoReport);
        System.out.println(b2.modelName + " 자동신고기능 : " + b2.canAutoReport);
        System.out.println("모든블랙박스 자동신고기능 : " + BlackBox.canAutoReport);
    }
}
