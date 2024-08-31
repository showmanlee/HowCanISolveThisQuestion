// Rust Study
// https://www.acmicpc.net/problem/30033

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= b[i]) {
            res++;
        }
    }
    cout << res << '\n';
}

// 길이가 같은 두 배열에서 앞 배열보다 뒷 배열 값이 더 작은 작거나 같은 경우의 수 구하기