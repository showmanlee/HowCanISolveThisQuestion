// 예산
// https://programmers.co.kr/learn/courses/30/lessons/12982

class Solution {
    public int solution(int[] d, int budget) {
        int answer = 0;
        for(int i = 0; i < d.length; i++)
            for (int j = i; j < d.length; j++)
                if (d[i] < d[j]){
                    int p = d[i];
                    d[i] = d[j];
                    d[j] = p;
                }
        
        for(int i = 0; i < d.length; i++){
            int sum = 0;
            for (int j = i; j < d.length; j++){
                sum += d[j];
            }
            if (budget >= sum)
                return d.length - i;
        }
        
        return answer;
    }
}

// d는 부서들이 요청한 금액들
// budget은 가지고 있는 예산