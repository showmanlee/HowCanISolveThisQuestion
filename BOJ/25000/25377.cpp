// 빵
// https://www.acmicpc.net/problem/25377

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int res = 987654321;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a <= b) {
            res = min(res, b);
        }
    }
    if (res == 987654321) {
        res = -1;
    }
    cout << res << '\n';
}

// 빵집까지 가는 시간과 해당 빵집에서 빵이 나오는 시간이 주어질 때, 갓구운 빵을 바로 살 수 있는 최소 시간 구하기

// a <= b일 때, b의 최솟값 구하기