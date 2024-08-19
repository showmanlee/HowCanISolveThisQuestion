// Number Pairs 
// https://www.acmicpc.net/problem/15234

#include <iostream>
#include <vector>
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
    sort(v.begin(), v.end());
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] + v[j] == k) {
                res++;
            }
        }
    }
    cout << res << '\n';
}

// 주어진 수로 만들 수 있는 순서쌍 중 두 수의 합이 k인 경우의 수 출력하기