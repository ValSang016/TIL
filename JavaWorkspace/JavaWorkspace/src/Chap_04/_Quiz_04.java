package Chap_04;

public class _Quiz_04 {
    public static void main(String[] args) {
        int hour = 10;
        int charge = 0;
        int max_char = 30000;
        boolean disabledCar = false;
        boolean smallCar = true;

        charge = hour * 4000;
        if(charge > max_char){
                charge = max_char;

        }
        if(disabledCar || smallCar){
            charge /= 2;
        }
        System.out.println("최종 주차요금 : " + charge);
    }
}
