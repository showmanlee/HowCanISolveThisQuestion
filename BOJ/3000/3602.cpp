// iChess
// https://www.acmicpc.net/problem/3602

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    if (a < b) {
        swap(a, b);
    }
    int n = 0;
    while (true) {
        int d = (n + 1) * (n + 1);
        if (a < (d / 2) + (d % 2) || b < d / 2) {
            break;
        }
        n++;
    }
    cout << (n > 0 ? to_string(n) : "Impossible") << '\n';
}

// 주어진 검은색 타일과 흰색 타일로 만들 수 있는 정사각형 체크판의 최대 변 길이 구하기