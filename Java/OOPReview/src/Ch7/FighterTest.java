package Ch7;

public class FighterTest {
    public static void main(String[] args) {

        Fighter f = new Fighter();

        if (f instanceof Unit) {
            System.out.println("f는 Unit의 자손입니다.");
        }

        if (f instanceof Fightable) {
            System.out.println("f는 Fightble을 구현했습니다.");
        }

        if (f instanceof Movable) {
            System.out.println("f는 Movable을 구현했습니다");
        }

        if (f instanceof Attackable) {
            System.out.println("f는 Attackable을 구현했습니다");
        }

        if (f instanceof Object) {
            System.out.println("f는 Object의 자손입니다.");
        }
    }
}

class Fighter extends Unit implements Fightable {
    public void move(int x, int y) {
        System.out.println("move");
    }

    public void attack(Unit u) {
        System.out.println("Attack");
    }
}

class Unit {
    int currentHp;
    int x, y;
}

interface Movable {
    void move(int x, int y);
}

interface Attackable {
    void attack(Unit u);
}

interface Fightable extends Movable, Attackable {

}
