// 카약과 강풍
// https://www.acmicpc.net/problem/2891

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, s, r;
    cin >> n >> s >> r;
    vector<int> v(n + 2, 1);
    for (int i = 0; i < s; i++) {
        int p;
        cin >> p;
        v[p]--;
    }
    for (int i = 0; i < r; i++) {
        int p;
        cin >> p;
        v[p]++;
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] == 0) {
            if (v[i - 1] == 2) {
                v[i - 1]--;
                v[i]++;
            } else if (v[i + 1] == 2) {
                v[i + 1]--;
                v[i]++;
            }
        }
        if (v[i] == 0) {
            res++;
        }
    }
    cout << res << '\n';
}

// 여분으로 카약 하나를 가진 팀은 양옆의 팀 중 하나에게 카약을 줄 수 있을 때, 카약이 없는 팀의 수의 최솟값 구하기

// 한 팀에 카약은 0~2개까지 주어질 수 있음 - 그리고 카약이 0개인 팀은 양쪽에 카약이 2개인 팀에게서 하나를 가져올 수 있음
// 따라서 왼쪽부터 순회하면서 카약이 0개인 팀 옆에 카약이 2개인 팀이 있다면 카약을 전달한다 - 왼쪽부터