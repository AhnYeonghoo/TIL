import java.util.*;

public class ChangeChar {
    public String solution(String str) {
        String answer = "";
        for (char x : str.toCharArray()) {
            if (Character.isLowerCase(x)) answer += Character.toUpperCase(x);
            else answer += Character.toLowerCase(x);
        }
        return answer;
    }

    public static void main(String[] args) {
        ChangeChar C = new ChangeChar();
        Scanner scan = new Scanner(System.in);
        String str = scan.next();
        System.out.print(C.solution(str));
    }
}
