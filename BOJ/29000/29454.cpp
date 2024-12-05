// Выражение
// https://www.acmicpc.net/problem/29454

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    for (int i = 0; i < n; i++) {
        int p = sum - v[i];
        if (p == v[i]) {
            cout << (i + 1) << '\n';
            break;
        }
    }
}

// 주어진 수열 원소 중 자신과 나머지 수의 합이 같은 수의 위치 구하기