package Chap_03;

public class _04_EscapeSequence {
    public static void main(String[] args) {
        // 특수문자, 이스케이프 문자( Escape Sequence, Escape Character, Special Character)

        // \n 줄바꿈
        System.out.println("자바가\n너무\n재밌어요.");

        // \t tab
        System.out.println("해물파전\t9,000원");
        System.out.println("김치전\t8,000원");

        // \\ 역슬래시 하나
        System.out.println("c:\\Program Files\\JavaWorkpsace");

        // \" \' 따옴표
        System.out.println("단비가 \"냐옹\"이라고 했어요.");
        System.out.println("너가 '뭘봐?'라는 표정을 지음");
        System.out.println("너가 \'뭘봐?\'라는 표정을 지음");

        char a = '\'';
        System.out.println(a);

    }
}
