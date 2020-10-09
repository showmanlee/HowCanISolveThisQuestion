// 삼각 달팽이
// https://programmers.co.kr/learn/courses/30/lessons/68645

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> board(n, vector<int>(n));
    int dir = 0, dist = n, count = 0;
    int x = -1, y = 0;
    while (dist > 0){
        for (int i = 0; i < dist; i++){
            if (dir == 0)
                board[++x][y] = ++count;
            else if (dir == 1)
                board[x][++y] = ++count;
            else
                board[--x][--y] = ++count;
        }
        dist--;
        dir = (dir + 1) % 3;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            answer.push_back(board[i][j]);
    return answer;
}