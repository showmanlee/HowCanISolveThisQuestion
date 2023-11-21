// 얼룩말을 찾아라!
// https://www.acmicpc.net/problem/30454

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n, l;
    cin >> n >> l;
    int res = 0, cnt = 0;
    for (int t = 0; t < n; t++) {
        char prev = '0';
        int p = 0;
        for (int i = 0; i < l; i++) {
            char c;
            cin >> c;
            if (prev == '0' && c == '1') {
                p++;
            }
            prev = c;
        }
        if (p > res) {
            res = p;
            cnt = 1;
        } else if (p == res) {
            cnt++;
        }
    }
    cout << res << ' ' << cnt << '\n';
}

// 얼룩말의 줄무늬 패턴이 주어질 때, 가장 많은 줄을 가진 얼룩말의 줄의 개수와 같은 줄을 가진 얼룩말 개수 출력하기

// 문자들을 받으며 이전 문자가 0이고 현재 문자가 1이라면 줄 개수 추가하기