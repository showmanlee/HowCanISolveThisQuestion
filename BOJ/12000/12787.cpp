// 지금 밥이 문제냐
// https://www.acmicpc.net/problem/12787

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        int d;
        cin >> d;
        if (d == 1) {
            string s;
            cin >> s;
            stringstream ss(s);
            unsigned long long p = 256ull * 256 * 256 * 256 * 256 * 256 * 256;
            unsigned long long res = 0;
            for (int i = 0; i < 8; i++) {
                string c;
                getline(ss, c, '.');
                res += stoull(c) * p;
                p /= 256;
            }
            cout << res << '\n';
        } else {
            unsigned long long n;
            cin >> n;
            string s;
            for (int i = 0; i < 8; i++) {
                unsigned long long p = n % 256;
                s = (i == 7 ? "" : ".") + to_string(p) + s;
                n /= 256;
            }
            cout << s << '\n';
        }
    }
}

// iPv8(256씩 8자리) 표현식과 이를 부호 없는 정수 형태로 나타낸 게 주어질 때, 서로 반대로 변환하기

// 전자의 경우 파싱해서 곱해서 만들고, 후자의 경우 256씩 나머지 구해서 문자열로 만든다
// 부호없는 64비트 정수가 필요해 unsigned long long 범위가 필요함에 주의