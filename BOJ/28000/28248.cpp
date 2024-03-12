// Deliv-e-droid
// https://www.acmicpc.net/problem/28248

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int res = n * 50 - m * 10;
    if (n > m) {
        res += 500;
    }
    cout << res << '\n';
}

// 배달한 물건 하나당 50점 득점, 실패한 물건 하나당 10점 득점, 배달한 물건이 실패한 물건보다 더 많을 경우 보너트 500점 득점할 때, 총 점수 구하기

// 앞서 말한 대로 계산하기