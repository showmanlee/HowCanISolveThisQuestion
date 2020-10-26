// Java Stdin and Stdout II
// https://www.hackerrank.com/challenges/java-stdin-stdout/problem

import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int i = scan.nextInt();
        double d = scan.nextDouble();
        scan.nextLine();
        String s = scan.nextLine();

        System.out.println("String: " + s);
        System.out.println("Double: " + d);
        System.out.println("Int: " + i);
    }
}

// Scanner.nextInt(), nextDouble(), nextLine();
// nextInt() 또는 nextDouble() 사용 후 nextLine()을 사용하면 nextInt()에서 읽은 정수형 문자 다음 '\n'만 읽어 빈 줄이 입력되니 이에 대한 핸들링 필요