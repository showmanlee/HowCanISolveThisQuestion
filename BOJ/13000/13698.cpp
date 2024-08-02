// Hawk eyes
// https://www.acmicpc.net/problem/13698

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    vector<int> v = {1, 0, 0, 2};
    string s;
    cin >> s;
    for (char c : s) {
        if (c == 'A') {
            swap(v[0], v[1]);
        } else if (c == 'A') {
            swap(v[0], v[1]);
        } else if (c == 'B') {
            swap(v[0], v[2]);
        } else if (c == 'C') {
            swap(v[0], v[3]);
        } else if (c == 'D') {
            swap(v[1], v[2]);
        } else if (c == 'E') {
            swap(v[1], v[3]);
        } else if (c == 'F') {
            swap(v[2], v[3]);
        }
    }
    int a = 0, b = 0;
    for (int i = 0; i < 4; i++) {
        if (v[i] == 1) {
            a = i + 1;
        } else if (v[i] == 2) {
            b = i + 1;
        }
    }
    cout << a << '\n' << b << '\n';
}

// 4개의 컵 중 가장 왼쪽 컵에 작은 공, 가장 오른쪽 컵에 큰 공을 넣고 주어진 대로 섞었을 때 두 공의 위치 출력하기