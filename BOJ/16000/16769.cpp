// Mixing Milk
// https://www.acmicpc.net/problem/16769

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    
    vector<long long> cap(3), v(3);
    for (int i = 0; i < 3; i++) {
        cin >> cap[i] >> v[i];
    }
    for (int i = 0; i < 100; i++) {
        long long p = v[i % 3] + v[(i + 1) % 3];
        v[(i + 1) % 3] = min(p, cap[(i + 1) % 3]);
        v[i % 3] = max(0ll, p - v[(i + 1) % 3]);
    }
    for (int i = 0; i < 3; i++) {
        cout << v[i] << '\n';
    }
}

// 용량이 다른 3개의 컵에 우유가 담겨 있고, 이를 1번 컵에서 2번 컵에 가득 찰 때까지 붓기 -> 2번 컵에서 3번 컵 -> 3번 컵에서 1번 컵...으로 100번 부을 때 결과 출력하기