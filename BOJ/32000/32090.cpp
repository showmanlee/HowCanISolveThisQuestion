// シンプルなエディタ
// https://www.acmicpc.net/problem/32090

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        string res;
        int idx = 0;
        for (int i = 0; i < n; i++) {
            string com;
            char c;
            cin >> com >> c;
            if (com == "INSERT") {
                if (idx == res.length()) {
                    res += c;
                } else if (idx == 0) {
                    res = c + res;
                } else {
                    res = res.substr(0, idx) + c + res.substr(idx);
                }
                idx++;
            } else if (com == "LEFT") {
                idx = max(0, idx - 1);
            } else if (com == "RIGHT") {
                idx = min((int)res.length(), idx + 1);
            }
        }
        cout << res << '\n';
    }
}

// 문자 입력과 커서 이동 입력이 들어왔을 때 텍스트 입력 결과 출력하기