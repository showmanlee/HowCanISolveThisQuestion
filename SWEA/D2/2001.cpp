// 2001. 파리 퇴치
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PzOCKAigDFAUq

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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> board(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> board[i][j];
        int max = 0;
        for (int i = 0; i < n - m + 1; i++)
            for (int j = 0; j < n - m + 1; j++){
                int sum = 0;
                for (int p = i; p < i + m; p++)
                    for (int q = j; q < j + m; q++)
                        sum += board[p][q];
                if (sum > max)
                    max = sum;
            }
        cout << '#' << test_case << ' ' << max << '\n';
	}
	return 0;
}

// n*n 영역에 파리들이 있을 때, m*m 사이즈 파리채로 잡을 수 있는 파리의 최대 수는?
// 영역이 15까지라 O(n^4)로 풀어도 됨