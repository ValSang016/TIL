package Chap_07;

public class _Quiz_07 {
    public static void main(String[] args) {
        hamBurger[] hm = new hamBurger[3];
        hm[0] = new hamBurger();
        hm[1] = new cheeseBurger();
        hm[2] = new shrimpBurger();

        System.out.println("주문하신 메뉴를 만듭니다.");
        System.out.println("-----------------");
        for (int i = 0; i < 3; i++) {
            hm[i].cook();
            System.out.println("-----------------");
        }
        System.out.println("메뉴 준비가 완료되었습니다.");

    }

}
class hamBurger {
    public String name;
    protected hamBurger(String name) {
        this.name = name;
    }
    public hamBurger() {
        this("햄버거");
    }
    public void cook() {
        System.out.println(this.name + "를 만듭니다.");
        for (material m : material.values()) {
            System.out.println("+" + m.name());
        }
    }

}
class cheeseBurger extends hamBurger {
    public cheeseBurger() {
        super("치즈버거");
    }
    public void cook(){
        super.cook();
        System.out.println("+치즈");
    }
}
class shrimpBurger extends hamBurger {
    public shrimpBurger() {
        super("새우버거");
    }
    public void cook(){
        super.cook();
        System.out.println("+새우");
    }
}

enum material {
    양상추, 패티, 피클;
}
