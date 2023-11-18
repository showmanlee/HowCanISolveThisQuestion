// HI-ARC=?
// https://www.acmicpc.net/problem/28444

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int h, i, a, r, c;
    cin >> h >> i >> a >> r >> c;
    cout << (h * i - a * r * c) << '\n';
}

// (h * i) - (a * r * c) 구하기