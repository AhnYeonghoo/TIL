package Ch12;

public class RecodeExample {
    public static void main(String[] args) {
        Member2 m = new Member2("winter", "눈송이", 25);
        System.out.println(m.id());
        System.out.println(m.name());
        System.out.println(m.age());
        System.out.println(m.toString());
        System.out.println();
        System.out.println(m.hashCode());
        Member2 m2 = new Member2("winter", "눈송이", 25);
        System.out.println(m.equals(m2));
    }
}

