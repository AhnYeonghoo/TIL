package Ch6;

public class ReferenceParamEx {
    public static void main(String[] args) {
        Data d = new Data();
        d.x = 10;
        System.out.println(d.x);
        change(d);
        System.out.println(d.x);
    }

    static void change(Data d) {
        d.x = 1000;
        System.out.println("change() : x " + d.x);
    }
}