// Lucky 7
// https://www.acmicpc.net/problem/30224

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int res = 0;
    if (n % 7 == 0) {
        res += 1;
    }
    while (n > 0) {
        if (n % 10 == 7) {
            res += 2;
            break;
        }
        n /= 10;
    }
    cout << res << '\n';
}

// 주어진 수에 7이 있는지, 그리고 7로 나누어떨어지는지 확인하고 출력하기