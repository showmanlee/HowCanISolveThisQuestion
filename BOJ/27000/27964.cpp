// 콰트로치즈피자
// https://www.acmicpc.net/problem/27964

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    map<string, bool> v;
    int res = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s.length() >= 6 && s.substr(s.length() - 6) == "Cheese" && !v[s]) {
            v[s] = true;
            res++;
        }
    }
    cout << (res >= 4 ? "yummy" : "sad") << '\n';
}

// 주어진 문자열들에서 끝이 Cheese로 끝나는 문자열이 4종류 이상 나오는지 확인하기

// map으로 확인해봅시다