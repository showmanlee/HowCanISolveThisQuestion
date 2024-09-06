// ФАКИР
// https://www.acmicpc.net/problem/31280

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    vector<int> v(4);
    int res = 0;
    for (int i = 0; i < 4; i++) {
        cin >> v[i];
        res += v[i];
    }
    sort(v.begin(), v.end());
    res -= v[0] - 1;
    cout << res << '\n';
}

// 주머니에 4가지 색깔의 쥐가 해당 갯수만큼 있을 때, 주머니의 쥐가 4가지 색상이란 것을 알게 되기까지 가장 많이 꺼내는 쥐의 수 구하기

// 네 수의 합 - 가장 작은 수 + 1