// ИЗЛОЖЕНИЕ НА ПЧЕЛЕН МЕД
// https://www.acmicpc.net/problem/24387

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    vector<long long> a(3), b(3);
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 3; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end(), greater<long long>());
    sort(b.begin(), b.end(), greater<long long>());
    long long res = 0;
    for (int i = 0; i < 3; i++) {
        res += a[i] * b[i];
    }
    cout << res << '\n';
}

// 1kg당 가격이 다른 꿀 3종류와 한 종류의 꿀을 담을 수 있는 크기가 다른 통 3개가 주어질 때, 최대 가격 출력하기