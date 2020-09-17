// 뉴스 클러스터링(2018 카카오)
// https://programmers.co.kr/learn/courses/30/lessons/17677

import java.util.*;

class Solution {
    public int solution(String str1, String str2) {
        int answer = 0;
        List<String> token1 = new ArrayList<String>();
        List<String> token2 = new ArrayList<String>();
        List<String> union = new ArrayList<String>(); 
        List<String> inter = new ArrayList<String>(); 
        for (int i = 0; i < str1.length() - 1; i++){
            String s = str1.substring(i, i + 2).toLowerCase();
            if (Character.isLowerCase(s.charAt(0)) && Character.isLowerCase(s.charAt(1)))
                token1.add(s);
        }
        for (int i = 0; i < str2.length() - 1; i++){
            String s = str2.substring(i, i + 2).toLowerCase();
            if (Character.isLowerCase(s.charAt(0)) && Character.isLowerCase(s.charAt(1)))
                token2.add(s);
        }
        Collections.sort(token1);
        Collections.sort(token2);
        for(int i = 0; i < token1.size(); i++){
            for (int j = 0; j < token2.size(); j++){
                if (token1.get(i).equals(token2.get(j))){
                    union.add(token1.get(i));
                    inter.add(token1.get(i));
                    token1.remove(i);
                    token2.remove(j);
                    i--;
                    break;
                }
            }
        }
        for (int i = 0; i < token1.size(); i++)
            union.add(token1.get(i));
        for (int i = 0; i < token2.size(); i++)
            union.add(token2.get(i)); 
        
        if (union.size() == 0)
            answer = 65536;
        else{
            double d = (double)inter.size() / union.size() * 65536;
            answer = (int)d;
        }
        return answer;
    }
}
    
// 자카드 유사도: 교집합 / 합집합 (중복 원소도 포함)
// 여기서는 65536을 곱한 후 소수점을 버린다. 합집합이 0이라면(tc4) 결과값을 1 = 65536으로 정의
// 들어오는 문장을 2개씩 쪼갠다(대소문자 구분X, 알파벳 아닌게 있으면 버림)