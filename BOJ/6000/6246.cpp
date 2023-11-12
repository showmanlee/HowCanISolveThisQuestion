// 풍선 놀이
// https://www.acmicpc.net/problem/6246

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<bool> v(n + 1);
    int res = n;
    for (int t = 0; t < q; t++) {
        int l, p;
        cin >> l >> p;
        for (int i = l; i <= n; i += p) {
            if (!v[i]) {
                v[i] = true;
                res--;
            }
        }
    }
    cout << res << '\n';
}

// n칸의 1차원 배열에 l번 칸부터 p칸 간격으로 풍선을 채우는 과정을 q번 진행할 때, 빈 칸의 개수 구하기

// 직접 채워보세요