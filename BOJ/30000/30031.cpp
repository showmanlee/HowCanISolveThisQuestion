// 지폐 세기
// https://www.acmicpc.net/problem/30031

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 136) {
            res += 1000;
        } else if (a == 142) {
            res += 5000;
        } else if (a == 148) {
            res += 10000;
        } else if (a == 154) {
            res += 50000;
        }
    }
    cout << res << '\n';
}

// 지폐의 가로 세로 길이가 주어질 때, 지폐 총액 구하기

// 규격에 맞는 지폐만 주어짐 - 세로는 언제나 68
// 그러니까 가로 길이만 보고 더해주면 된다는 말