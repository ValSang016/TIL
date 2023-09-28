package Chap_06;

import javax.swing.*;

public class Quiz_06_ {
    public static String getHiddenData(String data, int index){

        String plus = "";
        for (int i = index ; i < data.length(); i++) {
            plus += "*";
        }

        return data.substring(0,index).concat(plus);
    }
    public static void main(String[] args) {
        String name = "나코딩";
        String id = "990130-1234567";
        String phone = "010-1234-5678";

        System.out.println("이름 : " + getHiddenData(name, 1));
        System.out.println("주민번호 : " + getHiddenData(id, 8));
        System.out.println("전화번호 : " + getHiddenData(phone, 9));
    }
}
