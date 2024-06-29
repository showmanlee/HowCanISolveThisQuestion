// 재수강
// https://www.acmicpc.net/problem/31822

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++) {
        string ss;
        cin >> ss;
        if (s.substr(0, 5) == ss.substr(0, 5)) {
            res++;
        }
    }
    cout << res << '\n';
}

// 주어진 과목 코드와 앞 5자리가 같은 코드의 개수 구하기