// Basketball Score
// https://www.acmicpc.net/problem/32306

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    vector<int> v(3);
    for (int i = 1; i <= 2; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[i] = a + (b * 2) + (c * 3);
    }
    cout << (v[1] > v[2] ? 1 : (v[1] < v[2] ? 2 : 0)) << '\n';
}

// 1/2/3점슛 개수가 주어질 때 승리한 팀 구하기