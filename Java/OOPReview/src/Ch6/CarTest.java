package Ch6;

public class CarTest {
    public static void main(String[] args) {
        Car c1 = new Car();
        c1.color = "white";
        c1.gearType = "auto";
        c1.door = 4;
        Car c2 = new Car("white", "auto", 4);
        System.out.println(c1.toString());
        System.out.println(c2.toString());
    }
}

class Car {
    String color;
    String gearType;
    int door;

    Car() {}
    Car(String color) {
        this(color, "auto", 4);
    }
    Car(Car c) {
        color = c.color;
        gearType = c.gearType;
        door = c.door;
    }
    Car(String color, String gearType, int door) {
        this.color = color;
        this.gearType = gearType;
        this.door = door;
    }
}
