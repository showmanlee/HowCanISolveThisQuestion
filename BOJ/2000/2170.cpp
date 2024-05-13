// 선 긋기
// https://www.acmicpc.net/problem/2170

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

bool compare(pr a, pr b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pr> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), compare);
    int l = -1987654321, r = -1987654321;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].first <= r) {
            r = max(r, v[i].second);
        } else {
            res += r - l;
            l = v[i].first;
            r = v[i].second;
        }
    }
    res += r - l;
    cout << res << '\n';
}

// 1차원 공간의 특정 구간에 선을 그을 때, 선이 그어진 총 길이 구하기

// 우선 모든 선들을 시작 지점에 맞춰 정렬한다
// 그리고 선들을 돌면서 출발점과 도착점을 보는데, 현재 도착점이 출발점 안쪽이면 선을 그대로 그어주고, 바깥쪽이면 새로 그려준다