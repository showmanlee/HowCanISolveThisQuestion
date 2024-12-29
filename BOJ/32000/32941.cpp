// 왜 맘대로 예약하냐고
// https://www.acmicpc.net/problem/32941

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int t, x;
    cin >> t >> x;
    vector<int> cnt(t + 1);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int p;
            cin >> p;
            cnt[p]++;
        }
    }
    cout << (cnt[x] == n ? "YES" : "NO") << '\n';
}

// 사람들이 들어갈 수 있는 교시들이 주어질 떄, x교시에 모두 참석할 수 있는지 구하기