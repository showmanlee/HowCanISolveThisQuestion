// 프린터
// https://programmers.co.kr/learn/courses/30/lessons/42587

using System;
using System.Collections.Generic;

public class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 0; 
        priorities[location] += 10;  // 내꺼 표시
        Queue<int> queue = new Queue<int>(priorities);
        while(queue.Count != 0){
            int n = queue.Dequeue();
            List<int> check = new List<int>(queue);
            bool fail = false;
            
            foreach(int i in check)
                if (n % 10 < i % 10){
                    fail = true;
                    break;
                }
            
            if (fail)
                queue.Enqueue(n);
            else{
                answer++;
                if (n / 10 == 1)
                    break;
            }
        }
        return answer;
    }
}

// 현재 대기하고 있는 문서들의 우선순위(1~9) = priorities
// 여기서 내가 기다리고 있는 문서 = location
// priorities에서 가장 앞에있는 걸 꺼내고
// 나머지 중 나보다 높은 게 있으면 나를 뒤에 다시 넣고
// 그렇지 않으면 나를 인쇄한다 - 큐