package Ch12;

import java.util.*;

public class VectorEx1 {
    public static void main(String[] args) {
        Vector v = new Vector(5);
        v.add("1");
        v.add("2");
        v.add("3");
        print(v);

        v.trimToSize();
        System.out.println("=== after trimToSize() ===");
        print(v);

        v.ensureCapacity(6);
        System.out.println(" === after ensureCapacity(6) === ");
        print(v);

        v.setSize(7);
        print(v);

        v.clear();
        print(v);

    }

    static void print(Vector v) {
        System.out.println(v);
        System.out.println("size: " + v.size());
        System.out.println("capacity: " + v.capacity());
    }
}
