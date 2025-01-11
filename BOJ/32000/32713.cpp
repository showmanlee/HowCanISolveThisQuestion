// 숫자 POP
// https://www.acmicpc.net/problem/32713

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        int p = k;
        int l = 0;
        for (int j = i; j < n; j++) {
            if (v[j] == v[i]) {
                l++;
            } else {
                p--;
                if (p < 0) {
                    break;
                }
            }
        }
        res = max(l, res);
    }
    cout << res << '\n';
}

// 주어진 수열에서 최대 k개의 원소를 지워 만들 수 있는 연속된 원소의 최대 개수 구하기