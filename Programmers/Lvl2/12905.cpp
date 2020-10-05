// 가장 큰 정사각형 찾기
// https://programmers.co.kr/learn/courses/30/lessons/12905

#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    if (board.size() == 1 || board[0].size() == 1)
        return 1;
    
    for (int i = 1; i < board.size(); i++){
        for (int j = 1; j < board[0].size(); j++){
            if (board[i][j] > 0){
                board[i][j] = min(board[i-1][j-1], min(board[i][j-1], board[i-1][j])) + 1;
                if (board[i][j] > answer)
                   answer = board[i][j];
            }
        }
    }

    return answer * answer;
}

// 내가 0이 아닐 때 내 좌상단에 있는 숫자들 중 최소치 + 1가 내 숫자가 되고 그 숫자와 정답값 중 큰 게 답
// 단 행/열 수가 1일 수도 있으니 예외처리 해주기