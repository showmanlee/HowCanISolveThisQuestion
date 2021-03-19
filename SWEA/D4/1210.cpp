// 1210. [S/W 문제해결 기본] 2일차 - Ladder1
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14ABYKADACFAYh

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
	int T;
    for (T = 1; T <= 10; T++){
        cin >> test_case;
        vector<vector<int>> board(100, vector<int>(100));
        int x = -1;
        for (int i = 0; i < 100; i++){
            for (int j = 0; j < 100; j++){
                cin >> board[i][j];
                if (board[i][j] == 2)
                    x = j;
            }
        }
        for (int y = 99; y >= 0; y--){
            int dir = 0;
            if (x + 1 < 100 && board[y][x + 1] == 1)
                dir = 1;
            else if (x - 1 > 0 && board[y][x - 1] == 1)
                dir = -1;
            if (dir != 0){
                while(board[y][x] == 1)
                    x += dir;
                x -= dir;
            }
        }
        cout << '#' << test_case << ' ' << x << '\n';
    }
	return 0;
}

// 100*100 보드에 사다리 게임 판이 그려지고 도착지 중 하나가 표시될 때, 그 도착지에 대응하는 출발지의 좌표는?
// y좌표를 for타고 쭉 올라가다가 옆길이 있으면 while로 움직이기