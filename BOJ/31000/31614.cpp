// 分 (Minutes)
// https://www.acmicpc.net/problem/31614

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int h, m;
    cin >> h >> m;
    cout << (h * 60 + m) << '\n';
}

// h시 m분이 주어질 때, 0시 0분으로부터 몇 분이 지난 건지 출력하기