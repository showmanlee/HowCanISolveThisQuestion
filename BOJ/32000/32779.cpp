// 가희와 전기 요금 1
// https://www.acmicpc.net/problem/32779

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        double n, m;
        cin >> n >> m;
        int res = n * m / 1000.0 * 105.6 / 60.0;
        cout << res << '\n';
    }
}

// 전기 요금이 105.6원/kWh인 집에서 nW를 m분간 사용한 요금 출력하기