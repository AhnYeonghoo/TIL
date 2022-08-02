import java.util.*;

class FindChar {
    public int solution(String str, char t) {
        int answer = 0;
        str = str.toUpperCase(); // 모두 대문자로
        t = Character.toUpperCase(t); // 대문자로
        for (char x : str.toCharArray()) { //
            if (x == t) answer++; // 문자열을 문자 배열로 변경 후 비교 연산
        }
        return answer;
    }

    public static void main(String[] args) {
        FindChar fc = new FindChar();
        Scanner scan = new Scanner(System.in);
        String str = scan.next();
        char c = scan.next().charAt(0);
        System.out.print(fc.solution(str, c));

    }
}