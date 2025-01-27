// An Easy-Peasy Problem
// https://www.acmicpc.net/problem/30214

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    float n, m;
    cin >> n >> m;
    char res = (n >= m / 2 ? 'E' : 'H');
    cout << res << '\n';
}

// n이 m / 2 이상인지 확인하기