import java.util.*;
public class Main {
    public static void main(String[] args) {
        Main T = new Main();
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        System.out.print(T.solution(str));
        str = sc.nextLine();
        System.out.print(T.solutionTwo(str));
    }

    public String solution(String str) {
        String answer = "";
        int m = Integer.MIN_VALUE;
        String[] s = str.split(" ");
        for (String x : s) {
            int len = x.length();
            if (len > m) {
                m = len;
                answer = x;
            }
        }
        return answer;
    }

    public String solutionTwo(String str) {
        String answer = "";
        int m = Integer.MIN_VALUE, pos;
        while ((pos=str.indexOf(' ')) != -1) {
            String tmp = str.substring(0, pos);
            int len = tmp.length();
            if (len > m) {
                m = len;
                answer =  tmp;
            }
        }
        return answer;
    }
}

