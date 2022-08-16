// 스네이크버드
// https://www.acmicpc.net/problem/16435

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, l;
    cin >> n >> l;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        if (l >= v[i]) {
            l++;
        } else {
            break;
        }
    }
    cout << l << '\n';
}

// 서로 다른 높이에 걸려있는 과일들을 먹으면 스네이크버드의 길이가 1 늘어나고, 스네이크버드는 자신의 길이보다 낮거나 같은 과일을 먹을 수 있을 떄, 스네이크버드가 과일(들)을 먹어서 늘릴 수 있는 최대 길이 출력하기

// 그리디 - 언제나 가장 낮은 과일부터 먹는 것이 이득
// 따라서 과일들을 정렬한 후, 먹을 수 있는 과일부터 차례로 먹으며 길이를 늘려간다 - 그렇게 먹을 수 없는 과일이 등장하면 그만 먹기
// 과일을 먹을 수 없는 시점에서 길이를 출력합시다