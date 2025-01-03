// ソーシャルゲーム (Social Game)
// https://www.acmicpc.net/problem/16785

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;
    int cnt = 0, res = 0;
    while (cnt < c) {
        res++;
        cnt += a;
        if (res % 7 == 0) {
            cnt += b;
        }
    }
    cout << res << '\n';
}

// 하루 접속하면 a, 7일 접속하면 추가로 b원을 벌 수 있을 때, c원 벌기 위해 필요한 접속일 구하기