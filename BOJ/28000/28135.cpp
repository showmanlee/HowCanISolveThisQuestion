// Since 1973
// https://www.acmicpc.net/problem/28135

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int p = i;
        while (p >= 50) {
            if (p % 100 == 50) {
                if (i != n) {
                    res++;
                }
                break;
            }
            p /= 10;
        }
        res++;
    }
    cout << res << '\n';
}

// 1부터 n까지 세는데 50이 들어간 수는 2번 셀 때, 총 센 횟수 구하기

// 50은 하나 더 세고, 그러면서 1부터 카운팅 진행
// 50이 들어간 수까지 셀 경우 하나 더 안 셈에 주의