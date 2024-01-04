// 선택의 기로
// https://www.acmicpc.net/problem/30970

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

bool compareA(pr a, pr b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first > b.first;
}

bool compareB(pr a, pr b) {
	if (a.second == b.second) {
		return a.first > b.first;
	}
	return a.second < b.second;
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
    sort(v.begin(), v.end(), compareA);
    cout << v[0].first << ' ' << v[0].second << ' ' << v[1].first << ' ' << v[1].second << '\n';
    sort(v.begin(), v.end(), compareB);
    cout << v[0].first << ' ' << v[0].second << ' ' << v[1].first << ' ' << v[1].second << '\n';
}

// 품질과 가격이 모두 다른 물건을 아래의 두 가지 방법으로 구입할 때 우선순위가 가장 높은 물건 2개 구하기
// 1. 높은 품질 우선, 같은 경우 낮은 가격 / 2. 낮은 가격 우선, 같은 경우 높은 품질 우선

// 두 조건에 맞춰 커스텀 compare 맞춰서 돌리기