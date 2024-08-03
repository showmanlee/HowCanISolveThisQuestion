// Haughty Cuisine
// https://www.acmicpc.net/problem/20336

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<string>> v(n);
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        for (int j = 0; j < p; j++) {
            string s;
            cin >> s;
            v[i].push_back(s);
        }
    }
    cout << v[0].size() << '\n';
    for (string s : v[0]) {
        cout << s << '\n';
    }
}

// 문자열 묶음 n개가 주어질 때, 그 중 하나를 아무 거나 골라 개수와 함께 모두 출력하기