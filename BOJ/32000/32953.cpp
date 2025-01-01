// 회상
// https://www.acmicpc.net/problem/32953

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    map<int, int> cnt;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        for (int j = 0; j < p; j++) {
            int t;
            cin >> t;
            cnt[t]++;
            if (cnt[t] == m) {
                res++;
            }
        }
    }
    cout << res << '\n';
}

// 수업을 동시에 m개 이상 수강한 사람 횟수 구하기