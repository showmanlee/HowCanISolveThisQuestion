// 노브 돌리기
// https://www.acmicpc.net/problem/23756

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int d;
    cin >> d;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        res += min(abs(p - d), min(abs(p + 360 - d), abs(p - 360 - d)));
        d = p;
    }
    cout << res << '\n';
}

// 노브를 돌려야 하는 각도 값이 주어질 때, 최소로 이동하는 각도의 합 구하기

// 최소로 이동하는 값을 구해본다