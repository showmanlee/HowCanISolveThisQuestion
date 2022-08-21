// FUNGHI
// https://www.acmicpc.net/problem/10643

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    vector<int> v(8);
    for (int i = 0; i < 8; i++) {
        cin >> v[i];
    }
    int res = 0;
    for (int i = 0; i < 8; i++) {
        int p = 0;
        for (int j = 0; j < 4; j++) {
            p += v[(i + j) % 8];
        }
        res = max(res, p);
    }
    cout << res << '\n';
}

// 8조각 피자에 박힌 버섯의 수가 순서대로 주어질 때, 연속된 4조각을 집어 얻을 수 있는 버섯의 최대 개수는?

// 한 바퀴 돌면서 최대 개수를 확인하기 - 브루트포스