// Missing Numbers
// https://www.acmicpc.net/problem/17588

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<bool> v(201);
    int maxx = 0;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        v[p] = true;
        if (i == n - 1) {
            maxx = p;
        }
    }
    bool good = true;
    for (int i = 1; i <= maxx; i++) {
        if (!v[i]) {
            cout << i << '\n';
            good = false;
        }
    }
    if (good) {
        cout << "good job" << '\n';
    }
}

// 수열이 주어질 때, 1부터 n까지 세는데 빠진 수들 구하기