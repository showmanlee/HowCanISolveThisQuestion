// 정렬된 연속한 부분수열의 개수
// https://www.acmicpc.net/problem/31395

#include <iostream>
#include <string>
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
    long long res = 0;
    long long len = 1;
    for (int i = 1; i < n; i++) {
        if (v[i - 1] < v[i]) {
            len++;
        } else {
            res += (len + 1) * len / 2;
            len = 1;
        }
    }
    res += (len + 1) * len / 2;
    cout << res << '\n';
}

// 주어진 수열에서 모든 원소가 오름차순인 부분수열의 개수 구하기