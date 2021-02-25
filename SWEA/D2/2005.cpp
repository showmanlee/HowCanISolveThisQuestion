// 2005. 파스칼의 삼각형
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5P0-h6Ak4DFAUq

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    vector<vector<int>> v(10, vector<int>(10));
    for (int i = 0; i < 10; i++){
        v[i][0] = 1;
        v[i][i] = 1;
        for (int j = 1; j <= i - 1; j++)
            v[i][j] = v[i-1][j-1] + v[i-1][j];
    }
    
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n;
        cin >> n;
        cout << '#' << test_case << '\n';
        for (int i = 0; i < n; i++){
            for (int j = 0; j <= i; j++)
                cout << v[i][j] << ' ';
            cout << '\n';
        }
	}
	return 0;
}

// 파스칼의 삼각형 그리기
// 크기가 10까지니까 2차원으로 그릴 수 있음 - 그냥 미리 만들어두자
// 하지만 크기가 커져서 2차원 배열에 담을 수 없다면? - 배열을 2개 만들어서 이전 배열 현재 배열을 써먹어야 할까?
