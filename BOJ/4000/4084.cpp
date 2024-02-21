// Viva la Diferencia
// https://www.acmicpc.net/problem/4084

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    while (true) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == 0 && b == 0 && c == 0 && d == 0) {
            break;
        }
        int res = 0;
        while (!(a == b && b == c && c == d)) {
            int aa = abs(a - b);
            int bb = abs(b - c);
            int cc = abs(c - d);
            int dd = abs(d - a);
            a = aa;
            b = bb;
            c = cc;
            d = dd;
            res++;
        }
        cout << res << '\n';
    }
}

// 네 정수 a, b, c, d를 각각 |a-b| |b-c| |c-d| |d-a|으로 바꾸는 과정을 반복해 네 정수를 모두 같게 만드는 최소 횟수 구하기

// 직접 돌려봐도 됨 - 네 정수가 2^31보다 작다면 3*31번 안에 수렴하기 때문