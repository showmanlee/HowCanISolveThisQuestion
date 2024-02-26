// 사탕
// https://www.acmicpc.net/problem/11256

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        int p, n;
        cin >> p >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            v[i] = a * b;
        }
        sort(v.begin(), v.end(), greater<int>());
        int res = 0;
        for (int i = 0; i < n; i++) {
            p -= v[i];
            res++;
            if (p <= 0) {
                break;
            }
        }
        cout << res << '\n';
    }
}

// 사탕의 개수와 넣을 수 있는 개수가 다른 상자들이 주어질 때, 사탕을 모두 넣기 위해 필요한 상자의 최소 갯수 구하기

// 구합시다 - 상자 넓이 구해서 내림차순으로 정렬 후 계산