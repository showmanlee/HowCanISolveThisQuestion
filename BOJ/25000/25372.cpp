// 성택이의 은밀한 비밀번호
// https://www.acmicpc.net/problem/25372

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        string s;
        cin >> s;
        bool res = true;
        if (s.length() < 6 || s.length() > 9) {
            res = false;
        }
        cout << (res ? "yes" : "no") << '\n';
    }
}

// 주어진 비밀번호가 6자리 이상 9자리 이하인지 확인하기

// 비밀번호라고 해놓고 대소문자가 주어질 수 있지만, 판별 조건에 자릿수만 있음에 주의
// 그러니까 숫자만 따로 뺄 필요가 없다는 것