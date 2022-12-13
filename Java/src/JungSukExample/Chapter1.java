package JungSukExample;

public class Chapter1 {
    public static void main(String[] args) {
        System.out.println("1" + "2"); // "12"
        System.out.println(true + ""); // "true"
        System.out.println('A' + 'B'); // 131
        // b, c, d, e,
        byte b = 10;
        char ch = 'A';
        int i = 100;
        long l =  1000L;

        b = (byte)i;
        ch = (char) b;
        short s = (short)ch;
        float f = l;
        i = ch;
    }
}
