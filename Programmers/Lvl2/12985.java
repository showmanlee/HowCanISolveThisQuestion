// 예상 대진표
// https://programmers.co.kr/learn/courses/30/lessons/12985
import java.util.*;

class Solution
{
    public int solution(int n, int a, int b)
    {
        int answer = 0;
        int p = 0;
        while (n != 1){
            n /= 2;
            p++;
        }
        
        for(int i = 0; i < p; i++){
            answer++;
            if (Math.abs(a - b) == 1 && Math.abs(a / 2 - b / 2) == 1)
                return answer;
            a = a % 2 == 0 ? a / 2 : a / 2 + 1;
            b = b % 2 == 0 ? b / 2 : b / 2 + 1;
        }
        
        return answer;
    }
}

// 처음 대진에서 a번 참가자와 b번 참가자가 계속 이길 때, 몇 라운드에서 만나게 되는가?
// n은 참가자수(2의 승수로만 제공)