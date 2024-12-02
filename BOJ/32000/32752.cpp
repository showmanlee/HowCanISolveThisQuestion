// 수열이에요?
// https://www.acmicpc.net/problem/32752

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, l, r;
    cin >> n >> l >> r;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    l--;
    r--;
    sort(v.begin() + l, v.begin() + r + 1);
    int res = 1;
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            res = 0;
            break;
        }
    }
    cout << res << '\n';
}

// 주어진 수열의 l~r번 원소의 순서를 바꾸어 수열 전체를 비내림차순으로 만들 수 있는지 구하기