// 크레인 인형뽑기 게임(2019 카카오 겨울 인턴십)
// https://programmers.co.kr/learn/courses/30/lessons/64061

import java.util.*;

class Solution {
    public int solution(int[][] board, int[] moves) {
        int answer = 0;
        Stack<Integer> bucket = new Stack<Integer>();
        int n = board.length;
        
        for (int i = 0; i < moves.length; i++){
            for (int j = 0; j < n; j++){
                if (board[j][moves[i] - 1] != 0){
                    if (!bucket.empty() && bucket.peek() == board[j][moves[i] - 1]){
                        bucket.pop();
                        answer += 2;
                    }
                    else
                        bucket.push(board[j][moves[i] - 1]);
                    board[j][moves[i] - 1] = 0;
                    break;
                }
            }
        }
        return answer;
    }
}

// board은 중력의 영향을 받는 정사각형 형태의 바구니. 모든 인형은 한칸을 차지한다.
// moves는 인형을 집는 순서(1~폭), 집으면 집히는 대로 올라가지만 해당 칸에 인형이 없으면 안 집힌다.
// '바구니'는 인형이 하나씩 쌓이는 스택(용량은 무한함), 같은 인형 2개가 만나면 사라짐.
// 목표: 사라진 인형의 개수는?