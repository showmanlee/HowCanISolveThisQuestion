// 유치원생 파댕이 돌보기
// https://www.acmicpc.net/problem/30979

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int t, n;
    cin >> t >> n;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        res += p;
    }
    cout << "Padaeng_i " << (res >= t ? "Happy" : "Cry") << '\n';
}

// 주어진 정수 n개의 합이 t 이상인지 확인하기

// 계산 계산