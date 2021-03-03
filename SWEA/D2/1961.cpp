// 1961. 숫자 배열 회전
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5Pq-OKAVYDFAUq

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
        int n;
        cin >> n;
        vector<vector<int>> v(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> v[i][j];
        cout << '#' << test_case << '\n';
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++)
                cout << v[n-j-1][i];
            cout << ' ';
            for (int j = 0; j < n; j++)
                cout << v[n-i-1][n-j-1];
            cout << ' ';
            for (int j = 0; j < n; j++)
                cout << v[j][n-1-i];
            cout << '\n';
        }
	}
	return 0;
}

// n*n 배열을 시계방향으로 90, 180, 270도 회전한 꼴 출력하기
// 올바른 인덱스를 넣고 출력에 유의