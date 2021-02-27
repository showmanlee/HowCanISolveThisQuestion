// 1940. 가랏! RC카!
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PjMgaALgDFAUq

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
        int v = 0, res = 0;
        for (int i = 0; i < n; i++){
            int c, s;
            cin >> c;
            if (c > 0){
                cin >> s;
                v += (c == 1 ? s : -s);
                if (v < 0)
                    v = 0;
            }
            res += v;
        }
        cout << '#' << test_case << ' ' << res << '\n';
	}
	return 0;
}

// RC카의 가속도 변화가 주어질 때, RC카가 이동한 총 거리는?
// 가속하면 속도++, 감속하면 속도--(음수 = 0), 매 초마다 속도 변화 후 속도만큼 이동
// 속도를 미분하면 가속도, 속도를 적분하면 위치 변화