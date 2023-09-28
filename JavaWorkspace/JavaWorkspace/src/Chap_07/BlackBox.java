package Chap_07;

public class BlackBox {
    String modelName;
    String resolution;
    int price;
    String color;
    int serialNumber;

    static int counter = 0; //시리얼번호 생성해주는 역 (++연산으로 1씩 커짐)
    //static 이 안붙은 위의 것들은 인스턴스로 각 객체마다 다른 값을 가지게 되지만
    //static 이 붙은 밑은 모든 객체들에 일률적으로 적용된은 값임(고유값)
    static boolean canAutoReport = false;

    BlackBox(){    //Constructor 생성
        System.out.println("기본생성자 호출");
        this.serialNumber = ++ counter;
        System.out.println("새로운 시리얼 넘버를 발급받았습니다.");
    }
    BlackBox(String modelName, String resolution, int price, String color){
        this(); //위의 BlackBox 메소드 불러오기

        System.out.println("사용자 정의 생성자 호출");
        this.modelName = modelName;
        this.resolution = resolution;
        this.price = price;
        this.color = color;
    }


    void autoReport(){
        if(canAutoReport) {
            System.out.println("충돌이 감지되어 자동으로 신고합니다.");
        } else {
            System.out.println("자동신고 기능이 지원되지 않습니다.");
        }
    }
    void insertMemoryCard(int capacity) {
        System.out.println("메모리 카드가 삽입되었습니다.");
        System.out.println("용량은 " + capacity + " GB입니다.");
    }

    int getVideoFileCount(int type) {
        if (type == 1){
            return 9;
        } else if (type == 2) {
            return 1;
        }
        return 10;
    }

        //showDataTime : 날짜정보 표시여부
        //showSpeed : 속도정보 표시여부
        //min : 영상 기록단위 (분)
    void record(boolean showDataTime, boolean showSpeed, int min) {
        System.out.println("녹화를 시작합니다.");
        if(showDataTime){
            System.out.println("영상에 날짜 정보가 표시됩니다.");
        }
        if(showSpeed){
            System.out.println("영상에 속도 정보가 표시됩니다.");
        }
        System.out.println("영상은 " + min + "분 단위로 녹화됩니다.");
    }

    void record(){
        record(true, true, 5); //파라미터가 없을 때 기본값 출력
    }


    static void callServiceCenter(){   //클래스 메소드입니다.
        System.out.println("서비스 센터(1588-0000)로 연결됩니다. ");
        //modelName = "test";  (불가능) //instance 변수는 static 변수에서 사용 불가능
        //canAutoReport = false;  (가능) static 변수는 static 변수에서 사용 가능
    }

    public void appendModelName(String modelName) {
        this.modelName += modelName;  //this를 붙이면 인스턴스변수의 modelName
        //변수명이 다르면 this 굳이
    }


    //GETTER(값가져오기) & SETTER(값설정하기)
    String getModelName(){
        return modelName;
    }
    void setModelName(String modelName){
        this.modelName = modelName;
    }
    String getResolution(){
        if(resolution == null || resolution.isEmpty()){
            return "판매자에게 문의하세요.";
        }
        return resolution;
    }
    void setResolution(){
        this.resolution = resolution;
    }
    int getPrice(){
        return price;
    }
    void setPrice(int price){
        if(price < 100000){
            this.price = 100000;
        } else {
            this.price = price;
        }
    }
    String getColor(){
        return color;
    }
    void setColor(String color){
        this.color = color;
    }
}
