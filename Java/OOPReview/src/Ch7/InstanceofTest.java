package Ch7;

public class InstanceofTest {
    public static void main(String[] args) {
        FireEngine fe = new FireEngine();

        if (fe instanceof FireEngine) {
            System.out.println("This is a FireEngine");
        }
        if (fe instanceof Car) {
            System.out.println("car");
        }
        if (fe instanceof Object) {
            System.out.println("Object");
        }
        System.out.println(fe.getClass().getName());
    }
}
