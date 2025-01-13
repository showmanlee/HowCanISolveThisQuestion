// 에디터
// https://www.acmicpc.net/problem/1406

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int n;
    cin >> n;
    stack<char> l, r;
    for (char c : s) {
        l.push(c);
    }
    for (int t = 0; t < n; t++) {
        char w;
        cin >> w;
        if (w == 'L') {
            if (!l.empty()) {
                r.push(l.top());
                l.pop();
            }
        } else if (w == 'D') {
            if (!r.empty()) {
                l.push(r.top());
                r.pop();
            }
        } else if (w == 'B') {
            if (!l.empty()) {
                l.pop();
            }
        } else if (w == 'P') {
            char c;
            cin >> c;
            l.push(c);
        }
    }
    while (!l.empty()) {
        r.push(l.top());
        l.pop();
    }
    while (!r.empty()) {
        cout << r.top();
        r.pop();
    }
    cout << '\n';
}

// 주어진 문자열과 커서 이동/입력/삭제 명령이 주어질 때, 수정한 문자열 출력하기