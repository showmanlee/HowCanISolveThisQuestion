// 감마선을 맞은 컴퓨터
// https://www.acmicpc.net/problem/30402

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            char c;
            cin >> c;
            if (s.empty()) {
                if (c == 'w') {
                    s = "chunbae";
                } else if (c == 'b') {
                    s = "nabi";
                } else if (c == 'g') {
                    s = "yeongcheol";
                }
            }
        }
    }
    cout << s << '\n';
}

// 알파벳이 적힌 15*15 보드에서 w, b, g 중 어떤 알파벳이 나오는지 확인하기

// 저 셋 중 하나만 나옴이 보장되니 그것만 보면 됨