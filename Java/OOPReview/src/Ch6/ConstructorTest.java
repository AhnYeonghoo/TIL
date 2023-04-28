package Ch6;

public class ConstructorTest {
    public static void main(String[] args) {
        Data1  d1 = new Data1();

    }
}

class Data1 {
    int value;
}

class Data2 {
    int  value;
    Data2(int x) {
        value = x;
    }
}
