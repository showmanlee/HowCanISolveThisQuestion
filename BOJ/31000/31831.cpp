// 과민성 대장 증후군
// https://www.acmicpc.net/problem/31831

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int t = 0, res = 0;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        t = max(0, t + p);
        if (t >= m) {
            res++;
        }
    }
    cout << res << '\n';
}

// 0 미만으로 내려가지 않는 어떤 값의 등락폭이 주어질 때, 값이 m 이상이 되는 횟수 구하기