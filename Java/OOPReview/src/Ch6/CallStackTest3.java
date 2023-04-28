package Ch6;

public class CallStackTest3 {
    public static void main(String[] args) {
        System.out.println("main(String[] args)가 시작되었음");
        firstMethod();
        System.out.println("main(String[] args)가 끝났음.");
    }

    static void firstMethod() {
        System.out.println("firstMethod()");
        secondMethod();
        System.out.println("firstMethod() end");
    }

    static void secondMethod() {
        System.out.println("secondMethod()");
        System.out.println("secondMethod() end");
    }
}
