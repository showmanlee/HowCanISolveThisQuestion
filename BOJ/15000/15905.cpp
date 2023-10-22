// 스텔라(STELLA)가 치킨을 선물했어요
// https://www.acmicpc.net/problem/15905

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

    int n;
    cin >> n;
    vector<pr> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), compare);
    int res = 0;
    for (int i = 5; i < n; i++) {
        if (v[4].first == v[i].first) {
            res++;
        }
    }
    cout << res << '\n';
}

// 맞힌 문제 내림차순 -> 페널티 오름차순으로 순위가 결정될 때, 5등과 맞힌 문제 수는 같으면서 페널티를 더 받은 사람 수 출력하기

// 커스텀 정렬로 정렬한 뒤 5등과 그 이후 등수에 대해 5등과 같은 문제를 맞힌 사람 수를 구한다