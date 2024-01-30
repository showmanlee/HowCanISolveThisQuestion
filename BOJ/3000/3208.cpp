// gus
// https://www.acmicpc.net/problem/3208

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int res = 0;
    while (n != 0 && m != 0) {
        n--;
        if (n == 0) {
            break;
        }
        res++;
        m--;
        if (m == 0) {
            break;
        }
        res++;
    }
    cout << res << '\n';
}

// n*m 모양의 초콜릿을 좌측 상단부터 시계방향 나선형으로 먹을 때, 다 먹을 때 90도 회전한 횟수 구하기

// 직접 돌려봅시다 - 행/열 교대로 한 줄씩 없애가면서 확인