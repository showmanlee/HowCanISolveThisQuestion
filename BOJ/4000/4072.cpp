// Words
// https://www.acmicpc.net/problem/4072

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    while (true) {
        getline(cin, s);
        if (s == "#") {
            break;
        }

        vector<string> v;
		stringstream ss(s);
        string t;
		while (ss >> t) {
            reverse(t.begin(), t.end());
            v.push_back(t);
        }
        string res;
        for (int i = 0; i < v.size(); i++) {
            res += v[i];
            if (i != v.size() - 1) {
                res += ' ';
            }
        }
        cout << res << '\n';
    }
}

// 주어진 문자열을 단어 단위로 글자 순서 뒤집기