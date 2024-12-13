// Are They All Integers?
// https://www.acmicpc.net/problem/18141

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
    bool res = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (i == j || i == k || j == k) {
                    continue;
                }
                if ((v[i] - v[j]) % v[k] != 0) {
                    res = false;
                    break;
                }
            }
            if (!res) {
                break;
            }
        }
        if (!res) {
            break;
        }
    }
    cout << (res ? "yes" : "no") << '\n';
}

// 주어진 수열에서 서로 다른 3개의 수를 집어서 (v[i] - v[j]) / v[k] 식을 만들 때, 해당 식이 언제나 나누어떨어지는지 확인하기