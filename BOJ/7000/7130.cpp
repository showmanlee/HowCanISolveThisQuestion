// Milk and Honey
// https://www.acmicpc.net/problem/7130

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        res += max(a * x, b * y);
    }
    cout << res << '\n';
}

// a와 b의 개당 행복도가 주어지고, 각 칸에서 a나 b 중 한 종류만 모두 사용하여 얻을 수 있는 최대 행복도 구하기