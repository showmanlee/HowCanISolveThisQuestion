// gahui and sousenkyo 2
// https://www.acmicpc.net/problem/30792

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int p = v[0];
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < n; i++) {
        if (v[i] == p) {
            cout << (i + 1) << '\n';
            break;
        }
    }
}

// n명의 득표 수가 주어질 때, 주어진 득표수의 순위 구하기