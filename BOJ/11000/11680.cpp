// Dice Cup
// https://www.acmicpc.net/problem/11680

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

bool compare(pr a, pr b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first > b.first;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<pr> v(n + m + 1);
    for (int i = 1; i <= n + m; i++) {
        v[i].second = i;
    }
    int maxx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            v[i + j].first++;
            maxx = max(maxx, v[i + j].first);
        }
    }
    sort(v.begin(), v.end(), compare);
    for (pr p : v) {
        if (p.first == maxx) {
            cout << p.second << '\n';
        } else {
            break;
        }
    }
}

// 2개의 주사위를 굴릴 때 나올 확률이 가장 높은 합 구하기

// 직접 굴려보고 세서 출력해봅시다