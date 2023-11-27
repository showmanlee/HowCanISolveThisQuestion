// 카약
// https://www.acmicpc.net/problem/2890

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int r, c;
    cin >> r >> c;
    vector<string> v(r);
    vector<int> res(10);
    for (int i = 0; i < r; i++) {
        cin >> v[i];
    }
    int p = 0;
    bool found = false;
    for (int t = c - 2; t > 0; t--) {
        found = false;
        for (int i = 0; i < r; i++) {
            if (v[i][t] != '.' && res[v[i][t] - '0'] == 0) {
                if (!found) {
                    found = true;
                    p++;
                }
                res[v[i][t] - '0'] = p;
            }
        }
    }
    for (int i = 1; i <= 9; i++) {
        cout << res[i] << '\n';
    }
}

// 문자열로 9대의 카약 위치가 주어질 떄, 각 카약의 등수 출력하기

// 결승선부터 한 칸씩 움직이며 등수를 매겨줍시다