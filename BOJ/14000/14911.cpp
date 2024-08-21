// 궁합 쌍 찾기
// https://www.acmicpc.net/problem/14911

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int p;
    vector<int> v;
    while (cin >> p) {
        v.push_back(p);
    }
    int n = v.back();
    v.pop_back();
    sort(v.begin(), v.end());
    int cnt = 0;
    map<pr, int> visit;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[i] + v[j] == n && !visit[{v[i], v[j]}]) {
                cnt++;
                cout << v[i] << ' ' << v[j] << '\n';
                visit[{v[i], v[j]}] = true;
            }
        }
    }
    cout << cnt << '\n';
}

// 주어진 수로 만들 수 있는 순서쌍 중 두 수의 합이 n인 모든 경우와 그 수 출력하기

// 정렬은 정렬을 하면 되는데, 중복 처리에 주의