// 1206. [S/W 문제해결 기본] 1일차 - View
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV134DPqAA8CFAYh

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	for(test_case = 1; test_case <= 10; ++test_case)
	{
        int n;
        cin >> n;
        vector<int> bd(n);
        for (int i = 0; i < n; i++)
            cin >> bd[i];
        
        int res = 0;
        for (int i = 2; i < n - 2; i++){
            int count = 0;
            for (int j = bd[i]; j >= 1; j--){
                if (bd[i-2] >= j || bd[i-1] >= j || bd[i+2] >= j || bd[i+1] >= j)
                    break;
                count++;
            }
            res += count;
        }
        cout << '#' << test_case << ' ' << res << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

// 양옆으로 두 칸 이상 조망권이 확보되는 층 수는?
// 한 층씩 내려가면서 두 칸 뚫려있는지 확인하기
// 테케는 무조건 10개, 처음/마지막 2칸은 무조건 0으로 입력됨에 주의