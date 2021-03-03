// 1285. 아름이의 돌 던지기
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV18-stqI8oCFAZN

#include <iostream>

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
        int res = 100001, count = 0;
        for (int i = 0; i < n; i++){
            int p;
            cin >> p;
            if (p < 0)
                p *= -1;
            if (res > p){
                res = p;
                count = 1;
            }
            else if (res == p)
                count++;
        }
        cout << '#' << test_case << ' ' << res << ' ' << count << '\n';
	}
	return 0;
}

// 가장 원점에 가깝게 돌이 떨어진 위치의 절댓값과 해당 좌표에 떨어진 돌의 수 구하기
// 모두를 기억할 필요는 없음