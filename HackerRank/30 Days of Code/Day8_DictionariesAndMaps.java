// Day 8: Dictionaries and Maps
// https://www.hackerrank.com/challenges/30-dictionaries-and-maps/problem

import java.util.*;
import java.io.*;

class Solution{
    public static void main(String []argh){
        Map<String, Integer> m = new HashMap<>();
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for(int i = 0; i < n; i++){
            String name = in.next();
            int phone = in.nextInt();
            m.put(name, phone);
        }
        while(in.hasNext()){
            String s = in.next();
            if (m.get(s) == null)
                System.out.println("Not found");
            else
                System.out.println(s + "=" + m.get(s));
        }
        in.close();
    }
}
// n줄의 전화번호부와 *임의의 줄*의 검색이 주어졌을 때 결과 출력하기
// HashMap 사용 연습
// Java는 껍질 코드를 제공해줬음