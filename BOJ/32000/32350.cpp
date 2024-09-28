// 오버킬
// https://www.acmicpc.net/problem/32350

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, d, p;
    cin >> n >> d >> p;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int idx = 0;
    int res = 0;
    while (idx < n) {
        res++;
        v[idx] -= d;
        if (v[idx] <= 0) {
            int t = -v[idx];
            idx++;
            if (idx < n) {
                t = t * p / 100.f;
                v[idx] -= t;
                if (v[idx] <= 0) {
                    idx++;
                }
            }
        }
    }
    cout << res << '\n';
}

// 순서대로 놓인 몬스터 n마리에게 d의 피해를 입한 후 그 몬스터가 죽으면 p%만큼 다음 몬스터에게 피해를 줄 때, 모두 죽이기 위해 필요한 타수 구하기