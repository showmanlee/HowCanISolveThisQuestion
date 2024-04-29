// Scavenger Hunt
// https://www.acmicpc.net/problem/6030

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> a, b;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            a.push_back(i);
        }
    }
    for (int i = 1; i <= m; i++) {
        if (m % i == 0) {
            b.push_back(i);
        }
    }
    for (int i : a) {
        for (int j : b) {
            cout << i << ' ' << j << '\n';
        }
    }
}

// n과 m 각각의 약수로 만들 수 있는 쌍 모두 출력하기