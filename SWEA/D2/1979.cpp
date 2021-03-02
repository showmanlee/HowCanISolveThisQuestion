// 1979. 어디에 단어가 들어갈 수 있을까
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PuPq6AaQDFAUq

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
        int n, k;
        cin >> n >> k;
        vector<vector<int>> board(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> board[i][j];
        int res = 0;
        for (int i = 0; i < n; i++){
            int countv = 0, counth = 0;
            for (int j = 0; j < n; j++){
                if (board[i][j] == 1){
                    counth++;
                    if (counth == k)
                        res++;
                    else if (counth == k + 1)
                        res--;
                }
                else
                    counth = 0;
                if (board[j][i] == 1){
                    countv++;
                    if (countv == k)
                        res++;
                    else if (countv == k + 1)
                        res--;
                }
                else
                    countv = 0;
            }
        }
        cout << '#' << test_case << ' ' << res << '\n';
	}
	return 0;
}

// n*n 보드에 k 글자 단어가 몇 개 들어갈 수 있는지 확인하기
// 정확히 k글자가 연속으로 들어갈 공간 찾기
// 칸을 하나씩 순회하여 연속으로 k가 빈 순간 카운트 올리기, 그러나 이를 넘어선 경우 바로 내리기