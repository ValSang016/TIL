package Chap_06;

public class _03_Return {
    //호텔 전화번호
    public static String getPhoneNumber(){
        String phoneNumber = "010-1234-5678";
        return phoneNumber;
    }

    public static void main(String[] args) {
        System.out.println("호텔전화번호 : " + getPhoneNumber());
    }
}
