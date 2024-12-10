// 올바른 배열
// https://www.acmicpc.net/problem/1337

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
    sort(v.begin(), v.end());
    int res = 5;
    for (int i = 0; i < n; i++) {
        int p = v[i];
        int idx = i + 1;
        int r = 4;
        for (int j = 1; j < 5; j++) {
            if (idx < n && v[idx] == p + j) {
                r--;
                idx++;
            }
        }
        res = min(res, r);
    }
    cout << res << '\n';
}

// 주어진 수열을 정렬해서 5개의 연속된 수를 만들 때 추가적으로 넣어야 하는 원소 개수 구하기