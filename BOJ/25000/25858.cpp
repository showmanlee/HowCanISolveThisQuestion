// Divide the Cash
// https://www.acmicpc.net/problem/25858

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    int d = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        d += v[i];
    }
    for (int i = 0; i < n; i++) {
        cout << (m / d * v[i]) << '\n';
    }
}

// 주어진 돈을 비율에 따라 가른 결과 출력하기