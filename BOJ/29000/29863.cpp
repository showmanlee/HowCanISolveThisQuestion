// Arno's Sleep Schedule
// https://www.acmicpc.net/problem/29863

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    if (n <= 3) {
        n += 24;
    }
    m += 24;
    cout << (m - n) << '\n';
}

// 20~03시 사이에 자고 05~10시 사이에 일어나는 어린이가 있을 때, 총 몇 시간 자는지 구하기

// 알아서 24시간 변환해서 구해주세요...