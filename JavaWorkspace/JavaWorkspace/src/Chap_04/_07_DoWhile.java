package Chap_04;

public class _07_DoWhile {
    public static void main(String[] args) {
        //반복문 DoWhile
        int distance = 25; //25m
        int move = 0;
        int height = 23;  //2m
        do{
            System.out.println("이동을 계속합니다.");
            System.out.println("현재 이동거리 : "+move);
            move += 3;
        } while (move + height < distance);
        System.out.println("도착하였습니다.");

        System.out.println("22");

        //비교  - 아예 출력하지 않음
        while (move + height < distance){
            System.out.println("이동을 계속합니다.");
            System.out.println("현재 이동거리 : "+move);
            move += 3;
        }

}
}
