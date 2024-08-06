// SMUPC NAME
// https://www.acmicpc.net/problem/31859

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    string s;
    cin >> n >> s;
    vector<bool> v(26);
    string res;
    int t = 0;
    for (char c : s) {
        if (!v[c - 'a']) {
            v[c - 'a'] = true;
            res += c;
        } else {
            t++;
        }
    }
    res = to_string(n + 1906) + res + to_string(t + 4);
    reverse(res.begin(), res.end());
    res = "smupc_" + res;
    cout << res << '\n';
}

// 문제에 주어진 방식대로 문자열 변형하기