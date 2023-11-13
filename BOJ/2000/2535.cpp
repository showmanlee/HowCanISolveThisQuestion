// 아시아 정보올림피아드
// https://www.acmicpc.net/problem/2535

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<pr, int> prr;

bool compare(prr a, prr b) {
	return a.second > b.second;
}

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<prr> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first.first >> v[i].first.second >> v[i].second;
    }
    sort(v.begin(), v.end(), compare);
    int rank = 0;
    vector<int> cnt(1001);
    for (int i = 0; i < n; i++) {
        if (cnt[v[i].first.first] < 2) {
            cout << v[i].first.first << ' ' << v[i].first.second << '\n';
            cnt[v[i].first.first]++;
            rank++;
        }
        if (rank == 3) {
            break;
        }
    }
}

// 한 나라가 동시에 3개의 메달을 딸 수 없을 때, 참가자들의 점수에 따른 금/은/동메달 수상자 구하기

// 정렬 후 카운팅