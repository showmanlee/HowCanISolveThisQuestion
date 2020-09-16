// 비밀지도(2018 카카오)
// https://programmers.co.kr/learn/courses/30/lessons/17681

class Solution {
    public String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = new String[n];
        int[] map = new int[n];
        
        for (int i = 0; i < n; i++){
            map[i] = arr1[i] | arr2[i];
            answer[i] = "";
            for (int j = n - 1; j >= 0; j--){
                if (map[i] / (int)Math.pow(2, j) % 2 == 1)
                    answer[i] += '#';
                else
                    answer[i] += ' ';
            }
        }
        return answer;
    }
}

// 정사각형의 맵, 공백 또는 벽(#)
// 2장의 지도가 모두 공백일 때만 실제 공백.
// 지도는 모두 이진수로 암호화되어 있음.
// 그러니까, 이진수 2개를 OR 연산해서 공백 위치를 구하라는 말.