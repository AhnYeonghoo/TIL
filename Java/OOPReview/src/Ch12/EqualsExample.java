package Ch12;

public class EqualsExample {
    public static void main(String[] args) {
        Member obj1 = new Member("blud");
        Member obj2 = new Member("blud");
        Member obj3 = new Member("red");

        if (obj1.equals(obj2))
            System.out.println("obj1과 obj2는 동일합니다");

        if (obj1.equals(obj3)) {
            System.out.println("obj1과 obj2는 동일합니다.");
        } else {
            System.out.println("노동일");
        }
    }
}

class Member {
    private String id;

    public Member(String id) {
        this.id = id;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Member target) {
            if (id.equals(target.id)) return true;
        }

        return false;
    }
}