// 단체줄넘기
// https://www.acmicpc.net/problem/30457

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n), cnt(1001);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int res = 0;
    for (int i = 0; i < n; i++) {
        cnt[v[i]]++;
        if (cnt[v[i]] <= 2) {
            res++;
        }
    }
    cout << res << '\n';
}

// 단체줄넘기에서 참가자가 보는 방향에 자신보다 작은 사람만 들어가도록 배치할 때, 주어진 인원 중 배치할 수 있는 최대 인원 수 구하기

// 같은 키 인원은 최대 2명까지만 넣을 수 있음 - 서로 등지도록 하여
// 이를 이용해 최대 2명까지만 가져가도록 설정해준다