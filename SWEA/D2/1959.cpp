// 1959. 두 개의 숫자열
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PpoFaAS4DFAUq

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
        vector<int> a(n), b(m);
        for (int& i : a)
            cin >> i;
        for (int& j : b)
            cin >> j;
        long long res = 0;
        if (n < m){
            for (int k = 0; k <= m - n; k++){
                long long p = 0;
                for (int i = 0; i < n; i++)
                    p += a[i] * b[i + k];
                if (res < p)
                    res = p;
            }
        }
        else{
            for (int k = 0; k <= n - m; k++){
                long long p = 0;
                for (int i = 0; i < m; i++)
                    p += a[i + k] * b[i];
                if (res < p)
                    res = p;
            }
        }
        cout << '#' << test_case << ' ' << res << '\n';
	}
	return 0;
}

// 길이가 다른 두 개의 수열의 위치를 조정하여 마주보는 수들의 곱의 합을 최대로 만들기
// 받은 배열 길이에 따라 다르게 접근하기
// 배열 최대 길이 20에 값은 절댓값 10이므로 int로 커버가 안 될 수 있음에 주의
// 축약 for문에서 참조 자료형을 사용하면 배열에 값을 직접 넣을 수 있습니다