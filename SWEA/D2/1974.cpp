// 1974. 스도쿠 검증
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5Psz16AYEDFAUq

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        vector<vector<int>> board(9, vector<int>(9));
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                cin >> board[i][j];
        int res = 1;
        for (int i = 0; i < 9; i++){
            int v = 0, h = 0;
            for (int j = 0; j < 9; j++){
                v += board[i][j];
                h += board[j][i];
            }
            if (v != 45 || h != 45)
                res = 0;
        }
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++){
                int s = 0;
                for (int k = i * 3; k < (i + 1) * 3; k++)
                     for (int l = j * 3; l < (j + 1) * 3; l++)
                         s += board[k][l];
                if (s != 45)
                    res = 0;
            }
        cout << '#' << test_case << ' ' << res << '\n';
	}
	return 0;
}

// 스도쿠가 제대로 만들어졌는지 검증하기
// 만드는건 어렵지만 맞추는건 쉽다