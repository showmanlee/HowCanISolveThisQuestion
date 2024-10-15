// 승강장의 깊이
// https://www.acmicpc.net/problem/32193

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a += x;
        b += y;
        cout << (a - b) << '\n';
    }
}

// 지표면과 승강장 고도 변화가 주어질 때, 지표면에서 승강장까지의 깊이 구하기