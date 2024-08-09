// 도전 숫자왕
// https://www.acmicpc.net/problem/23057

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n);
    int res = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        res += v[i];
    }
    map<int, bool> visit;
    for (int i = 1; i < (1 << n); i++) {
        int p = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                p += v[j];
            }
        }
        if (!visit[p]) {
            visit[p] = true;
            res--;
        }
    }
    cout << res << '\n';
}

// n개의 숫자카드 중 모든 카드의 합 이하의 수 중 1개 이상을 고른 합으로 만들 수 없는 수의 개수 구하기

// map으로 중복 체크하면서 합에서 하나씩 빼준다