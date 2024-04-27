// 최대 상승
// https://www.acmicpc.net/problem/25644

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int minn = 1987654321;
    int maxx = -1;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        if (minn > p) {
            minn = maxx = p;
        }
        maxx = max(maxx, p);
        res = max(res, maxx - minn);
    }
    cout << res << '\n';
}

// 주식의 등락이 주어질 때, 얻을 수 있는 최대 이득 구하기

// 낮은 점 기준, 가장 고점이 높은 경우를 찾아봅시다